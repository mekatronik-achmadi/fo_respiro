/**
 * @file    main.c
 * @brief  Main source code
 *
 * @addtogroup MAIN
 * @{
 */


#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "fo_gui.h"
#include "fo_adc.h"
#include "fo_bt.h"
#include "fo_data.h"
#include "fo_exti.h"

/**
 * @brief   Draw graph routine thread. This is main routine for the job
 */
static THD_WORKING_AREA(waLED, 512);
static THD_FUNCTION(thdLED, arg) {
    (void)arg;
    chRegSetThreadName("runled");

    while(1){
        palTogglePad(GPIOE,5);
        gfxSleepMilliseconds(500);
    }
}

/**
 * @brief   Main Function
 *
 * @return              Status of execution
 * @retval 0	        Success
 * @retval 1			Not Success
 *
 */
int main(void) {

    gfxInit();

    start_exti();
    start_adc();
    start_bt();
    start_data();
    start_routine();

    palSetPadMode(GPIOE, 5,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE, 5);
    chThdCreateStatic(waLED, sizeof(waLED),	NORMALPRIO, thdLED, NULL);

    while(true) {
        shell_bt();
        gfxSleepMilliseconds(500);
    }
}

/** @} */
