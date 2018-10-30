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
#if !defined(ADC_GRP1_NUM_CHANNELS) || defined(__DOXYGEN__)
#define ADC_GRP1_NUM_CHANNELS   1
#endif

/**
 * @brief   define ADC matrix depth.
 */
#if !defined(#define ADC_GRP1_BUF_DEPTH) || defined(__DOXYGEN__)
#define ADC_GRP1_BUF_DEPTH      100
#endif

/**
 * @brief   Starting ADC routine.
 */
void start_adc(void);

#endif // FO_ADC_H
