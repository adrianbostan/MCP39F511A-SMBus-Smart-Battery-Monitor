
#include <Wire.h>


// ManufactureDate data type is a bitfield
//
struct Date_t
{
  unsigned day:5;
  unsigned month:4;
  unsigned year:7;
};


// Standard Smart Battery command
//
      unsigned int ManufactureAccess      = 0x0100;                       // cmd 00   r/w   - bitfield
      unsigned int RemainingCapacityAlarm = 0;                            // cmd 01   r/w   - mAh
      unsigned int RemainingTimeAlarm     = 0;                            // cmd 02   r/w   - min
      unsigned int BatteryMode            = 0x0080;                       // cmd 03   r/w   - bitfield
        signed int AtRate                 = 0;                            // cmd 04   r/w   - mA
      unsigned int AtRateTimeToFull       = 0xFFFF;                       // cmd 05   r     - min
      unsigned int AtRateTimeToEmpty      = 0xFFFF;                       // cmd 06   r     - min
      unsigned int AtRateOK               = 0x0001;                       // cmd 07   r     - boolean
const unsigned int Temperature            = (25+273.5)*10;                // cmd 08   r     - 10*°K
      unsigned int Voltage                = 0;                            // cmd 09   r     - mV
        signed int Current                = 0;                            // cmd 0A   r     - mA
        signed int AverageCurrent         = 0;                            // cmd 0B   r     - 1 minute average current
const unsigned int MaxError               = 10;                           // cmd 0C   r     - %
      unsigned int RelativeStateOfCharge  = 0;                            // cmd 0D   r     - %
      unsigned int AbsoluteStateOfCharge  = 0;                            // cmd 0E   r     - %
      unsigned int RemainingCapacity      = 0;                            // cmd 0F   r     - mAh
      unsigned int FullChargeCapacity     = 0;                            // cmd 10   r     - mAh
      unsigned int RunTimeToEmpty         = 0;                            // cmd 11   r     - min
      unsigned int AverageTimeToEmpty     = 0;                            // cmd 12   r     - min
      unsigned int AverageTimeToFull      = 0;                            // cmd 13   r     - min
const unsigned int ChargingCurrent        = 2000;                         // cmd 14   r     - mA
const unsigned int ChargingVoltage        = 12600;                        // cmd 15   r     - nCell * 4200mV
      unsigned int BatteryStatus          = 0;                            // cmd 16   r     - bitfielf
      unsigned int CycleCount             = 10;                           // cmd 17   r     - #
const unsigned int DesignCapacity         = 4400;                         // cmd 18   r     - mAh
const unsigned int DesignVoltage          = 11100;                        // cmd 19   r     - nCell * 3700mV
const unsigned int SpecificationInfo      = 0x0021;                       // cmd 1A   r     - bitfield
const Date_t       ManufactureDate        = { 29,3,2019-1980 };           // cmd 1B   r     - bitfield
const unsigned int SerialNumber           = 12345;                        // cmd 1C   r     - #
const char         ManufacturerName[]     = { "\x07""SAM-HSW" };          // cmd 20   r     - first byte is the text length
const char         DeviceName[]           = { "\x0D""DELL RM6618AR" };    // cmd 21   r     - first byte is the text length
const char         DeviceChemistry[]      = { "\x04""LION" };             // cmd 22   r     - first byte is the text length
const char         ManufacturerData[]     = { "\x0C""123456789012" };     // cmd 23   r     - first byte is the data length
      unsigned int OptionalMfgFunction5   = 0;                            // cmd 2F   r/w
      unsigned int OptionalMfgFunction4   = 0;                            // cmd 3C   r/w
      unsigned int OptionalMfgFunction3   = 4200;                         // cmd 3D   r/w   - mV  battery 3 voltage
      unsigned int OptionalMfgFunction2   = 4200;                         // cmd 3E   r/w   - mV  battery 2 voltage
      unsigned int OptionalMfgFunction1   = 4200;                         // cmd 3F   r/w   - mV  battery 1 voltage


// DELL specific Smart Battery command
//
      unsigned int w_cmd00                = 0;                            // cmd 00   r/w   - ManufacturerAccess received data
      unsigned int w_cmd2E                = 0;                            // cmd 2E   r/w   - Addressable parameter
      unsigned long w_cmd36               = 0;                            // cmd 36   r/w   - Challenge/Response for authentication


