#include "fo_uart.h"

void FO_Uart_Init(void){
    palSetPadMode(GPIOA,10,PAL_MODE_ALTERNATE(7));
    palSetPadMode(GPIOA,9,PAL_MODE_ALTERNATE(7));
    sdStart(&SD1,NULL);
}

void FO_Uart_Test(void){
    chprintf((BaseSequentialStream *)&SD1,"test serial ok \n\r");
    chThdSleepMilliseconds(500);
}
