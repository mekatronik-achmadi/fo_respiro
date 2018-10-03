#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "fo_gui.h"

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

int main(void) {

    // ================================================================== //

    // Initialize and clear the display
    gfxInit();

    //rotate display
    gdispSetOrientation(gOrientation90);

    // ================================================================== //

    palSetPadMode(GPIOE, 5,PAL_MODE_OUTPUT_PUSHPULL);

    chThdCreateStatic(waLed1, sizeof(waLed1),	NORMALPRIO, thdLed1, NULL);
    start_routine();
    // ================================================================== //

    while(true) {
        gfxSleepMilliseconds(500);
    }
}
