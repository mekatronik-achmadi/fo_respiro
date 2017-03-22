#include "gfx.h"
#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "math.h"

#include <string.h>

GHandle ghlblY1,ghlblDY,ghPlot,ghbtnStart,ghbtnSave;

#define ADC_GRP1_NUM_CHANNELS   1
#define ADC_GRP1_BUF_DEPTH      100

static adcsample_t samples[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];

adcsample_t adc0;
uint32_t sum_adc0;

adcsample_t y_0,y_1,dy;

static point data[20] = {
    { 10, 0 },
    { 20, 0 },
    { 30, 0 },
    { 40, 0 },
    { 50, 0 },
    { 60, 0 },
    { 70, 0 },
    { 80, 0 },
    { 90, 0 },
    { 100,0 },
    { 110, 0 },
    { 120, 0 },
    { 130, 0 },
    { 140, 0 },
    { 150, 0 },
    { 160, 0 },
    { 170, 0 },
    { 180, 0 },
    { 190, 0 },
    { 200,0 }
};

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
    FALSE,
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
    ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0)
};

static THD_WORKING_AREA(wa_adcThread, 128);
static THD_FUNCTION(adcThread,arg) {
  (void)arg;

  while (TRUE) {
    chThdSleepMilliseconds(100);
    adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP1_BUF_DEPTH);
  }
}

char txt_adc[6];

static GGraphStyle GraphStyle1 = {
    { GGRAPH_POINT_DOT, 0, Blue },          // Point
    { GGRAPH_LINE_NONE, 2, Gray },          // Line
    { GGRAPH_LINE_SOLID, 0, White },        // X axis
    { GGRAPH_LINE_SOLID, 0, White },        // Y axis
    { GGRAPH_LINE_DASH, 5, Gray, 50 },      // X grid
    { GGRAPH_LINE_DOT, 7, Yellow, 50 },     // Y grid
    GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS   // Flags
};

static const GGraphStyle GraphStyle2 = {
    { GGRAPH_POINT_SQUARE, 5, Red },        // Point
    { GGRAPH_LINE_DOT, 2, Blue },           // Line
    { GGRAPH_LINE_SOLID, 0, White },        // X axis
    { GGRAPH_LINE_SOLID, 0, White },        // Y axis
    { GGRAPH_LINE_DASH, 5, Gray, 50 },      // X grid
    { GGRAPH_LINE_DOT, 7, Yellow, 50 },     // Y grid
    GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS   // Flags
};

static void TextUpdate(void){

    uint16_t i;

    for(i=19;i>0;i--){
        data[i].y = data[i-1].y;
    }

    y_1=adc0;
    if(y_1>y_0){dy=y_1-y_0;}
    else{dy=y_0-y_1;}
    y_0=y_1;

    data[0].y = dy;

    chsnprintf(txt_adc,6,"%4i",y_1);
    gwinSetText(ghlblY1, txt_adc, TRUE);

    chsnprintf(txt_adc,6,"%4i",dy);
    gwinSetText(ghlblDY, txt_adc, TRUE);

    gwinClear(ghPlot);
    gwinGraphSetOrigin(ghPlot, 0, 0);
    gwinGraphSetStyle(ghPlot, &GraphStyle1);
    gwinGraphDrawAxis(ghPlot);
    gwinGraphStartSet(ghPlot);
    gwinGraphSetStyle(ghPlot, &GraphStyle2);
    gwinGraphDrawAxis(ghPlot);
    gwinGraphDrawPoints(ghPlot, data, sizeof(data)/sizeof(data[0]));

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
    GWindowInit win;

    gwinWidgetClearInit(&wi);
    wi.g.show = TRUE;
    win.show = TRUE;

    wi.g.width = 100; wi.g.height = 20; wi.g.x = 10, wi.g.y = 40;
    wi.text = "0";
    ghlblY1 = gwinLabelCreate(0, &wi);
    gwinLabelSetAttribute(ghlblY1, 50, "y  :");

    wi.g.width = 100; wi.g.height = 20; wi.g.x = 130, wi.g.y = 40;
    wi.text = "0";
    ghlblDY = gwinLabelCreate(0, &wi);
    gwinLabelSetAttribute(ghlblDY, 50, "dy :");

    win.x = 10;
    win.y = 100;
    win.width = 200;
    win.height = 100;
    ghPlot = gwinGraphCreate(0, &win);

    gwinGraphSetOrigin(ghPlot, 0, 0);
    gwinGraphSetStyle(ghPlot, &GraphStyle1);
    gwinGraphDrawAxis(ghPlot);

    wi.g.width = 50; wi.g.height = 20; wi.g.x = 250, wi.g.y = 40;
    wi.text = "Start";
    ghbtnStart = gwinButtonCreate(0, &wi);

    wi.g.width = 50; wi.g.height = 20; wi.g.x = 250, wi.g.y = 80;
    wi.text = "Save";
    ghbtnSave = gwinButtonCreate(0, &wi);

}

int main(void) {

    // Initialize the display
    gfxInit();

    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
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
