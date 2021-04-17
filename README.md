# MCP39F521-SMBUS-Battery-Monitor
This is a smart battery monitor based on Microchip 24-Bit Single Phase AC/DC Power Monitoring IC-MCP39F521.
It is intended to be used in systems with SMBUS communication like DJI smart batteries, ardupilot systems and any other system that need a smart battery.
The system can provide the standar smart battery commands:

const unsigned int Temperature            = (25+273.5)*10;                // cmd 08   r     - 10*°K
      unsigned int Voltage                = 0;                            // cmd 09   r     - mV
        signed int Current                = 0;                            // cmd 0A   r     - mA
        signed int AverageCurrent         = 0;                            // cmd 0B   r     - 1 minute average current
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

