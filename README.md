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

## Schematics
Microcontroller

![enter image description here](https://lh3.googleusercontent.com/mSzP7UsCJ-I1wtHEh31xxDW4gVl6GFHgebOBKciEZVFpPPXRAUbkpExHZWhTk8EMTdNuoJgXLgYo6xoNQa0jmwH8--gCtyMGX1775qpx-YiO80Rn3pq7rpd_Ckj_UxwUKTF-6f2mpWWj86FpqvNTYPcsQeqf7HOXHYqJ6jPhNUhK5_n0lqXcrEL82m1dIYZ3g5nmws4L2BrYNKWv5veKXrUbyfuvi8cFwaaFVTtWIjIbYvMqveechPfYSm7bxTQljnWBcOfhsUhQckiqrI4nzsyLbzXMmKL_G7vGiIhNlCeZ5SNlEE3SQXjweIunII8sl9ORiMssU9KEW7p_qqqQ5Ap-8xpteJxnnA_gTb8Tm7z36rreaXDSbKTRDatWzDGvvDgZ0ixW3rBv889DtG2e-qq8ydhrsf9QSUcvVN9Q9gUtmRky2MhTq-Nsr0i5hs_Yk-KB17zMpO8xDb2WTGK3cj-oFsc4tgJ8scdM8g1QGGGM9p-UUdbet_nvV5skuFMTF4US3bM6--IkLced9AozEVEbt1bDB_7kWYXwSwlM9HmU2cbbElPsIJKNOfZIIUw3jJnJBN6XGrWKxR4qKbnGUM4LYg4l7H-_96HjXq2KPoc1cF8mTKakyijfJ8nsMnl0rMCR8fT6lBwB1I6EQOemr3ryUqRmf4QeZAlUWiR0Dv5A4024yEGmfg8FLKwekpzM6cp5EnETyo0YdRn7gbTxj2y-=w1918-h1373-no?authuser=0)

MCP39F511A

![enter image description here](https://lh3.googleusercontent.com/71c8oBwLsAw3XT1_llCBbGCrN1vHdI6WyFuoPbn-n6hjH4qT6ILGn9BV-Au-fF9diRwI35YrsSBMYYvXuIxJgCC8dq43H4qciqMhepObRPCbxDSPZNHNLKcdOsivBCWZ0nG9gf40MIak2imfClUkM-1lAOGv8q2kXlkWNcYT_9cK0_JBJezKHLTUZyWRXvWmj_GTYzRdhcB-7upScwjt-Cgn2_lq-30iSD-xc46xCy00rQa3NFlVAeiphWEmKYKFq_3n-J61pa7MVzj3k8YzO6PjLSBoVjQ9ITV6VsQNxZsNsCtMvnliIOlXgcZwrRxlWmCr7GJOpSWHdtXbt1DwoTEmSN07sRXPHRipHww3QuwUI2OVgqg48d1AR1XkS9K1QRGg_n89-5XNI71qq2tyObMF3vlkMjVZt4IJzF_NuIC7agfyMP3VLMQvl6t0hu7pivF0fTANVHaYl34Acv1pf2P46zFLfE6erxrGnU7KG8AMShHlOwfxwMEvuxMBNqr9GUptMglyUfso5aW2tKJTxKbCnWglpo5hWDPfntF-XsjKTm-uvZtKE3X368FnIy-BBqodXNUO82dy5mtRKHHZeX0nlatHaKzOQRUM53l-jezDoN1JD7vCpEtO39NSbXP2y5H3IvFKXBQkiQXDRz-nvqQ-G6-py0AQPdNsMaxTf2tt_n16cSutcxG8LF806FfZQ2WWerKyLc2Qv5gx9u1LsFcV=w1918-h1375-no?authuser=0)

Buck Regulator

![enter image description here](https://lh3.googleusercontent.com/lH8DM5jS4BXGPEp0QIvl26y2gZUje-eEBmMFG8CgeBm88_XuwIzL-nIn7Gzsk-F6_3RBXAXVbVVLbWe3M0-JQ1BdU9TyxjmjfL7ouXD6EZh3PTCLSpRD4SpUnLubJn2u5UFkBQPxGRd4mHOuOe0I-SMRLkcGwbTQx7JeMcj6HI6uWe2hhgKdwzlb4ZSsjaAH2jKcWKFHg8duhxxWUrfSd5dum8F7tMCakaaQSLnyczTRqoNIsGYgxojjsBp7BFj_VeJpw3JZBbaaPCeihrL5S3xCfkaxIyGe08TzWx3EEjhG7FW1FLJmr9Ayr-OV5Fl8F6z2SU5kG_eNeRAiyMf_FPv5aBRngazhM0BQnRpC3el_d3ZPkE1DZqyhXskKWwk8jqUiXqqCyFKVgr1BINSTK7KfiF23YZGbxTf4LuCpt_VnXesbdqQZDRFWpvFLtrqGoSP8EvE_4TAJbFORl3Kzdx0A4oZXLPzyMV5JDtMLcg9ag3Qqr-ECv7hlRNBGVuV42fKtwQ4q-_cLXWOjMEScJRHoXlHfdib-PlEyDVSyh86sNp5klbdLpo_wbn51mfRyKXPRjRacf0HXZF9ZZZgklYh71Ti3fwV1AO2v2K5C3OCx_IeK_i5rXSeKyxZeASdsi3wcuJLmwd3sgTeWf3tpjCGRsRlOhAzE_cNX8JTzl2eNZWhW1UIirmRRq81OogelB5itpxNGomD7Enyjb3BRTHmV=w1918-h1373-no?authuser=0)

USB

![enter image description here](https://lh3.googleusercontent.com/ugu8F4XXiFtFv5B0ALNKV4AjYkGEJDQxnEPIVAB0IsprMNA4bGxa1g-pOeKcoQztqXcbMCoYrcgxmJZqSji_EtLFSNfn1Bbnv96xwVFSP9xakOV6b0vIyeb1npgRJmGsWR6SgTpbmoTHSKTMxT4hAUYHWya9XVHJb8NqZIDUkJy6oa9ScGLJoziDOJlT1syguJFHdOJMiiPkWxuEd_af0_WSnyU9-Z9D0YnTI9qbsKl-JAEVSunWlAXibp1-dYfGOpXOuqWNull_p-MoKvId3YQXJWtq4OE1493BlUKCaNpf_M3UfTW73HIpTXXD6uZb43fgnq0K6CUabj2KODzuCSUy7_2eR2ZpHd0cNAR2TDv4WqPLkUnM1fBgBL3Zg4cNMH2syaOHL1zwgZ1u9Oi8J2ammR1brc1HWfQhU9y2Clff8gIiPVubssk_tmGhLzvLVCVbPj0LCkr1D6mh-9VR2UheYG4p9vu2WWyMR34R_YJAUPohIR4Mt-S46-0GPnNe7lm-hMs8NM5XxooNLzIbh41qKblt9CJX-yuJb6SL7mdHNvR_JRl6TlpXQPX7j2z_WL18WaqWT_oHhTxYXmEq1weUYWcAoHKJqQtJSYLQEgEgQ99gUdzW7mas8GG8-E8mO0N_DkXJwtGC--JhS-BC1S4H5LPwzDmqGQGuOPajXpKAWramIGpH4J4xuPqzjMyIwZL6JvVP3S_NpeSWBE9gzOdJ=w1918-h1370-no?authuser=0)
