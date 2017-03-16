#include "gfx.h"
#include "ch.h"
#include "hal.h"

#include "chprintf.h"

#include <string.h>

GHandle ghlblADC0, ghlblADC1;

#define ADC_GRP1_NUM_CHANNELS   2
#define ADC_GRP1_BUF_DEPTH      10

static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

adcsample_t adc0,adc1;
uint32_t sum_adc0,sum_adc1;

void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  if (adcp->state == ADC_COMPLETE) {

    sum_adc0=0;
    sum_adc1=0;

    for(i=0;i<ADC_GRP1_BUF_DEPTH;i++){
        sum_adc0=sum_adc0+samples[0+(i*ADC_GRP1_NUM_CHANNELS)];
        sum_adc1=sum_adc1+samples[1+(i*ADC_GRP1_NUM_CHANNELS)];
    }

    adc0=sum_adc0/ADC_GRP1_BUF_DEPTH;
    adc1=sum_adc1/ADC_GRP1_BUF_DEPTH;

   }
 }

static const ADCConversionGroup adcgrpcfg = {
    FALSE,
    ADC_GRP1_NUM_CHANNELS,
    adccb,
    NULL,
    /* HW dependent part.*/
    0,
    0,
    ADC_SMPR2_SMP_AN0(ADC_SAMPLE_239P5) | ADC_SMPR2_SMP_AN1(ADC_SAMPLE_239P5),
    0,
    ADC_SQR1_NUM_CH(ADC_GRP1_NUM_CHANNELS),
    0,
    ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0) | ADC_SQR3_SQ2_N(ADC_CHANNEL_IN1)
};

static THD_WORKING_AREA(wa_adcThread, 128);
static THD_FUNCTION(adcThread,arg) {
  (void)arg;

  while (TRUE) {
    chThdSleepMilliseconds(100);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP1_BUF_DEPTH);
  }
}

char txt_adc0[16];
char txt_adc1[16];

static void TextUpdate(void){
    chsnprintf(txt_adc0,16,"%4i",adc0);
    gwinSetText(ghlblADC0, txt_adc0, TRUE);
    chsnprintf(txt_adc1,16,"%4i",adc1);
    gwinSetText(ghlblADC1, txt_adc1, TRUE);

    chThdSleepMilliseconds(100);
}

//========================================================

static THD_WORKING_AREA(waBlink, 128);
static THD_FUNCTION(thdBlink, arg) {

  (void)arg;

  chRegSetThreadName("blinker");
  while (true) {
    palSetPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
    palClearPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
  }
}

//========================================================

float calibrationData[] = {
    -0.06678,		// ax
    -0.00187,		// bx
    259.06353,		// cx
    0.00039,		// ay
    0.09974,		// by
    -31.92561 		// cy
};

bool_t LoadMouseCalibration(unsigned instance, void *data, size_t sz)
{
    (void)instance;

    if (sz != sizeof(calibrationData) || instance != 0) {
        return FALSE;
    }

    memcpy(data, (void*)&calibrationData, sz);

    return TRUE;
}

//========================================================

static void createWidgets(void) {
    GWidgetInit	wi;

    // Apply some default values for GWIN
    gwinWidgetClearInit(&wi);
    wi.g.show = TRUE;

    // Create the IP label
    wi.g.width = 200; wi.g.height = 20; wi.g.x = 10, wi.g.y = 80;
    wi.text = "0";
    ghlblADC0 = gwinLabelCreate(0, &wi);
    gwinLabelSetAttribute(ghlblADC0, 100, "ADC0:");

    // Create the DHCP label
    wi.g.width = 200; wi.g.height = 20; wi.g.x = 10, wi.g.y = 100;
    wi.text = "0";
    ghlblADC1 = gwinLabelCreate(0, &wi);
    gwinLabelSetAttribute(ghlblADC1, 100, "ADC1:");
}

int main(void) {

    // Initialize the display
    gfxInit();

    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA,1,PAL_MODE_INPUT_ANALOG);
    adcStart(&ADCD1, NULL);
    chThdCreateStatic(wa_adcThread, sizeof(wa_adcThread), NORMALPRIO, adcThread, NULL);

    palSetPadMode(GPIOE,5,PAL_MODE_OUTPUT_PUSHPULL);
    chThdCreateStatic(waBlink, sizeof(waBlink), NORMALPRIO, thdBlink, NULL);

    // Set the widget defaults
    gwinSetDefaultFont(gdispOpenFont("*"));
    gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);
    gdispClear(White);
    gdispSetOrientation(GDISP_ROTATE_90);

    // create the widget
    createWidgets();

    while(1) {
        TextUpdate();
    }

    return 0;
}
