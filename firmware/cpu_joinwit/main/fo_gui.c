/**
 * @file    fo_gui.c
 * @brief   Display GUI code
 *
 * @addtogroup GUI
 * @{
 */

#include "fo_gui.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern adcsample_t adc0;
extern point vdata[N_DATA];

/*===========================================================================*/
/* GRAPH PART                                                                */
/*===========================================================================*/

/**
 * @brief   play status variable
 */
u_int8_t play_stt;

/**
 * @brief   play duration counter  variable
 */
u_int16_t play_dur;

/**
 * @brief   object for overall graphic GUI
 */
static GGraphObject g;

/**
 * @brief   graphic line configuration
 */
static GGraphStyle GraphLine = {
    { GGRAPH_POINT_DOT, 10, White },          // Point
    { GGRAPH_LINE_SOLID, 10, White },          // Line
    { GGRAPH_LINE_SOLID, 0, Gray },        // X axis
    { GGRAPH_LINE_SOLID, 0, Gray },        // Y axis
    { GGRAPH_LINE_DOT, 5, Gray, 50 },      // X grid
    { GGRAPH_LINE_DOT, 5, Gray, 50 },     // Y grid
    GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS   // Flags
};

/**
 * @brief   play duration counter thread
 */
static THD_WORKING_AREA(waPlay, 256);
static THD_FUNCTION(thdPlay, arg) {
    (void)arg;
    chRegSetThreadName("playduration");

    while(true){
        if(play_stt == 1){
            play_dur++;
        }
        gfxSleepMilliseconds(PLAY_DELAY);
    }
}

/*===========================================================================*/
/* DRAWING PART                                                              */
/*===========================================================================*/

/**
 * @brief   object for graphic and console window
 */
GHandle     gh,gc;

/**
 * @brief   console string variable
 */
char txt_adc0[16];

/**
 * @brief   Main GUI routine function
 */
static void gui_routine(void){
    u_int16_t cadc;

    gwinGraphStartSet(gh);
    gwinGraphDrawAxis(gh);
    gwinGraphDrawPoints(gh, vdata, sizeof(vdata)/sizeof(vdata[0]));

    cadc = data_calib(adc0);

    chsnprintf(txt_adc0,16,"ADC0= %4i |",adc0);
    gwinPrintf(gc, txt_adc0);
    chsnprintf(txt_adc0,16,"CADC= %4i uW |",cadc);
    gwinPrintf(gc, txt_adc0);
    chsnprintf(txt_adc0,16," Y0= %4i\n",vdata[0].y);
    gwinPrintf(gc, txt_adc0);

    gfxSleepMilliseconds(DISP_DELAY);
    gwinClear(gh);
    gwinClear(gc);
    palTogglePad(GPIOE,5);
}

/**
 * @brief   Draw graph routine thread. This is main routine for the job
 */
static THD_WORKING_AREA(waDraw, 256);
static THD_FUNCTION(thdDraw, arg) {
    font_t	    gfont;

    (void)arg;
    chRegSetThreadName("drawgraph");

    gfont = gdispOpenFont("UI2");
    gwinSetDefaultFont(gfont);

    {
      GWindowInit wi;
      gwinClearInit(&wi);

      wi.show = true;

      wi.x = 0;
      wi.y = 0;
      wi.width = gdispGetWidth();
      wi.height = (gdispGetHeight()/16)*15;
      gh = gwinGraphCreate(&g, &wi);

      wi.x = 0;
      wi.y = (gdispGetHeight()/16)*15;;
      wi.width = gdispGetWidth();
      wi.height = (gdispGetHeight()/16);

      gc = gwinConsoleCreate(0, &wi);

    }

  gwinGraphSetOrigin(gh, 0, 0);
  gwinGraphSetStyle(gh, &GraphLine);

  gwinClear(gc);
  gwinPrintf(gc, "System Ready \n");
  gwinGraphStartSet(gh);
  gwinGraphDrawAxis(gh);

#if DRAW_MODE==0
    uint16_t    i;

    gwinGraphStartSet(gh);
    gwinGraphDrawAxis(gh);

    for(i = 0; i < gwinGetWidth(gh)*5*2; i++) {
        gwinGraphDrawPoint(gh, i/5-gwinGetWidth(gh)/2, 20*sin(2*0.8*GFX_PI*i/180));
    }
    while(1);
#endif

#if DRAW_MODE==1

    while (true) {
        gui_routine();
    }
#endif

}

/*===========================================================================*/
/* INIT PART                                                                 */
/*===========================================================================*/

/**
 * @brief   Start GUI routine
 */
void start_routine(void){
    palSetPadMode(GPIOE, 5,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE, 5);

    gdispSetOrientation(GDISP_ROTATE_90);

    chThdCreateStatic(waDraw, sizeof(waDraw),	NORMALPRIO, thdDraw, NULL);
    chThdCreateStatic(waPlay, sizeof(waPlay),	NORMALPRIO, thdPlay, NULL);
}

/** @} */
