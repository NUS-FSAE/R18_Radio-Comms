/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
        Device            :  PIC18F66K80
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set AUDIO_ON aliases
#define AUDIO_ON_TRIS               TRISAbits.TRISA5
#define AUDIO_ON_LAT                LATAbits.LATA5
#define AUDIO_ON_PORT               PORTAbits.RA5
#define AUDIO_ON_ANS                ANCON0bits.ANSEL4
#define AUDIO_ON_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define AUDIO_ON_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define AUDIO_ON_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define AUDIO_ON_GetValue()           PORTAbits.RA5
#define AUDIO_ON_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define AUDIO_ON_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define AUDIO_ON_SetAnalogMode()  do { ANCON0bits.ANSEL4 = 1; } while(0)
#define AUDIO_ON_SetDigitalMode() do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()    do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()   do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()   do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()         PORTBbits.RB2
#define RB2_SetDigitalInput()   do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()  do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()     do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()   do { WPUBbits.WPUB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()    do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()   do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()   do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()         PORTBbits.RB3
#define RB3_SetDigitalInput()   do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()  do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()     do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()   do { WPUBbits.WPUB3 = 0; } while(0)

// get/set LED_BLUE aliases
#define LED_BLUE_TRIS               TRISDbits.TRISD4
#define LED_BLUE_LAT                LATDbits.LATD4
#define LED_BLUE_PORT               PORTDbits.RD4
#define LED_BLUE_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LED_BLUE_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LED_BLUE_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LED_BLUE_GetValue()           PORTDbits.RD4
#define LED_BLUE_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LED_BLUE_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set LED_GREEN aliases
#define LED_GREEN_TRIS               TRISDbits.TRISD5
#define LED_GREEN_LAT                LATDbits.LATD5
#define LED_GREEN_PORT               PORTDbits.RD5
#define LED_GREEN_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED_GREEN_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED_GREEN_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED_GREEN_GetValue()           PORTDbits.RD5
#define LED_GREEN_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED_GREEN_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set LED_RED aliases
#define LED_RED_TRIS               TRISDbits.TRISD6
#define LED_RED_LAT                LATDbits.LATD6
#define LED_RED_PORT               PORTDbits.RD6
#define LED_RED_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LED_RED_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define LED_RED_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LED_RED_GetValue()           PORTDbits.RD6
#define LED_RED_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LED_RED_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set RG0 procedures
#define RG0_SetHigh()    do { LATGbits.LATG0 = 1; } while(0)
#define RG0_SetLow()   do { LATGbits.LATG0 = 0; } while(0)
#define RG0_Toggle()   do { LATGbits.LATG0 = ~LATGbits.LATG0; } while(0)
#define RG0_GetValue()         PORTGbits.RG0
#define RG0_SetDigitalInput()   do { TRISGbits.TRISG0 = 1; } while(0)
#define RG0_SetDigitalOutput()  do { TRISGbits.TRISG0 = 0; } while(0)

// get/set RG3 procedures
#define RG3_SetHigh()    do { LATGbits.LATG3 = 1; } while(0)
#define RG3_SetLow()   do { LATGbits.LATG3 = 0; } while(0)
#define RG3_Toggle()   do { LATGbits.LATG3 = ~LATGbits.LATG3; } while(0)
#define RG3_GetValue()         PORTGbits.RG3
#define RG3_SetDigitalInput()   do { TRISGbits.TRISG3 = 1; } while(0)
#define RG3_SetDigitalOutput()  do { TRISGbits.TRISG3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/