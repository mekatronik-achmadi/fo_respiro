#include "ch.h"
#include "hal.h"

#include "fo_uart.h"
#include "fo_shell.h"
#include "fo_gui.h"
#include "fo_adc.h"

extern adcsample_t adc0;
uint8_t val_rate=0;

static THD_WORKING_AREA(wa_glcdThread, 128);
static THD_FUNCTION(glcdThread, arg) {
  (void)arg;
  chRegSetThreadName("GLCD Update");
  while (TRUE) {
    chThdSleepMilliseconds(500);
    GUI_Clear();
//    GUI_PlotADC(adc0);
//    GUI_GraphTest(0);
    GUI_DataText(adc0,val_rate);
    chprintf((BaseSequentialStream *)&SD1,"%4i \n\r",adc0);
  }
}

int main(void) {

  halInit();
  chSysInit();

  GUI_Start();
  GUI_Clear();

  GUI_StartupLogo();

  FO_Shell_Init();
  FO_Adc_Init();

  GUI_Clear();
  chThdCreateStatic(wa_glcdThread, sizeof(wa_glcdThread), NORMALPRIO, glcdThread, NULL);

  while (true) {
      FO_Shell_Run();
  }
}
