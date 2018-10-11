#include "fo_bt.h"
#include "fo_adc.h"
#include "fo_gui.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern adcsample_t adc0;
extern point vdata[N_DATA];

void start_bt(void){
    palSetPadMode(GPIOB,10,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOB,11,PAL_MODE_INPUT);
    sdStart(&SD3,NULL);
}

void test_bt(void){
    chprintf((BaseSequentialStream *)&SD3,"ADC0= %4i | Y0= %4i\n\r",adc0,vdata[0].y);
}
