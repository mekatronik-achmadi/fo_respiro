#include "fo_bt.h"
#include "fo_adc.h"
#include "fo_gui.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern adcsample_t adc0;
extern point vdata[N_DATA];

/*===========================================================================*/
/* SHELL ROUTINE                                                             */
/*===========================================================================*/

static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    chprintf(chp,"serial ok \n\r");
    return;
}

static void cmd_adc0(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    chprintf(chp,"data,%4i,%4i\n\r",adc0,vdata[0].y);
    return;
}

/*===========================================================================*/
/* SERIAL ROUTINE                                                            */
/*===========================================================================*/

thread_t *shelltp = NULL;

static const ShellCommand commands[] = {
  {"test",cmd_test},
  {"adc0",cmd_adc0},
  {NULL, NULL}
};

static const ShellConfig shell_cfg = {
  (BaseSequentialStream *)&SD3,
  commands
};

void start_bt(void){
    palSetPadMode(GPIOB,10,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOB,11,PAL_MODE_INPUT);
    sdStart(&SD3,NULL);
    shellInit();
}

void shell_bt(void){
    if (!shelltp)
      shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);
      shelltp = NULL;
    }
}
