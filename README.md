# MCP39F511A-SMBUS-Battery-Monitor

This is a smart battery monitor based on Microchip 24-Bit Single Phase AC/DC Power Monitoring IC-**MCP39F511A**.
It is intended to be used in systems with **SMBUS** communication like **DJI** smart batteries, **Ardupilot** systems and any other system that need a smart battery.
The system can provide the standar smart battery commands:


## MCP39F511A Features


The MCP39F511A device is a highly-integrated, complete single-phase power-monitoring IC designed for real-time measurement of input power for AC and DC power supplies, making it suitable for a wide range of consumer and industrial applications. It is capable of detecting the input voltage types in order to select DC or AC mode automatically. It includes dual-channel Delta-Sigma ADCs, a 16-bit calculation engine, EEPROM and a flexible 2-wire interface. Separate AC and DC calibration registers are provided, to ensure high-accuracy measurements in both modes. An integrated low-drift voltage reference with 7 ppm/°C in addition to 94.5 dB of SINAD performance on each measurement channel allows for better than 0.1% accurate designs across a 4000:1 dynamic range.

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

   It is intended to be used in systems with SMBUS communication like DJI smart batteries, ardupilot systems and any other system that need a smart battery.
   
SMBUS specification http://smbus.org/specs/

A practical example it's given with ardupilot flight controller https://ardupilot.org/copter/docs/common-smart-battery-landingpage.html

Choosing the smart battery type in Mission Planner 
![enter image description here](https://lh3.googleusercontent.com/Nz-Pm1pWJTOUIaxA-z57OdngeumQ3byctwtXQpXhdJjJvFH2G75ZisiXTt_YqtdU_KT-H7r8BxtbJXsmjkfiC7dk_nBpC6IXZzAnMZEXXUMdKEmUa3rm-YRL7fMDNnnFpL4B_h-DdeFJD3oupeDf4Xo9g6Dn9DS2gAJ0pONZQpTh-VDq5p-k_-YIqCLixPxyzsFc_1xiJCDfkdUAY84rwKvuFDElOazsuFaVKV0OYDmp81ejp-FZe_ThhOaoDbhUK3veCs--ZQ04HXqB6wcP_gjUEn03-y1hBO-J8jzdc3NW5SWLbFloRVrCuE_Z4dpi4lbXtnajVtCz--DkNRfJn35n_iG8OE6iFba7EjcfYEl6NRTXY2O11-NxNzWuyFSxKlbdTLcmpHaBDyAThOB1OaTAIUaLeAW-yXNobNUMilDSiB7Rc8qEFtWbEncP-JZ5lQuWVdd9xRi5KGi0K-ZaL8leC5z2iDeEBrMUa4RmStFe_cKMEo2vfOeeFzlenm7YsotuGxmqYq859y3Np_nV0buwtyf7UizVAZ8er6XtD1JjNKFOalG4K1F4rl6ZHhaMYLripbNF4uViVaMyafElcr7H9fH7AwB1MeJp1bWUgWmZWsb3DcUdldw8J3FPW6YNFXn1ap8luLlEaPn9geQMB6E0DqHzDcmETp9U2jmAye3svp2CE77IcOm-HygEWqvwdtamlR5GBlN8k-47oyUWkofI=w1836-h530-no?authuser=0)
Battery data reporting in Mission Planner

![enter image description here](https://lh3.googleusercontent.com/hcL6z32l4YAc2mXp1lRe-uz-v7Su1y8u6KC85UWVEVa2h-mTP8tP8_Yr1OnQzo8a2IyKg1VMdzUMCdkijQlNhCU0yPWmhL33xeFpH7a7uBdMMz_tRICi-dvyxnP0DDylh35PQnCFl60mTG2XjByv4Qli2t6q900__D6xdWrOWyZQZdKO7zM_tFJhuQe06LKGHuJatR3tXRFOFjUtTWwS1DIstCho5Xoz_FHmOcj1dVUWz1azOfiUONmOsL_i_5rTZ7WTMRXeH9sP3GqeXYw1sPjtdb9DBtcg-om1B6oxMkscEvvuzQSTrLD-NZQRyu-2-7NognPl_X5dV5sD_S0Jai_J_aSO8NOHEJVnFFphHFaoQKyY15fqkSwAvkb8-c8YipZhLy75yid7pzNplYG0E-p7USjREm0Al7NKdbD5wIMpE1cv0AgFisqb7SkHwfYYluO2STIA-kzLQgiWZRKRG38QT0zo8B5esi76KOeh-uHfz7SQ7MU0d5Ln2dgTNY0b-8BjsTX0TIBBSyPbv4L0qBYSE3ME6PcoJj6SK71nKDl83wb6lgiEU1xNynSRFNRW7vpk_mDQLEjSemAyzN6C3FQizCwogOTMK9zaPpyH_K0KxfNqvc5UT8P0spnnQJPfTamQe6bQoc1ysl-6Wmv5NA-OSXF4PPYKZTu6CdivQMBtUmi3RDi1pf2AEfixdiAprrH7trKxJpnbQ4srLOLTSRKQ=w1834-h1268-no?authuser=0)
