/*
 * File:   main.c
 * Author: FSAE
 *
 * Created on December 15, 2017, 7:18 PM
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h";

uCAN_MSG canMessage;
bool CAN_timeout = true;
bool ringing = false;

void setLED_Blue() {
    LED_BLUE_SetLow();
    LED_GREEN_SetHigh();
    LED_RED_SetHigh();
}

void setLED_Red() {
    LED_RED_SetLow();
    LED_BLUE_SetHigh();
    LED_GREEN_SetHigh();
}

void setLED_Green() {
    LED_GREEN_SetLow();
    LED_RED_SetHigh();
    LED_BLUE_SetHigh();
}

void setLED_Cyan() {
    LED_RED_SetHigh();
    LED_BLUE_SetLow();
    LED_GREEN_SetLow();
}

void ring() {
    // 4s period
    ringing = true;
}

void can_receive_timeout() {
    //5s timeout
    CAN_timeout = true;
}

void main(void) {
    SYSTEM_Initialize();
    TMR1_StopTimer();
    
    //CAN config 
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 0;
    RXF1SIDH = 0xC8;
    RXF1SIDL = 0x60; //Filter for ID 0x643
    TMR1_SetInterruptHandler(&can_receive_timeout);
    TMR0_SetInterruptHandler(&ring);
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    
    //Connect to bluetooth headphone
    __delay_ms(10000); //

    BEEP_SetLow();
    
    while (1) {
        if(AUDIO_ON_GetValue() == 0) {
            setLED_Cyan();
        } else if (CAN_receive(&canMessage)) {
            if (canMessage.frame.id == 0x643) {
                TMR1_Reload();
                CAN_timeout = false;
                if(canMessage.frame.data0 >> 7) {
                    PTT_SetLow();
                    __delay_ms(600);
                    setLED_Green();
                } else {
                    PTT_SetHigh();
                    setLED_Blue();
                }    
            }
        } else if (CAN_timeout) {
            PTT_SetHigh();
            setLED_Red();
        }
        if (ringing) {
            EUSART1_Write('R');
            EUSART1_Write('I');
            EUSART1_Write('N');
            EUSART1_Write('G');
            EUSART1_Write('\n');
            EUSART1_Write('\r');
            ringing = false;
        }
    }
    return;
}
