# MCP39F511A-SMBUS-Battery-Monitor

This is a smart battery monitor based on Microchip 24-Bit Single Phase AC/DC Power Monitoring IC-**MCP39F511A**.



## MCP39F511A Features


The **MCP39F511A** device is a highly-integrated, complete single-phase power-monitoring IC designed for real-time measurement of input power for AC and DC power supplies, making it suitable for a wide range of consumer and industrial applications. It is capable of detecting the input voltage types in order to select DC or AC mode automatically. It includes dual-channel Delta-Sigma ADCs, a 16-bit calculation engine, EEPROM and a flexible 2-wire interface. Separate AC and DC calibration registers are provided, to ensure high-accuracy measurements in both modes. An integrated low-drift voltage reference with 7 ppm/°C in addition to 94.5 dB of SINAD performance on each measurement channel allows for better than 0.1% accurate designs across a 4000:1 dynamic range.

Additional Features

-   Real-Time Measurement of Input Power for AC or DC Supplies
-   Power Monitoring Accuracy capable of 0.1% error across 4000:1 dynamic range
-   Automatic Sensing and Switching Between AC and DC Modes
-   Built-In Calculations:

-   Active, Reactive, Apparent Power
-   Active and Reactive Energy Accumulation
-   True RMS Current, RMS Voltage
-   Line Frequency, Power Factor

-   Dedicated Zero Crossing Detection (ZCD) Pin
-   Dedicated PWM Output Pin
-   Automatic Event Pin Control through Fast Voltage Surge Detection
-   Fast Calibration Routines
-   2-wire UART: Baud Rate up to 115.2kbps
-   512 bytes User-accessible EEPROM through page read/write commands
-   Low-Drift Internal Voltage Reference: 10 ppm/°C typical
-   28-lead 5x5 QFN package
-   Extended Temperature Range -40°C to +125°C
-   AEC-Q100 qualified

Device web page https://www.microchip.com/wwwproducts/en/MCP39F521

## Applications

   It is intended to be used in systems with **SMBUS** communication like **DJI** smart batteries, **Ardupilot** flight controller systems and any other system that need a smart battery.
   
**SMBUS** specification http://smbus.org/specs/

A practical example it's given with ardupilot flight controller https://ardupilot.org/copter/docs/common-smart-battery-landingpage.html

Choosing the smart battery type in **Mission Planner** 
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/ardupilot.png)
Battery data reporting in **Mission Planner**
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/ardupilot_battery.png)
The system can provide the standard smart battery commands:

    const unsigned int Temperature            = 0;                            // cmd 08   r     - °C
          unsigned int Voltage                = 0;                            // cmd 09   r     - mV
            signed int Current                = 0;                            // cmd 0A   r     - mA
            signed int AverageCurrent         = 0;                            // cmd 0B   r     - average current for 60 sec
          unsigned int RelativeStateOfCharge  = 0;                            // cmd 0D   r     - %
          unsigned int AbsoluteStateOfCharge  = 0;                            // cmd 0E   r     - %
          unsigned int RemainingCapacity      = 0;                            // cmd 0F   r     - mAh
          unsigned int FullChargeCapacity     = 0;                            // cmd 10   r     - mAh
          unsigned int RunTimeToEmpty         = 0;                            // cmd 11   r     - min
          unsigned int AverageTimeToEmpty     = 0;                            // cmd 12   r     - min
          unsigned int AverageTimeToFull      = 0;                            // cmd 13   r     - min
    const unsigned int ChargingCurrent        = 4000;                         // cmd 14   r     - mA
    const unsigned int ChargingVoltage        = 4200;                        // cmd 15   r     - nCell * 4200mV
          unsigned int BatteryStatus          = 0;                            // cmd 16   r     - status
          unsigned int CycleCount             = 10;                           // cmd 17   r     - #
    const unsigned int DesignCapacity         = 9000;                         // cmd 18   r     - mAh
    const unsigned int DesignVoltage          = 11100;                        // cmd 19   r     - nCell * 3700mV
    const unsigned int SpecificationInfo      = 0x0021;                       // cmd 1A   r     - user
    const unsigned int SerialNumber           = 12345;                        // cmd 1C   r     - #

## System Block Diagram 
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/Untitled%20Diagram%281%29.png)

## Application Block Diagram 
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/use%20block%20diag.png)

## PCB

The PCB design its done in Altium designer.
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/board.png)

TOP
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/top.png)

BOTTOM
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/btm.png)

## Schematics

Microcontroller
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/sch_pg1.png)

MCP39F511A
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/sch_pg3.png)

Buck Regulator
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/sch_pg4.png)

USB
![enter image description here](https://raw.githubusercontent.com/catkiller007/MCP39F521-SMBUS-Battery-Monitor/main/Pictures/sch_pg2.png)