// DELL specific value for command received in ManufacturerAccess 0x00
//
#define MA_DeviceType                 0x0001      //  Returns IC name such as SH79F329 (35E1)
#define MA_SoftwareRev                0x0002      //  Returns the software version number
#define MA_Sleep                      0x0005      //  System enters low power mode
#define MA_Reset                      0x0041      //  System reset
#define MA_Seal                       0x062b      //  The Flash parameters are sealed, and the Dataflash cannot be read or written before decryption


//
// Bit definition for BatteryMode (0x03)
//
#define BM_CAPACITY_MODE              0x8000 
#define BM_CHARGER_MODE               0x4000 
#define BM_ALARM_MODE                 0x2000 
//                                    0x1000 Reserved
//                                    0x0800 Reserved
//                                    0x0400 Reserved
#define BM_PRIMARY_BATTERY            0x0200 
#define BM_CHARGE_CONTROLLER_ENABLED  0x0100 
#define BM_CONDITION_FLAG             0x0080 
//                                    0x0040 Reserved
//                                    0x0020 Reserved
//                                    0x0010 Reserved
//                                    0x0008 Reserved
//                                    0x0004 Reserved
#define BM_PRIMARY_BATTERY_SUPPORT    0x0002 
#define BM_INTERNAL_CHARGE_CONTROLLER 0x0001 

//
// Bit definition for BatteryStatus (0x1C)
//
#define BS_OVER_CHARGED_ALARM         0x8000 
#define BS_TERMINATE_CHARGE_ALARM     0x4000 
//                                    0x2000 Reserved
#define BS_OVER_TEMP_ALARM            0x1000 
#define BS_TERMINATE_DISCHARGE_ALARM  0x0800 
//                                    0x0400 Reserved
#define BS_REMAINING_CAPACITY_ALARM   0x0200 
#define BS_REMAINING_TIME_ALARM       0x0100 
#define BS_INITIALIZED                0x0080 
#define BS_DISCHARGING                0x0040 
#define BS_FULLY_CHARGED              0x0020 
#define BS_FULLY_DISCHARGED           0x0010 
#define BS_ERRORS_BITS                0x000F 


// DELL specific - Challenge/Answer command 0x36
// unknow cipher method, for now use a table of known answer
// yes, it is a drop into the sea, but on my DELL E5400 "in" parameter change only when connect AC adapter to PC in power off state
//
unsigned long*  ChallengeAnswer0x36 ( unsigned long in )
{
  static struct ca { unsigned long in,out; }  tab[]=
  {
    { 0x5D8BAFC1,0xACE8E95E },
    { 0xB7EC42FF,0xA3150150 },
    { 0x20ECC219,0x54CE5425 },
    { 0xE3147497,0x5E31DF8B },
    { 0x4151B8CC,0x504BC161 },
  };
  struct ca *p;
  for( p=tab ; p<tab+sizeof( tab )/sizeof( *tab ) ; p++ )
    if( in==p->in )
      return &p->out;
  p--;
  return &p->out;
}


// Fuel Gauge engine
//
struct FuelGaugeCtrl
{
// AN0 connected to VBAT with a resistor partition 220k/100k
//
  unsigned  ReadVoltage ( void )
  {
    static unsigned last_1=0,last_2=0,last_3=0;
    unsigned mV=(long)analogRead( 0 )*322L*5005L/100L/1024L;
    unsigned r=(mV+last_1+last_2+last_3)>>2;                // medium of last 4 measures
    last_3=last_2;
    last_2=last_1;
    last_1=mV;
    return r;
  }

// AN1 connected to ACS712-20 output.  out: 2V at 20A
//
  int   ReadCurrent ( void )
  {
    static int last_1=0,last_2=0,last_3=0;
    int mA=-((long)analogRead( 1 )-512L)*25000L/512L;
    int r=(mA+last_1+last_2+last_3)>>2;                // medium of last 4 measures
    last_3=last_2;
    last_2=last_1;
    last_1=mA;
    return r;
  }

#define  LOOPINTERVAL           100L  // msec Fuel Gauge Loop period

  unsigned long lastupdate;           // msec
           long ActualCapacityLong;   // 10*mAs
  unsigned long DesignCapacityLong;   // 10*mAs
  unsigned int  BatteryEmptyVoltage;  // mV
  unsigned      LastBS;               // BatteryStatus at previous Loop

