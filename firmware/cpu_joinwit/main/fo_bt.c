/**
 * @file    fo_bt.c
 * @brief   Bluetooth shell code
 *
 * @addtogroup SHELL
 * @{
 */

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

/**
 * @brief   Command routine to test serial data.
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    chprintf(chp,"serial ok \n\r");
    return;
}

/**
 * @brief   Command routine to send adc data.
 */
static void cmd_adc0(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    chprintf(chp,"data,%4i,%4i\n\r",adc0,vdata[0].y);
    return;
}

/*===========================================================================*/
/* SERIAL ROUTINE                                                            */
/*===========================================================================*/

/**
 * @brief   shell object.
 */
thread_t *shellbt = NULL;

/**
 * @brief   Shell command enumeration.
 */
static const ShellCommand commandbt[] = {
  {"test",cmd_test},
  {"adc0",cmd_adc0},
  {NULL, NULL}
};

/**
 * @brief   Configure shell to using serial UART-3.
 */
static const ShellConfig shellbt_cfg = {
  (BaseSequentialStream *)&SD3,
  commandbt
};

/**
 * @brief   Start serial bluetooth.
 */
void start_bt(void){
    palSetPadMode(GPIOB,10,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOB,11,PAL_MODE_INPUT);
    sdStart(&SD3,NULL);
    shellInit();
}

/**
 * @brief   Start shell for bluetooth.
 */
void shell_bt(void){
    if (!shellbt)
      shellbt = shellCreate(&shellbt_cfg, SHELL_BT_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shellbt)) {
      chThdRelease(shellbt);
      shellbt = NULL;
    }
}

/** @} */
