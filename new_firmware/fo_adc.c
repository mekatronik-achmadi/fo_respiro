#include "fo_adc.h"

static adcsample_t samples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH];

adcsample_t adc0;
uint32_t sum_adc0;

adcsample_t data_array[X_LENGTH];

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
  ADC_SMPR2_SMP_AN0(ADC_SAMPLE_112),
  ADC_SQR1_NUM_CH(ADC_GRP_NUM_CHANNELS),
  0,
  ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0)
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

static THD_WORKING_AREA(wa_adcshiftThread, 128);
static THD_FUNCTION(adcshiftThread, arg) {
  (void)arg;
  chRegSetThreadName("ADC Shift");
  while (TRUE) {
    chThdSleepMilliseconds(10);
    FO_Data_Shift(adc0-OFF_ADC);

  }
}

void FO_Adc_Init(){
    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);

    chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);
    chThdCreateStatic(wa_adcshiftThread, sizeof(wa_adcshiftThread), NORMALPRIO, adcshiftThread, NULL);
}

void FO_Data_Shift(adcsample_t v_input){
    uint8_t i;

    for(i=1;i<X_LENGTH;i++){
        data_array[i]=data_array[i-1];
    }

    data_array[0]=v_input;
}
