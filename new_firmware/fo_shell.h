#ifndef FO_SHELL_H
#define FO_SHELL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "memstreams.h"
#include "chstreams.h"
#include "shell.h"

#include "fo_uart.h"

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
#define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)

void FO_Shell_Init(void);
void FO_Shell_Run(void);

#endif // FO_SHELL_H
