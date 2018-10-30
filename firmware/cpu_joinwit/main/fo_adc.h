/**
 * @file    fo_adc.h
 * @brief   ADC Handler.
 *
 * @addtogroup ADC
 * @{
 */

#ifndef FO_ADC_H
#define FO_ADC_H

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/**
 * @brief   define ADC channel.
 */
#define ADC_GRP1_NUM_CHANNELS   1


/**
 * @brief   define ADC matrix depth.
 */
#define ADC_GRP1_BUF_DEPTH      100

void start_adc(void);

#endif // FO_ADC_H

/** @} */
