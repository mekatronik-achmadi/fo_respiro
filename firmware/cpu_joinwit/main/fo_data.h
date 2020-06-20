/**
 * @file    fo_data.h
 * @brief   Data handling header
 *
 * @addtogroup DATA
 * @{
 */

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

/**
 * @brief define test Timer and Input-Capture
 */
#define TEST_GPT_ICU FALSE

/**
 * @brief   define total data point for display.
 */
#define N_DATA 320

/**
 * @brief   define data array movement direction.
 */
#define LEFT_TO_RIGHT FALSE

/**
 * @brief   define data scaling for display.
 */
#define DATA_SCALE 1 // (200/4095)*20

/**
 * @brief   define minimum value of change
 */
#define C_DVAL  10

void data_zeroing(void);
void data_shifting(void);
void start_data(void);

#endif // FO_DATA_H

/** @} */
