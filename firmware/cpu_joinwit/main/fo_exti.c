/**
 * @file    fo_exti.c
 * @brief   GPIO interface handling code
 *
 * @addtogroup GPIO
 * @{
 */

#include "fo_exti.h"

extern adcsample_t adc0;
extern point vdata[N_DATA];

uint8_t run_mode=RUN_STATE;

/**
 * @brief   EXTI PORTC.0 callback:
 *			- call data out function
 */
static void extcbDataOut(EXTDriver *extp, expchannel_t channel) {

    (void)extp;
    (void)channel;

    if(run_mode==RUN_STATE)run_mode=PAUSE_STATE;
    else if(run_mode==PAUSE_STATE)run_mode=RUN_STATE;
}

/**
 * @brief   EXTI Interrupt configuration
 *
 */
static const EXTConfig extcfg = {
  {
    {EXT_CH_MODE_FALLING_EDGE | EXT_CH_MODE_AUTOSTART | EXT_MODE_GPIOC, extcbDataOut},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL},
    {EXT_CH_MODE_DISABLED, NULL}
  }
};

/**
 * @brief   Start EXTI interrupt
 *
 */
void start_exti(void){
    palSetPadMode(GPIOA,9,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOC, 0,PAL_MODE_INPUT_PULLUP);

    extStart(&EXTD1, &extcfg);
    sdStart(&SD1,NULL);
}

/** @} */
