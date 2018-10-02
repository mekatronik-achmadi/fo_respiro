#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

static THD_WORKING_AREA(waLed1, 128);
static THD_FUNCTION(thdLed1, arg) {

  (void)arg;
  chRegSetThreadName("led1");
  while (true) {
    palClearPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOE, 5);
    chThdSleepMilliseconds(500);
  }
}

/*===========================================================================*/
/* GRAPH PART                                                                */
/*===========================================================================*/

#define N_DATA 200
#define DISP_DELAY 500
#define PLAY_DELAY 500
#define LEFT_TO_RIGHT false
static point vdata[N_DATA];

static THD_WORKING_AREA(waGenData, 128);
static THD_FUNCTION(thdGenData, arg) {

  (void)arg;
  u_int8_t n_rnd;
  u_int16_t i;

  chRegSetThreadName("dataupdate");

  for(i=0;i<N_DATA;i++){
     vdata[i].x = 2*i;
     vdata[i].y = 0;
  }

#if LEFT_TO_RIGHT
  while (true) {
    for(i=0;i<N_DATA-1;i++){
        vdata[i].y = vdata[i+1].y;
    }

    n_rnd = rand() % 10;
    vdata[N_DATA-1].y = 10 * n_rnd;
#else
  while (true) {
    for(i=N_DATA-1;i>0;i--){
        vdata[i].y = vdata[i-1].y;
    }

    n_rnd = rand() % 10;

    vdata[0].y = 10 * n_rnd;
#endif

    gfxSleepMilliseconds(50);
  }
}

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

#define DURATION 10
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

static THD_WORKING_AREA(waDraw, 256);
static THD_FUNCTION(thdDraw, arg) {

    GHandle     gh,gc;
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
      wi.height = gdispGetHeight()/2;
      gh = gwinGraphCreate(&g, &wi);

      wi.x = 0;
      wi.y = gdispGetHeight()/2;;
      wi.width = gdispGetWidth();
      wi.height = gdispGetHeight()/2;

      gc = gwinConsoleCreate(0, &wi);

    }

  gwinGraphSetOrigin(gh, 0, 0);
  gwinGraphSetStyle(gh, &GraphLine);

  gwinClear(gc);
  gwinPrintf(gc, "System ready \n");

/*
    uint16_t    i;

    gwinGraphStartSet(gh);
    gwinGraphDrawAxis(gh);

    for(i = 0; i < gwinGetWidth(gh)*5*2; i++) {
        gwinGraphDrawPoint(gh, i/5-gwinGetWidth(gh)/2, 20*sin(2*0.8*GFX_PI*i/180));
    }
    while(1);
*/

/*
    uint16_t    i;
    while(true){
        for(i = 0; i < N_DATA; i++) {
            gwinGraphDrawPoint(gh, vdata[i].x, vdata[i].y);
        }
    }
*/


  gwinPrintf(gc, "Function: Random Number \n");
  while (true) {

    gwinGraphStartSet(gh);
    gwinGraphDrawAxis(gh);
    gwinGraphDrawPoints(gh, vdata, sizeof(vdata)/sizeof(vdata[0]));

    gfxSleepMilliseconds(DISP_DELAY);
    gwinClear(gh);
  }


/*
  while(true){
        if(palReadPad(GPIOC,0)){
            if(play_stt == 0){
                play_stt = 1;
                play_dur = 0;

                gwinPrintf(gc, "Function: Random Number \n");
                gwinPrintf(gc, "Start to Play \n");
            }
        }

        gwinClear(gh);
        if(play_stt == 1){

            gwinGraphStartSet(gh);
            gwinGraphDrawAxis(gh);
            gwinGraphDrawPoints(gh, vdata, sizeof(vdata)/sizeof(vdata[0]));
        }

        if(play_dur >= DURATION){
            if(play_stt == 1){
                play_stt = 0;
                gwinPrintf(gc, "Playing is over \n");
            }
        }

        gfxSleepMilliseconds(DISP_DELAY);
  }
*/

}

int main(void) {

    // ================================================================== //

    // Initialize and clear the display
    gfxInit();

    //rotate display
    gdispSetOrientation(gOrientation90);

    // ================================================================== //

    palSetPadMode(GPIOE,5,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOC, 0,PAL_MODE_INPUT_PULLDOWN);

    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);

    // Draw a sine wave
    chThdCreateStatic(waGenData, sizeof(waGenData),	NORMALPRIO, thdGenData, NULL);
    chThdCreateStatic(waDraw, sizeof(waDraw),	NORMALPRIO, thdDraw, NULL);
    chThdCreateStatic(waPlay, sizeof(waPlay),	NORMALPRIO, thdPlay, NULL);

    // ================================================================== //

    while(true) {
        gfxSleepMilliseconds(500);
    }
}