  unsigned VoltageToCapacity ( void )
  {
    int c = (long)FullChargeCapacity*(Voltage-BatteryEmptyVoltage)/(ChargingVoltage-BatteryEmptyVoltage);
    if( Current>0 )         c -= Current;
    else                    c -= Current>>2;
    if( c>FullChargeCapacity )
      return FullChargeCapacity;
    if( c<0 )      
      return 0;
    return c;
  }

  void  Setup ( void )
  {
    for( int i=0 ; i<4 ; i++ )
    {
      Voltage=ReadVoltage();
      Current=ReadCurrent();
    }
    
    BatteryEmptyVoltage = DesignVoltage*34L/37L;
    FullChargeCapacity  = DesignCapacity;
    DesignCapacityLong  = (3600000L/LOOPINTERVAL)*DesignCapacity;
    ActualCapacityLong  = (3600000L/LOOPINTERVAL)*VoltageToCapacity();
    
    lastupdate = millis()-LOOPINTERVAL-1;
    Loop();
  }
  
  void  Loop  ( void )
  {
    if( millis()-lastupdate<LOOPINTERVAL )
      return;
    lastupdate += LOOPINTERVAL;

             int  C     = ReadCurrent();
    unsigned int  V     = ReadVoltage();
    unsigned long VTCL  = 10L*(3600000L/LOOPINTERVAL)*VoltageToCapacity();            // VTCL premultiply by 10

    if( C<0 && VTCL/8L<ActualCapacityLong )           ActualCapacityLong = VTCL/8;    // VTCL used in range +/- 20%
    else if( C>0 && VTCL/12L>ActualCapacityLong )     ActualCapacityLong = VTCL/12;   //
    else                                              ActualCapacityLong+= C;
    if( ActualCapacityLong<0 )                        ActualCapacityLong = 0;
    if( ActualCapacityLong>DesignCapacityLong )       ActualCapacityLong = DesignCapacityLong;

    unsigned  FCC   = FullChargeCapacity;
    unsigned  RC    = ActualCapacityLong/(3600000L/LOOPINTERVAL);
    unsigned  RTTE  = C>=0 ? 0 : ( 60L*RC/-C );
    unsigned  RSOC  = 100L*RC/FCC;
    unsigned  ASOC  = 100L*RC/DesignCapacity;
    unsigned  CC    = CycleCount;

    unsigned  BS    =( V>=ChargingVoltage && C<(DesignCapacity>>5)  ? BS_TERMINATE_CHARGE_ALARM   |BS_FULLY_CHARGED     : 0 ) |
                     ( V<=BatteryEmptyVoltage                       ? BS_TERMINATE_DISCHARGE_ALARM|BS_FULLY_DISCHARGED  : 0 ) |
//                     ( RSOC<10                                      ? BS_FULLY_DISCHARGED           : 0 ) |
//                     ( RSOC>90                                      ? BS_FULLY_CHARGED              : 0 ) |
                     ( RC<RemainingCapacityAlarm                    ? BS_REMAINING_CAPACITY_ALARM   : 0 ) |
                     ( RTTE<RemainingTimeAlarm                      ? BS_REMAINING_TIME_ALARM       : 0 ) |
                     ( C<50                                         ? BS_DISCHARGING                : 0 ) |
                     ( BS_INITIALIZED );
                   
    unsigned BSchanged = BS^LastBS;
    if( BSchanged&BS&BS_TERMINATE_CHARGE_ALARM )      FCC = RC;
    if( BSchanged&BS&BS_TERMINATE_DISCHARGE_ALARM )   RC = 0;
    if( BSchanged&BS&BS_DISCHARGING )                 CC++; 
    LastBS = BS;
    
    noInterrupts();
    Current               = C;
    Voltage               = V;
    RemainingCapacity     = RC;
    RunTimeToEmpty        = RTTE;
    RelativeStateOfCharge = RSOC;
    AbsoluteStateOfCharge = ASOC;
    FullChargeCapacity    = FCC;
    CycleCount            = CC;
    BatteryStatus         = BS;
    interrupts();
  }
};


struct FuelGaugeCtrl  FuelGauge;
byte  command=0;


