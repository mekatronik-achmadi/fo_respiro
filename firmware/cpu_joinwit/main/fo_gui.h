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

#define N_DATA 200
#define DISP_DELAY 500
#define PLAY_DELAY 500
#define LEFT_TO_RIGHT false
#define DURATION 50

#define DRAW_MODE   1
#define DATA_SRC    1

#if DATA_SRC==0
    #define DATA_SCALE  15
#elif DATA_SRC==1
    #define DATA_SCALE 0.05 // (200/4095)
#endif

void start_routine(void);

#endif // FO_GUI_H
