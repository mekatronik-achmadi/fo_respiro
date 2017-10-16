#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"
#include "fo_gui.h"

uint16_t val_adc=0;
uint8_t val_rate=0;

int main(void) {

  halInit();
  chSysInit();

  GUI_Start();
  GUI_Clear();

  GUI_StartupLogo();

  FO_Shell_Init();

  GUI_Clear();
  GUI_Frame();
  GUI_DataText(val_adc,val_rate);

  while (true) {
      FO_Shell_Run();
  }
}
