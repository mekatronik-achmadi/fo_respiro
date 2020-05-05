/**
 * @file    fo_bt.h
 * @brief   Bluetooth shell header
 *
 * @addtogroup SHELL
 * @{
 */

#ifndef FO_BT_H
#define FO_BT_H

#include "ch.h"
#include "hal.h"
#include "gfx.h"
#include "chprintf.h"
#include "shell.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "memstreams.h"

/**
 * @brief   Main Shell working area size .
 */
#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(512)

void start_bt(void);
void shell_bt(void);

#endif // FO_BT_H

/** @} */
