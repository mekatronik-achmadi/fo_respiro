#include "fo_gui.h"
#include "fo_adc.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern adcsample_t adc0;

/*===========================================================================*/
/* RANDOM DATA PART                                                          */
/*===========================================================================*/
point vdata[N_DATA];

static void zeroing(void){
    u_int16_t i;

    for(i=0;i<N_DATA;i++){
       vdata[i].x = 2*i;
       vdata[i].y = 0;
    }
}

static THD_WORKING_AREA(waGenData, 128);
static THD_FUNCTION(thdGenData, arg) {

  (void)arg;
#if DATA_SRC==0
  u_int8_t n_value;
#endif

  u_int16_t i;

  chRegSetThreadName("dataupdate");

  zeroing();

#if LEFT_TO_RIGHT
  while (true) {
    for(i=0;i<N_DATA-1;i++){
        vdata[i].y = vdata[i+1].y;
    }

 #if DATA_SRC==0
    n_value = rand() % 10;
    vdata[N_DATA-1].y = DATA_SCALE * n_value;
 #elif DATA_SRC==1
    vdata[N_DATA-1].y = DATA_SCALE * adc0;
 #endif


#else
  while (true) {
    for(i=N_DATA-1;i>0;i--){
        vdata[i].y = vdata[i-1].y;
    }

 #if DATA_SRC==0
   n_value = rand() % 10;
   vdata[0].y = DATA_SCALE * n_value;
 #elif DATA_SRC==1
   vdata[0].y = DATA_SCALE * adc0;
 #endif


#endif

    gfxSleepMilliseconds(50);
  }
}

/*===========================================================================*/
/* GRAPH PART                                                                */
/*===========================================================================*/

static GGraphObject g;

static GGraphStyle GraphLine = {
    { GGRAPH_POINT_DOT, 10, White },          // Point
    { GGRAPH_LINE_SOLID, 10, White },          // Line
    { GGRAPH_LINE_SOLID, 0, Gray },        // X axis
    { GGRAPH_LINE_SOLID, 0, Gray },        // Y axis
    { GGRAPH_LINE_DOT, 5, Gray, 50 },      // X grid
    { GGRAPH_LINE_DOT, 5, Gray, 50 },     // Y grid
    GWIN_GRAPH_STYLE_POSITIVE_AXIS_ARROWS   // Flags
};

u_int8_t play_stt;
u_int16_t play_dur;

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
GHandle     gh,gc;
char txt_adc0[16];

static void gui_routine(void){
    gwinGraphStartSet(gh);
    gwinGraphDrawAxis(gh);
    gwinGraphDrawPoints(gh, vdata, sizeof(vdata)/sizeof(vdata[0]));

    chsnprintf(txt_adc0,16,"ADC0= %4i |",adc0);
    gwinPrintf(gc, txt_adc0);
    chsnprintf(txt_adc0,16," Y0= %4i\n",vdata[0].y);
    gwinPrintf(gc, txt_adc0);

    gfxSleepMilliseconds(DISP_DELAY);
    gwinClear(gh);
    gwinClear(gc);
    palTogglePad(GPIOE,5);
}

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

#if DRAW_MODE==2
  while(true){
        if(!palReadPad(GPIOC,0)){
            if(play_stt == 0){
                zeroing();

                play_stt = 1;
                play_dur = 0;

                palSetPad(GPIOE,5);
            }
        }


        if(play_stt == 1){
            gui_routine();
        }

        if(play_dur >= DURATION){
            if(play_stt == 1){
                play_stt = 0;
                gwinPrintf(gc, "System Ready \n");

                gwinClear(gh);
                gwinGraphStartSet(gh);
                gwinGraphDrawAxis(gh);

                palSetPad(GPIOE,5);
            }
        }

        gfxSleepMilliseconds(DISP_DELAY);
  }
#endif

}

/*===========================================================================*/
/* INIT PART                                                                 */
/*===========================================================================*/

void start_routine(void){
    palSetPadMode(GPIOC, 0,PAL_MODE_INPUT_PULLUP);
    palSetPadMode(GPIOE, 5,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE, 5);

    gdispSetOrientation(gOrientation90);

    chThdCreateStatic(waGenData, sizeof(waGenData),	NORMALPRIO, thdGenData, NULL);
    chThdCreateStatic(waDraw, sizeof(waDraw),	NORMALPRIO, thdDraw, NULL);
    chThdCreateStatic(waPlay, sizeof(waPlay),	NORMALPRIO, thdPlay, NULL);
}
