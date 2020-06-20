#include "ch.h"
#include "hal.h"

static THD_WORKING_AREA(waLED, 128);
static THD_FUNCTION(thdLED, arg) {

    (void)arg;

    chRegSetThreadName("blinker");
    while (true) {
        palTogglePad(GPIOC,13);
        chThdSleepMilliseconds(100);
    }
}

int main(void) {

  halInit();
  chSysInit();
  
  palSetPadMode(GPIOA,0,PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOA,0);

  palSetPadMode(GPIOC,13,PAL_MODE_OUTPUT_PUSHPULL);
  palClearPad(GPIOC,13);
  chThdCreateStatic(waLED, sizeof(waLED), NORMALPRIO, thdLED, NULL);

  while(true){
    palTogglePad(GPIOA,0);
    chThdSleepMilliseconds(500);
  }
}
