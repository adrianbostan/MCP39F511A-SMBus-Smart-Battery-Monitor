#include <Wire.h>


#define SPECIFICATION               3 //packed specification number and scaling information
#define SERIAL_NUMBER               6699
#define IMPORTING_ENERGY            1
#define EXPORTING_ENERGY            0


#define BATTERY_MIN_CELL_VOLTAGE           3.6
#define BATTERY_MAX_CELL_VOLTAGE           4.2
#define BATTERY_CELL_NR                    3
#define BATTERY_NOMINAL_VOLTAGE             11.1
#define BATTERY_FULL_CHARGE_VOLTAGE        (BATTERY_CELL_NR * BATTERY_MAX_CELL_VOLTAGE)
#define BATTERY_FULL_DISCHARGE_VOLTAGE     (BATTERY_CELL_NR * BATTERY_MIN_CELL_VOLTAGE)
#define BATTERY_DESIGN_CAPACITY            2200
#define BATTERY_CHARGED                    1
#define BATTERY_DISCHARGED                 2
#define BATTERY_CALIBRATION                3 
#define BATTERY_NORMAL_OPERATION           4
#define F511A_CNT_ERASE_ENABLE             0
#define F511A_CNT_ERASE_DISABLE            1

byte register_to_call = 0;
int16_t  current = 32000;                                           //charge/discharge rate in mA increments - positive for charge, negative for discharge, 0 to 32,767 mA for charge or 0 to -32,768 mA for discharge
uint16_t remaining_capacity =0;                                 //remaining charge in mAh or 10mWh
uint16_t temperature = 0;                                         //cell temperature in tenth degree Kelvin increments, 0 to +6553.5°K
uint16_t overall_voltage = 0;                                  //battery terminal voltage in milli-volts, 0 to 65,535 mV
uint16_t cell_voltage[6] = {0, 0, 0, 0, 0, 0};  //battery cell voltage in milli-volts, 0 to 65,535 mV
uint16_t actual_full_charge_capacity = 0;                            //estimated full charge capacity in mAh or 10mWh

uint16_t cycle_count = 67;
uint16_t active_power = 0;

uint16_t battery_SOC = 0;
uint8_t battery_status = BATTERY_CALIBRATION;

char rxBuffer[47];
byte F511A_read_44_bytes[8]           = {0xA5, 0x08, 0x41, 0x00, 0x02, 0x4E, 0x2C, 0x6A};
byte F511A_disable_reset_counters[12] = {0xA5, 0x0C, 0x41, 0x00, 0x94, 0x4D, 0x04, 0x00, 0x00, 0x00, 0x03, 0xDA};
byte F511A_enable_counters[12]        = {0xA5, 0x0C, 0x41, 0x00, 0x94, 0x4D, 0x04, 0x01, 0x00, 0x00, 0x03, 0xDB};

uint32_t F511A_current = 0;
uint16_t F511A_status = 0;
uint64_t F511A_Active_Energy_Import = 0;
uint64_t F511A_Active_Energy_Export = 0;


uint8_t F511A_voltage_sign;
uint8_t F511A_current_sign;
uint8_t F511A_active_power_sign;
uint8_t F511A_eng_cnt_erase = F511A_CNT_ERASE_ENABLE;


const unsigned int Temperature            = 0;           // cmd 08   r     - °C
      unsigned int Voltage                = 0;           // cmd 09   r     - mV
        signed int Current                = 0;           // cmd 0A   r     - mA
        signed int AverageCurrent         = 0;           // cmd 0B   r     - avg current for 60 sec
      unsigned int RelativeStateOfCharge  = 0;           // cmd 0D   r     - %
      unsigned int AbsoluteStateOfCharge  = 0;           // cmd 0E   r     - %
      unsigned int RemainingCapacity      = 0;           // cmd 0F   r     - mAh
      unsigned int FullChargeCapacity     = 0;           // cmd 10   r     - mAh
      unsigned int RunTimeToEmpty         = 0;           // cmd 11   r     - min
      unsigned int AverageTimeToEmpty     = 0;           // cmd 12   r     - min
      unsigned int AverageTimeToFull      = 0;           // cmd 13   r     - min
const unsigned int ChargingCurrent        = 4000;        // cmd 14   r     - mA
const unsigned int ChargingVoltage        = 4200;        // cmd 15   r     - nCell * 4200mV
      unsigned int BatteryStatus          = 0;           // cmd 16   r     - status
      unsigned int CycleCount             = 10;          // cmd 17   r     - #
const unsigned int DesignCapacity         = 9000;        // cmd 18   r     - mAh
const unsigned int DesignVoltage          = 11100;       // cmd 19   r     - nCell * 3700mV
const unsigned int SpecificationInfo      = 0x0021;      // cmd 1A   r     - user
const unsigned int SerialNumber           = 12345;       // cmd 1C   r     - #

