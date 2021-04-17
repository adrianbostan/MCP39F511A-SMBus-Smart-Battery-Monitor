# MCP39F521-SMBUS-Battery-Monitor

This is a smart battery monitor based on Microchip 24-Bit Single Phase AC/DC Power Monitoring IC-**MCP39F521**.
It is intended to be used in systems with **SMBUS** communication like **DJI** smart batteries, **Ardupilot** systems and any other system that need a smart battery.
The system can provide the standar smart battery commands:


## MCP39F521 Features

The **MCP39F521** is a highly integrated, single-phase power-monitoring IC designed for real-time measurement of input power for AC/DC power supplies, providing power and energy values. It includes dual-channel delta sigma ADCs, a 16-bit calculation engine, EEPROM and a flexible 2-wire interface. An integrated low-drift voltage reference in addition to the 94.5 dB of SINAD performance on each measurement channel allows for better than 0.1% accurate designs across a 4000:1 dynamic range.

***Additional Features***

-   Power Monitoring Accuracy capable of 0.1% error across 4000:1 dynamic range
-   Built-In Calculations on Fast 16-Bit Processing Core
    -   Active, Reactive, Apparent Power
    -   Active and Reactive Energy Accumulation
    -   True RMS Current, RMS Voltage
    -   Line Frequency, Power Factor
-   Dedicated Zero Crossing Detection (ZCD) Pin
-   Dedicated PWM Output Pin
-   Automatic Event Pin Control through Fast Voltage Surge Detection
-   Fast Calibration Routines
-   I2C Interface
-   512 bytes User-accessible EEPROM through page read/write commands
-   Non-volatile On-chip Memory, no external memory required
-   Low-Drift Internal Voltage Reference: 10 ppm/°C typical
-   28-lead 5x5 QFN package
-   Extended Temperature Range -40°C to +125°C
-   AEC-Q100 Grade 1

## Applications

   It is intended to be used in systems with SMBUS communication like DJI smart batteries, ardupilot systems and any other system that need a smart battery.
The system can provide the standard smart battery commands:

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
    const unsigned int SerialNumber           = 12345;                        // cmd 1C   r     - #
