#ifndef FO_ADC_H
#define FO_ADC_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "memstreams.h"

#include "fo_gui.h"

#if !defined(CHPRINTF_USE_FLOAT) || defined(__DOXYGEN__)
#define CHPRINTF_USE_FLOAT          FALSE
#endif
#define MAX_FILLER 16
#define FLOAT_PRECISION 10

#define ADC_GRP_NUM_CHANNELS   1
#define ADC_GRP_BUF_DEPTH      100

#define MAX_ADC 400
#define OFF_ADC 460

void FO_Adc_Init(void);
void FO_Data_Shift(adcsample_t v_input);

#endif // FO_ADC_H
