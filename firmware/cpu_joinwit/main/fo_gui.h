/**
 * @file    fo_gui.h
 * @brief   Display GUI header
 *
 * @addtogroup GUI
 * @{
 */

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

/**
 * @brief   Value of slow refresh delay in ms
 */
#define SLOW_REFRESH_DELAY 10

/**
 * @brief   Either use fast or each @p SLOW_REFRESH_DELAY ms
 */
#define USE_FAST_REFRESH FALSE

/**
 * @brief   Display show duration.
 */
#define DISP_SHOW_DELAY  100

/**
 * @brief   define GUI draw mode:
 *			- 0 :for use test using sine graph
 *			- 1 :for use real routine
 */
#define DRAW_MODE   1

void start_routine(void);

#endif // FO_GUI_H

/** @} */
