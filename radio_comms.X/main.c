#include <xc.h>
#include "mcc_generated_files/mcc.h";

bool CAN_ok = false;

void CAN_timeout() {
    //200ms timer callback function
    if(!CAN_ok) {
//        LED_RED_SetLow();
//        LED_GREEN_SetHigh();
//        LED_BLUE_SetHigh();
    }
}

void main(void) {
    uCAN_MSG canMessage;
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR1_SetInterruptHandler(&CAN_timeout);
    
    //CAN config 
    CIOCONbits.CLKSEL = 1;
    CIOCONbits.ENDRHI = 1;
    CIOCONbits.TX2SRC = 0;
    CIOCONbits.TX2EN = 0; 
    
    //Connect to bluetooth headphone
    __delay_ms(10000);
    EUSART1_Write('R');
    EUSART1_Write('I');
    EUSART1_Write('N');
    EUSART1_Write('G');
    EUSART1_Write('\n');
    EUSART1_Write('\r');
        
    LED_RED_SetLow();
    while (1) {   
        if (CAN_receive(&canMessage)) {
            CAN_ok = true;
            if (canMessage.frame.id == 0x643) {              
                    CAN_ok = true;
                if(canMessage.frame.data0 & 0b1) {
                //    AUDIO_ON_SetLow();
                    LED_RED_SetHigh();
                    LED_GREEN_SetHigh();
                    LED_BLUE_SetLow();
                } else if(!(canMessage.frame.data0 & 0b1)){
                    LED_RED_SetHigh();
                //    AUDIO_ON_SetHigh();
                    LED_GREEN_SetLow();
                    LED_BLUE_SetHigh();
                }
                
            }
        }
        CAN_ok = false;
        TMR1_StartTimer();
    }
    
    return;
}
