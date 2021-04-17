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

Device web page https://www.microchip.com/wwwproducts/en/MCP39F521

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

## System Block Diagram 
![enter image description here](https://lh3.googleusercontent.com/Ajs4Ss-s_SY_vg1gdsJ8DbFhPhGjDxqMYIotm569ERTdCx_cEReyBe_HWLupvyjOGRlqoD9Ul5bQ8LuA698H6Se84HqwQEdDTN9Sdsk1G624Zdl-RVLGw9s5iTjj1ITvmpeUx91WOmb2y3VhPDoipn4uyRgAg6xM59yk3ctaNa4QXnn5AknZnZsWo4LiCJhTfB5F9zHgW6ATDOsCwxx8Yl6alFGKFc5GKpQ4mz-GaqvMsJgMKhJhe2FZMOAUzJL81ue5z3eXkevHsdv1qiwwSMR2HyZknU4IOdvDqN6m_vzB9WgZZyo74CmtkKtV1KgBmnS2tTNmYNSW96gMtTp7jqDawp3l9Pxp-xio7qA3AkQsDSp554zNL2BoYggXR8BHVpRp726YylUQma3Dni85I7_bxYPr-U-GJyAn-q-FBT7QtJZl5uQzxo5UmFMY3R2q1IT-JpXZv9B86DEp64pyeJQmkOKxFPAbO5EAXFEhk7lQLnp-xy3uGmfiWxeKXYc-lyilW8h99tJlwSxaws-O5BoWst9b0WQKj3S-T1gyO6zyDaAIhEtBhDtysGhRN6Sk8TXvW_NsinWG4QW74Ia_PLbq0hNbdnuZEjiuIBbO-kr5wQfSHXkmF_kv1TnlSJ26-dGyyiDEkEvhAJyVwxuDwoZavT9_37U_sjdMnVS6S8qiqAZuYTf9lOah5VRhc3LttWwjIBopvWvfeCpzYmSAW_ax=w1055-h808-no?authuser=0)

## PCB

The PCB design its done in Altium designer.

![enter image description here](https://lh3.googleusercontent.com/Inny6Rmvvf0m7qI5NzU4f-6bc4WiuC_tW0TJT-wi3_VeKG1nn7TIgDNy4kCZNQuXjgsIBpZeTB_FxmBoI4RloEczqI8ZF5iHU1IWLeGLQN7i9x_bajdC9R54vAHWiUMYzg8N9qbkvoBzFDQcEqKUZttaTfVJN2GFjP1ZiV5KQ7LautGzyS0qeRmKqKJtJkxkT5-gsmcvmUxoEw0tm6syPitnR0MN0PGUP9r01ozemO-JS6V6NV_FJS0d-4Kz3zjmrA6jkpK5ReXr_uGfcAGlGXRt02loo2mbVI_ZL4kHQwP3eAOnxz6EOzmyDwtW6bjm6NvaRXlJ3rKsoIOJhGolH0s4-Z-uZc89oMOy0ck9Oz4TPrPP_MiNWRMcF16M-2ZuLLysi8o4kbqnHw40vNUrgjQHTQTQ_da0aB5saOhglsN-ifu0dg5DnDTJ6dvyasGPixPBfU0bLjVa61xWQhEhq2Fblyqid-zV5QNJ60OX27c6_8idUUEDptB7be9dfE62gTG0GF8BapZfAtnQBvwR9lGLIXwRi9pvq4yVGH21567V4AE5vw07MAIErqIsrVUcWSUDtueVocSwyizqIX5hYU2luGurq2PiK7ayoGM5L-IKYEmEu0vQBjFs7kELH6Rml59u3bKCyTOD9WKHzUJ4dlIfc0j48A6MQ0Iw3NENY5PAz7mirUMMpPSLrKI5LZB6qpvQXv-0Q6Syn04t4otKG7Z7=w1176-h850-no?authuser=0)
