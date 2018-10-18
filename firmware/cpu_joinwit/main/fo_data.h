#ifndef FO_DATA_H
#define FO_DATA_H

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define N_DATA 320
#define LEFT_TO_RIGHT false
#define DATA_SCALE 0.05 // (200/4095)

void data_zeroing(void);
void data_shifting(void);
void start_data(void);

#endif // FO_DATA_H
