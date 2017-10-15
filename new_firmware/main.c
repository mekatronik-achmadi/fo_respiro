#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"

int main(void) {

  halInit();
  chSysInit();

  FO_Shell_Init();

  while (true) {
      FO_Shell_Run();
  }
}
