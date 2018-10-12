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

#define SHELL_WA_SIZE THD_WORKING_AREA_SIZE(512)

thread_t *shellCreate(const ShellConfig *scp, size_t size, tprio_t prio);

void start_bt(void);
void shell_bt(void);

#endif // FO_BT_H
