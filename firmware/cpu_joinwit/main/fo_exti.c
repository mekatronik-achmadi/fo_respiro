/**
 * @file    fo_exti.c
 * @brief   GPIO interface handling.
 *
 * @addtogroup GPIO
 * @{
 */

#include "fo_exti.h"

extern adcsample_t adc0;
extern point vdata[N_DATA];

/**
 * @brief   data out to serial function
 */
static void exti_dataout(void){
    chprintf((BaseSequentialStream *)&SD1,"ADC0 = %4i\n\r",adc0);
}

/**
 * @brief   EXTI PORTC.0 callback:
 *			- call data out function
 */
static void extcbDataOut(EXTDriver *extp, expchannel_t channel) {

    (void)extp;
    (void)channel;

    exti_dataout();
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