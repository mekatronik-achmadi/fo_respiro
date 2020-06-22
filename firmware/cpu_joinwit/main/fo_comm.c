/**
 * @file    fo_comm.c
 * @brief   Serial shell code
 *
 * @addtogroup SHELL
 * @{
 */

#include "fo_comm.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern uint16_t pdata[N_DATA];
extern uint8_t run_mode;

/*===========================================================================*/
/* SHELL ROUTINE                                                             */
/*===========================================================================*/

/**
 * @brief   Command routine to test serial data.
 */
static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    if(argc!=0){chprintf(chp,"usage: test\r\n");}

    chprintf(chp,"serial ok \r\n");
    return;
}

/**
 * @brief   Command routine to get data array.
 */
static void cmd_data(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;
    uint16_t i;

    if(argc!=0){chprintf(chp,"usage: data\r\n");}

    if(run_mode==RUN_STATE){chprintf(chp,"Please pause to get data snapshot\r\n");}
    else{
        chprintf(chp,"[ ");
        for(i=0;i<N_DATA;i++){chprintf(chp,"%3i ",pdata[i]);}
        chprintf(chp,"]\r\n");
    }

    return;
}

/**
 * @brief   Command routine to run the measurement.
 */
static void cmd_run(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    if(argc!=0){chprintf(chp,"usage: run\r\n");}

    if(run_mode==RUN_STATE){
        chprintf(chp,"data process already run\r\n");
    }
    else{
        run_mode=RUN_STATE;
        chprintf(chp,"data process started\r\n");
    }

    return;
}

/**
 * @brief   Command routine to pause the measurement.
 */
static void cmd_stop(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    if(argc!=0){chprintf(chp,"usage: stop\r\n");}

    if(run_mode==PAUSE_STATE){
        chprintf(chp,"data process already paused\r\n");
    }
    else{
        run_mode=PAUSE_STATE;
        chprintf(chp,"data process stopped\r\n");
    }

    return;
}

/*===========================================================================*/
/* SERIAL ROUTINE                                                            */
/*===========================================================================*/

/**
 * @brief   shell object.
 */
thread_t *shelltp = NULL;

/**
 * @brief   Shell command enumeration.
 */
static const ShellCommand commands[] = {
  {"test",cmd_test},
  {"data",cmd_data},
  {"run",cmd_run},
  {"stop",cmd_stop},
  {NULL, NULL}
};

/**
 * @brief   Configure shell to using serial UART-3.
 */
static const ShellConfig shell_cfg = {
  (BaseSequentialStream *)&SD1,
  commands
};

/**
 * @brief   Start serial bluetooth.
 */
void start_comm(void){
    palSetPadMode(GPIOA,9,PAL_MODE_STM32_ALTERNATE_PUSHPULL);
    palSetPadMode(GPIOA,10,PAL_MODE_INPUT);
    sdStart(&SD1,NULL);
    shellInit();
}

/**
 * @brief   Start shell for bluetooth.
 */
void shell_comm(void){
    if (!shelltp)
      shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);
      shelltp = NULL;
    }
}

/** @} */