// Answers to the read command
//
void sendAnswer ( byte command )
{
  static unsigned int zero=0;
  switch( command )
  {
    case 0x00: Wire.write((byte*)&ManufactureAccess, 2); break;
    case 0x01: Wire.write((byte*)&RemainingCapacityAlarm, 2); break;
    case 0x02: Wire.write((byte*)&RemainingTimeAlarm, 2);break;
    case 0x03: Wire.write((byte*)&BatteryMode, 2);break;
    case 0x04: Wire.write((byte*)&AtRate, 2);break;
    case 0x05: Wire.write((byte*)&AtRateTimeToFull, 2);break;
    case 0x06: Wire.write((byte*)&AtRateTimeToEmpty, 2);break;
    case 0x07: Wire.write((byte*)&AtRateOK, 2);break;
    case 0x08: Wire.write((byte*)&Temperature, 2);break;
    case 0x09: Wire.write((byte*)&Voltage, 2);break;
    case 0x0a: Wire.write((byte*)&Current, 2);break;
    case 0x0b: Wire.write((byte*)&AverageCurrent, 2);break;
    case 0x0c: Wire.write((byte*)&MaxError, 2);break;
    case 0x0d: Wire.write((byte*)&RelativeStateOfCharge, 2);break;
    case 0x0e: Wire.write((byte*)&AbsoluteStateOfCharge, 2);break;
    case 0x0f: Wire.write((byte*)&RemainingCapacity, 2);break;
    case 0x10: Wire.write((byte*)&FullChargeCapacity, 2);break;
    case 0x11: Wire.write((byte*)&RunTimeToEmpty, 2);break;
    case 0x12: Wire.write((byte*)&AverageTimeToEmpty, 2);break;
    case 0x13: Wire.write((byte*)&AverageTimeToFull, 2);break;
    case 0x14: Wire.write((byte*)( BatteryStatus&(BS_OVER_CHARGED_ALARM|BS_TERMINATE_CHARGE_ALARM) ? &zero : &ChargingCurrent ), 2); break;
    case 0x15: Wire.write((byte*)( BatteryStatus&(BS_OVER_CHARGED_ALARM|BS_TERMINATE_CHARGE_ALARM) ? &zero : &ChargingVoltage ), 2); break;
    case 0x16: Wire.write((byte*)&BatteryStatus, 2);break;
    case 0x17: Wire.write((byte*)&CycleCount, 2);break;
    case 0x18: Wire.write((byte*)&DesignCapacity, 2);break;
    case 0x19: Wire.write((byte*)&DesignVoltage, 2);break;
    case 0x1a: Wire.write((byte*)&SpecificationInfo, 2);break;
    case 0x1b: Wire.write((byte*)&ManufactureDate, 2);break;
    case 0x1c: Wire.write((byte*)&SerialNumber, 2);break;
    case 0x20: Wire.write((byte*)ManufacturerName,  strlen(ManufacturerName));break;
    case 0x21: Wire.write((byte*)DeviceName,        strlen(DeviceName));break;
    case 0x22: Wire.write((byte*)DeviceChemistry,   strlen(DeviceChemistry));break;
    case 0x23: Wire.write((byte*)ManufacturerData,  strlen(ManufacturerData));break;
    case 0x2F: Wire.write((byte*)OptionalMfgFunction5, 2);break;
    case 0x3C: Wire.write((byte*)OptionalMfgFunction4, 2);break;
    case 0x3D: Wire.write((byte*)OptionalMfgFunction3, 2);break;
    case 0x3E: Wire.write((byte*)OptionalMfgFunction2, 2);break;
    case 0x3F: Wire.write((byte*)OptionalMfgFunction1, 2);break;

// DELL specif commands
    case 0x2e: sendAnswer( w_cmd2E>>8 ); break;                      
    case 0x36: Wire.write( 4 ); Wire.write( (byte*)ChallengeAnswer0x36( w_cmd36 ), 4 ); break;
    
    default:   Wire.write(0); Wire.write(0); break;
  }
}


