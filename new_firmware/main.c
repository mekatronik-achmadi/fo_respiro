#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"

#include "glcd_ks0108.h"

int main(void) {

  halInit();
  chSysInit();

  GLCD_Initalize();
  GLCD_ClearScreen();

  GLCD_TestString();

//  FO_Shell_Init();

  while (true) {
      chThdSleepMilliseconds(100);
//      FO_Shell_Run();
  }
}