void requestEvent(void){
  switch (register_to_call) {
    case 0x0A: //current request
      Wire.write(lowByte(current));
      Wire.write(highByte(current));
      break;
    case 0x0F: //remaining capacity request
      Wire.write(lowByte(remaining_capacity));
      Wire.write(highByte(remaining_capacity));
      break;
    case 0x08: //temperature request
      Wire.write(lowByte(temperature));
      Wire.write(highByte(temperature));
      break;
    case 0x09: //overall voltage request
      Wire.write(lowByte(overall_voltage));
      Wire.write(highByte(overall_voltage));
      break;
    case 0x3f: //cell 1 voltage request
      Wire.write(lowByte(cell_voltage[0]));
      Wire.write(highByte(cell_voltage[0]));
      break;
    case 0x3e: //cell 2 voltage request
      Wire.write(lowByte(cell_voltage[1]));
      Wire.write(highByte(cell_voltage[1]));
      break;
    case 0x3d: //cell 3 voltage request
      Wire.write(lowByte(cell_voltage[2]));
      Wire.write(highByte(cell_voltage[2]));
      break;
    case 0x3c: //cell 4 voltage request
      Wire.write(lowByte(cell_voltage[3]));
      Wire.write(highByte(cell_voltage[3]));
      break;
    case 0x3b: //cell 5 voltage request
      Wire.write(lowByte(cell_voltage[4]));
      Wire.write(highByte(cell_voltage[4]));
      break;
    case 0x3a: //cell 6 voltage request
      Wire.write(lowByte(cell_voltage[5]));
      Wire.write(highByte(cell_voltage[5]));
      break;
    case 0x1a: //specification_Info
      Wire.write(lowByte(SPECIFICATION));
      Wire.write(highByte(SPECIFICATION));
      break;
    case 0x10: //full charge capacity
      Wire.write(lowByte(actual_full_charge_capacity));
      Wire.write(highByte(actual_full_charge_capacity));
      break;
    case 0x1c: //serial number
      Wire.write(lowByte(SERIAL_NUMBER));
      Wire.write(highByte(SERIAL_NUMBER));
      break;
    case 0x16: //serial status
      Wire.write(lowByte(battery_status));
      Wire.write(highByte(battery_status));
      break;   
    case 0x17: //cycle count
      Wire.write(lowByte(cycle_count));
      Wire.write(highByte(cycle_count));
      break;   
    case 0x24: //active power
      Wire.write(lowByte(active_power));
      Wire.write(highByte(active_power));
      break;   
 

  }

}

void recieveEvent(int Anzahl)
{
  while (Wire.available())
  {
    register_to_call = Wire.read();
  }
 
}

void setup() 
{
  Wire.begin(0x0B);
  Wire.onReceive(recieveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(115200);
  Serial2.begin(115200);
 
    
}

void update_battery_status()
{
  if(overall_voltage >= BATTERY_FULL_CHARGE_VOLTAGE & (current <= 100 & current > 0))
    battery_status = BATTERY_CHARGED;
}

//asume battery fully discharged
void battery_calibration_cycle()
{
  if(battery_status == BATTERY_CALIBRATION)
  {         
        if(F511A_active_power_sign == IMPORTING_ENERGY & F511A_eng_cnt_erase == F511A_CNT_ERASE_ENABLE)
        {
          Serial2.write(F511A_disable_reset_counters, sizeof(F511A_disable_reset_counters));
          delay(100);
          Serial2.write(F511A_enable_counters, sizeof(F511A_enable_counters));
          F511A_eng_cnt_erase = F511A_CNT_ERASE_DISABLE;
        }              
  }

  if(battery_status == BATTERY_CHARGED)
  {
    actual_full_charge_capacity = (uint16_t)((F511A_Active_Energy_Import * 1000)/BATTERY_NOMINAL_VOLTAGE);
    
  }

  
}
//uint32_t mem_DEVICE_ID          @ 0x00802000;//0x00

void loop()
{  

    
    //battery_calibration_cycle();
    //update_battery_status();
 
  
    Serial2.write(F511A_read_44_bytes, sizeof(F511A_read_44_bytes));
    
    Serial2.readBytes(rxBuffer, 47);
    delay(500);
 
    overall_voltage = ((rxBuffer[7]&0xFF)<<8 | (rxBuffer[6]&0xFF))*10;
    
    temperature = ((rxBuffer[11]&0xFF)<<8 | (rxBuffer[10]&0xff));//formula to celsius
    
    F511A_current = ((rxBuffer[17]&0xFF)<<24 | (rxBuffer[16]&0xFF)<<16 | (rxBuffer[15]&0xFF)<<8 | (rxBuffer[14]&0xFF));
    
    F511A_status = ((rxBuffer[3]&0xFF)<<8 | (rxBuffer[2]&0xff));
    F511A_voltage_sign      = ((F511A_status & (0x0001 << 13)) >> 13);
    F511A_current_sign      = ((F511A_status & (0x0001 << 14)) >> 14);
    F511A_active_power_sign = ((F511A_status & (0x0001 << 4)) >> 4);

    if(F511A_current_sign==1)
      current=-(int16_t)F511A_current/10;
      else
        current=(int16_t)F511A_current/10;



            
     

    Serial.println(temperature);
 
    
 }
