#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"
#include "fo_gui.h"

int main(void) {

  halInit();
  chSysInit();

  GUI_Start();
  GUI_Clear();

  GUI_StartupLogo();

  FO_Shell_Init();

  GUI_Clear();
  GUI_TestDraw();
//  GUI_TestString();

  while (true) {
      FO_Shell_Run();
  }
}
