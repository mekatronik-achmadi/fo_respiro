/**
 * @file    fo_exti.h
 * @brief   GPIO interface handling header
 *
 * @addtogroup GPIO
 * @{
 */

#ifndef FO_EXTI_H
#define FO_EXTI_H

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

#define PAUSE_STATE 0
#define RUN_STATE   1

void start_exti(void);

#endif // FO_EXTI_H

/** @} */
