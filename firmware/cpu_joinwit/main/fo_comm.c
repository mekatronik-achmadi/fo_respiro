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
extern uint16_t rdata[R_DATA];
extern uint16_t rdata_cnt;
extern uint8_t rdata_ful;
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
        for(i=0;i<N_DATA;i++){chprintf(chp,"%i,%4i;",i,pdata[i]);chThdSleepMilliseconds(50);}
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


/**
 * @brief   Command routine to get real data array.
 */
static void cmd_real(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;
    uint16_t i;

    if(argc!=0){chprintf(chp,"usage: real\r\n");}

    if(run_mode==RUN_STATE){chprintf(chp,"Please pause to get real data snapshot\r\n");}
    else{
        chprintf(chp,"[ ");
        for(i=0;i<R_DATA;i++){chprintf(chp,"i,%4i ",i,rdata[i]);chThdSleepMilliseconds(50);}
        chprintf(chp,"]\r\n");
    }

    return;
}

/**
 * @brief   Command routine to get real data array.
 */
static void cmd_clear(BaseSequentialStream *chp, int argc, char *argv[]){
    (void) argv;
    (void) argc;

    if(argc!=0){chprintf(chp,"usage: clr\r\n");}

    if(run_mode==RUN_STATE){chprintf(chp,"Please pause to clr real data snapshot\r\n");}
    else{
        real_zeroing();
        rdata_cnt = 0;
        rdata_ful = 0;
        chprintf(chp,"Real data array cleared\r\n");
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
  {"real",cmd_real},
  {"clr",cmd_clear},
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