// called after received a write command from host
//
void receiveEvent ( int numOfBytes )
{
  command = Wire.read();
  switch( command )
  {
  case 0x00:    // DELL specific ManufacturerAccess
    w_cmd2E=0;
    if( numOfBytes>=2 )
    {
      ((byte*)&w_cmd00)[0]=Wire.read();
      ((byte*)&w_cmd00)[1]=Wire.read();
      switch( w_cmd00 )
      {
      case MA_DeviceType:   ManufactureAccess=0x8CA0;  break;
      case MA_SoftwareRev:  ManufactureAccess=0x1961;  break;
      case 0:
      case MA_Sleep:
      case MA_Reset:
      case MA_Seal:         ManufactureAccess=0x0100;  break;
      default:              ManufactureAccess=w_cmd00; break;
      }
    }
     break;
  case 0x2E:    // DELL specific Addressable parameter
    if( numOfBytes>=2 )
    {
      ((byte*)&w_cmd2E)[0]=Wire.read();
      ((byte*)&w_cmd2E)[1]=Wire.read();
    }
    break;
  case 0x36:    // DELL specific Challenge/Answer
    if( numOfBytes>=5 )
    {
      byte size=Wire.read();
      ((byte*)&w_cmd36)[0]=Wire.read();
      ((byte*)&w_cmd36)[1]=Wire.read();
      ((byte*)&w_cmd36)[2]=Wire.read();
      ((byte*)&w_cmd36)[3]=Wire.read();
      if( size!=4 )
        w_cmd36=0;
    }
    break;
    
  case 0x01:    // RemainCapacityAlarm
    if( numOfBytes>=2 )
    {
      ((byte*)&RemainingCapacityAlarm)[0]=Wire.read();
      ((byte*)&RemainingCapacityAlarm)[1]=Wire.read();
    }
    break;
  case 0x02:    // RemainingTimeAlarm
    if( numOfBytes>=2 )
    {
      ((byte*)&RemainingTimeAlarm)[0]=Wire.read();
      ((byte*)&RemainingTimeAlarm)[1]=Wire.read();
    }
    break;
  case 0x04:    // AtRate
    if( numOfBytes>=2 )
    {
      ((byte*)&AtRate)[0]=Wire.read();
      ((byte*)&AtRate)[1]=Wire.read();
      AtRateTimeToEmpty =-1;
      AtRateTimeToFull  =-1;
      if( AtRate>0 )
        AtRateTimeToFull = 60L*(FullChargeCapacity-RemainingCapacity)/AtRate;
      else if( AtRate<0 )
        AtRateTimeToEmpty= 60L*RemainingCapacity/-AtRate;
    }
    break;
  }
}


// called after received a read command from host
//
void requestEvent ( void )
{
  digitalWrite( 13, !digitalRead( 13 ) );   // for debug
  sendAnswer( command );
}


bool  displayStatus=false;

// called after input from serial line
//
void serialEvent  ( void )
{
  displayStatus = true;
  while( Serial.available() ) 
    Serial.read();
}

void setup()
{
  pinMode( 13, OUTPUT ); /**/

  Wire.begin(0x0B);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  Serial.begin(115200);
  Serial.println( "Ready" );

  FuelGauge.Setup();

  displayStatus = true;
}

void loop()
{
  FuelGauge.Loop();
  if( !displayStatus )
    return;
  Serial.print( "Current                =" ); Serial.println( Current );
  Serial.print( "Voltage                =" ); Serial.println( Voltage );
  Serial.print( "VoltageToCapacity      =" ); Serial.println( FuelGauge.VoltageToCapacity() );
  Serial.print( "ActualCapacityLong     =" ); Serial.println( FuelGauge.ActualCapacityLong );
  Serial.print( "RemainingCapacity      =" ); Serial.println( RemainingCapacity );
  Serial.print( "RunTimeToEmpty         =" ); Serial.println( RunTimeToEmpty );
  Serial.print( "RelativeStateOfCharge  =" ); Serial.println( RelativeStateOfCharge );
  Serial.print( "AbsoluteStateOfCharge  =" ); Serial.println( AbsoluteStateOfCharge );
  Serial.print( "FullChargeCapacity     =" ); Serial.println( FullChargeCapacity );
  Serial.print( "BatteryStatus          =" ); Serial.println( BatteryStatus,HEX );
  Serial.print( "w_cmd36                =" ); Serial.println( w_cmd36,HEX );
  Serial.print( "ChallengeAnswer0x36    =" ); Serial.println( *ChallengeAnswer0x36( w_cmd36 ),HEX );
  Serial.println();
  displayStatus=false;
}
