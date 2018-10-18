#ifndef FO_GUI_H
#define FO_GUI_H

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "fo_adc.h"
#include "fo_data.h"

#define DISP_DELAY 500
#define PLAY_DELAY 500
#define DURATION 50
#define DRAW_MODE   1

void start_routine(void);

#endif // FO_GUI_H
