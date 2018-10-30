/**
 * @file    fo_data.h
 * @brief   Data handling.
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
 * @brief   define total data point for display.
 */
#define N_DATA 320

/**
 * @brief   define data array movement direction.
 */
#define LEFT_TO_RIGHT false

/**
 * @brief   define data scaling for display.
 */
#define DATA_SCALE 0.05 // (200/4095)

/**
 * @brief   define calibration factor.
 */
#define C_CALIB 0.2

void data_zeroing(void);
void data_shifting(void);
u_int16_t data_calib(u_int16_t vadc);
void start_data(void);

#endif // FO_DATA_H

/** @} */
