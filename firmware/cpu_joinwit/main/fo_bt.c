#include "fo_bt.h"

void start_bt(void){
    palSetPadMode(GPIOB,10,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOB,11,PAL_MODE_INPUT);
    sdStart(&SD3,NULL);
}

void test_bt(void){
    chprintf((BaseSequentialStream *)&SD3,"test serial ok \n\r");
}
