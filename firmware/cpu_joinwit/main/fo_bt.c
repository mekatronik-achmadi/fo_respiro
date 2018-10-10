#include "fo_bt.h"

void start_bt(void){
    palSetPadMode(GPIOA,2,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOA,3,PAL_MODE_INPUT);
    sdStart(&SD2,NULL);
}

void test_bt(void){
    chprintf((BaseSequentialStream *)&SD2,"test serial ok \n\r");
}
