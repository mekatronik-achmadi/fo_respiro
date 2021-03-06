/**
 * @file    fo_adc.c
 * @brief   ADC Handler code
 *
 * @addtogroup ADC
 * @{
 */

#include "fo_adc.h"

/**
 * @brief   ADC buffer variable.
 */
static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

/**
 * @brief   ADC final variable.
 */
adcsample_t adc0;

/**
 * @brief   ADC DMA routine callback .
 */
void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  uint32_t sum_adc0;

  if (adcp->state == ADC_COMPLETE) {

    sum_adc0=0;

    for(i=0;i<ADC_GRP1_BUF_DEPTH;i++){
        sum_adc0=sum_adc0+samples[0+(i*ADC_GRP1_NUM_CHANNELS)];
    }

    adc0=(sum_adc0/ADC_GRP1_BUF_DEPTH);

   }
 }

/**
 * @brief   ADC configuration group.
 */
static const ADCConversionGroup adcgrpcfg = {
    false,
    ADC_GRP1_NUM_CHANNELS,
    adccb,
    NULL,
    /* HW dependent part.*/
    0,
    0,
    ADC_SMPR2_SMP_AN0(ADC_SAMPLE_239P5),
    0,
    ADC_SQR1_NUM_CH(ADC_GRP1_NUM_CHANNELS),
    0,
    ADC_SQR3_SQ2_N(ADC_CHANNEL_IN0)
};


static THD_WORKING_AREA(waAdc, 128);
#define ThdFunc_ADC THD_FUNCTION

/**
 * @brief   ADC start conversion thread.
 */
static ThdFunc_ADC(thdAdc,arg) {
  (void)arg;
  chRegSetThreadName("adctrigger");

  while (true) {
    chThdSleepMicroseconds(500);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP1_BUF_DEPTH);
  }
}

/**
 * @brief   Starting ADC routine.
 *
 */
void start_adc(void){
    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);
    chThdCreateStatic(waAdc, sizeof(waAdc), NORMALPRIO, thdAdc, NULL);
}

/** @} */
