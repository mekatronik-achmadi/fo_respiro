/**
 * @file    fo_comm.h
 * @brief   Serial shell header
 *
 * @addtogroup SHELL
 * @{
 */

#ifndef FO_COMM_H
#define FO_COMM_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "shell.h"
#include "memstreams.h"

#include "fo_data.h"
#include "fo_exti.h"

/**
 * @brief   Main Shell working area size .
 */
#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(512)

void start_comm(void);
void shell_comm(void);

#endif // FO_COMM_H
/** @} */
