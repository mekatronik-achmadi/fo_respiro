#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"

#include "glcd_ks0108.h"
#include "logolab.h"

int main(void) {

  halInit();
  chSysInit();

  GLCD_Initalize();
  GLCD_ClearScreen();

  GLCD_Bitmap(LogoLab,0,0,100,52);
  GLCD_GoTo(0,6);
  GLCD_WriteString("|  by Photonic Labs |");

  FO_Shell_Init();

  while (true) {
      FO_Shell_Run();
  }
}
