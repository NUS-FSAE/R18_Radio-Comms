/*
 * File:   main.c
 * Author: FSAE
 *
 * Created on December 15, 2017, 7:18 PM
 */


#include <xc.h>
#include "mcc_generated_files/mcc.h";

uCAN_MSG canMessage;

void main(void) {
    SYSTEM_Initialize();
    
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 0; 
    
    //LED_BLUE_SetLow();
    __delay_ms(10000);
    EUSART1_Write('R');
    EUSART1_Write('I');
    EUSART1_Write('N');
    EUSART1_Write('G');
    EUSART1_Write('\n');
    EUSART1_Write('\r');
    
    while (1) {
        if (CAN_receive(&canMessage)) {
            if (canMessage.frame.id == 0x640) {
                LED_RED_SetLow();
                __delay_ms(200);
            }
        }
    }
    
    return;
}
