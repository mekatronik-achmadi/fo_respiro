/**
 * @file    fo_data.c
 * @brief   Data handling code
 *
 * @addtogroup DATA
 * @{
 */

#include "fo_data.h"

/*===========================================================================*/
/* IMPORT DATA PART                                                          */
/*===========================================================================*/

extern adcsample_t adc0;

adcsample_t vcurr,vprev,dval;
icucnt_t Tchange, Tcount;

/*===========================================================================*/
/* GENERATE DATA PART                                                        */
/*===========================================================================*/

/**
 * @brief   data point array for display.
 */
point vdata[N_DATA];

/**
 * @brief   set data array to zero.
 *
 */
void data_zeroing(void){
    u_int16_t i;

    for(i=0;i<N_DATA;i++){
       vdata[i].x = i;
       vdata[i].y = 0;
    }
}

/**
 * @brief   set data shifting by 1.
 * @pre     @p LEFT_TO_RIGHT must defined.
 *
 */
void data_shifting(void){
    u_int16_t i;

#if LEFT_TO_RIGHT
    for(i=0;i<N_DATA-1;i++){
        vdata[i].y = vdata[i+1].y;
    }
#else
    for(i=N_DATA-1;i>0;i--){
        vdata[i].y = vdata[i-1].y;
    }
#endif
}


/**
 * @brief   main data processing
 * @pre     @p LEFT_TO_RIGHT must defined.
 *
 */
void data_process(void){
    data_shifting();

#if LEFT_TO_RIGHT
  vdata[N_DATA-1].y = DATA_SCALE * adc0;
  vprev = vcurr;
  vcurr = vdata[N_DATA-1].y;
#else
    vdata[0].y = DATA_SCALE * (adc0-C_OFFSET);
    vprev = vcurr;
    vcurr = vdata[0].y;
#endif

    if(vcurr>=vprev){dval = vcurr-vprev;}
    else if(vcurr<vprev){dval = vprev-vcurr;}

    if(dval>=C_DVAL){
        palClearPad(GPIOE,6);
        palSetPad(GPIOC,7);
    }
}

static void gptcb(GPTDriver *gptp) {
  (void)gptp;
#if TEST_GPT_ICU
  palTogglePad(GPIOC,7);
#endif
  data_process();
}

static const GPTConfig gptcfg = {
  10000,    /* 10kHz timer clock.*/
  gptcb,   /* Timer callback.*/
  0,
  0
};

/**
 * @brief   Changes frequency counter.
 *
 */
static THD_WORKING_AREA(waChange, 128);
static THD_FUNCTION(thdChange, arg) {

    (void)arg;

    chRegSetThreadName("frequencyoverflow");
    Tcount = 0;
    Tchange = 0;

    while(1){
        Tcount++;

        if(Tcount==1000){
            Tcount = 0;
            Tchange = 0;
            palSetPad(GPIOE,6);
            palClearPad(GPIOC,7);
        }

        gfxSleepMicroseconds(100);
    }

}

static void icuperiodcb(ICUDriver *icup) {
  Tchange = icuGetPeriodX(icup);
  palClearPad(GPIOC,7);
  Tcount = 0;
}


static ICUConfig icucfg = {
  ICU_INPUT_ACTIVE_HIGH,
  10000,                                  /* 10kHz ICU clock frequency.   */
  NULL,
  icuperiodcb,
  NULL,
  ICU_CHANNEL_2,
  0
};

/**
 * @brief   Starting Data routine.
 *
 */
void start_data(void){
    palSetPadMode(GPIOE, 6,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE,6);

    palSetPadMode(GPIOC, 7, PAL_MODE_OUTPUT_PUSHPULL);
    palClearPad(GPIOC,7);

    icuStart(&ICUD3, &icucfg);
    palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_PULLDOWN);
    icuStartCapture(&ICUD3);
    icuEnableNotifications(&ICUD3);

    gptStart(&GPTD4, &gptcfg);
    gptStartContinuous(&GPTD4,100);

    data_zeroing();
    chThdCreateStatic(waChange, sizeof(waChange),	NORMALPRIO, thdChange, NULL);
}

/** @} */
