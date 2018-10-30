/**
 * @file    main.c
 * @brief   GPIO interface handling.
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

    while(true) {
        shell_bt();
        gfxSleepMilliseconds(500);
    }
}

/** @} */
