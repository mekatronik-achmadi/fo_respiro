#include "fo_adc.h"

static adcsample_t samples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH];

adcsample_t adc0;
uint32_t sum_adc0;

void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  if (adcp->state == ADC_COMPLETE) {

    sum_adc0=0;

    for(i=0;i<ADC_GRP_BUF_DEPTH;i++){
        sum_adc0=sum_adc0+samples[i*ADC_GRP_NUM_CHANNELS];
    }

    adc0=sum_adc0/ADC_GRP_BUF_DEPTH;
   }
 }

static const ADCConversionGroup adcgrpcfg = {
  FALSE,
  ADC_GRP_NUM_CHANNELS,
  adccb,
  NULL,
  /* HW dependent part.*/
  0,
  ADC_CR2_SWSTART,
  0,
  ADC_SMPR2_SMP_AN3(ADC_SAMPLE_112),
  ADC_SQR1_NUM_CH(ADC_GRP_NUM_CHANNELS),
  0,
  ADC_SQR3_SQ1_N(ADC_CHANNEL_IN3)
};

static THD_WORKING_AREA(wa_adcThread, 128);
static THD_FUNCTION(adcThread, arg) {
  (void)arg;
  chRegSetThreadName("ADC Run");
  while (TRUE) {
    chThdSleepMilliseconds(100);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP_BUF_DEPTH);
  }
}

void FO_Adc_Init(){
    palSetPadMode(GPIOA,3,PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);

    chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);
}
