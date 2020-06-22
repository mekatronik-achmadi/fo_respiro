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
#include "fo_comm.h"

static THD_WORKING_AREA(waLED, 32);
#define ThdFunc_RunLED THD_FUNCTION

/**
 * @brief   LED RUN Blink thread.
 */
static ThdFunc_RunLED(thdLED, arg) {
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
 */
int main(void) {

    gfxInit();

    start_exti();
    start_adc();
    start_comm();
    start_data();
    start_routine();

    palSetPadMode(GPIOE, 5,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE, 5);
    chThdCreateStatic(waLED, sizeof(waLED),	NORMALPRIO, thdLED, NULL);

    while(true) {
        shell_comm();
        gfxSleepMilliseconds(500);
    }
}

/** @} */
