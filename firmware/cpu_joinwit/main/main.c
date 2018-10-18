#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "fo_gui.h"
#include "fo_adc.h"
#include "fo_bt.h"
#include "fo_data.h"

int main(void) {

    gfxInit();

    start_adc();
    start_bt();
    start_data();
    start_routine();

    while(true) {
        shell_bt();
        gfxSleepMilliseconds(500);
    }
}
