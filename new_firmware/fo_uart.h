#ifndef FO_UART_H
#define FO_UART_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "memstreams.h"
#include "chstreams.h"

void FO_Uart_Init(void);
void FO_Uart_Test(void);

#endif // FO_UART_H
