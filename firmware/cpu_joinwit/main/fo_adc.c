#include "fo_adc.h"

static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

adcsample_t adc0;
uint32_t sum_adc0;

void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  if (adcp->state == ADC_COMPLETE) {

    sum_adc0=0;

    for(i=0;i<ADC_GRP1_BUF_DEPTH;i++){
        sum_adc0=sum_adc0+samples[0+(i*ADC_GRP1_NUM_CHANNELS)];
    }

    adc0=sum_adc0/ADC_GRP1_BUF_DEPTH;

   }
 }

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
static THD_FUNCTION(thdAdc,arg) {
  (void)arg;

  while (true) {
    chThdSleepMilliseconds(100);
    palTogglePad(GPIOE,6);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP1_BUF_DEPTH);
  }
}

void start_adc(void){
    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);
    chThdCreateStatic(waAdc, sizeof(waAdc), NORMALPRIO, thdAdc, NULL);

    palSetPadMode(GPIOE, 6,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE,6);
}
