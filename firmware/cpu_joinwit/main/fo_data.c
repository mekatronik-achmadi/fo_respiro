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
extern uint8_t run_mode;

/**
 * @brief Current Value as difference between ADC.0 and C_OFFSET
 * @pre @p C_OFFSET must suitable for experiment setup
 */
adcsample_t vcurr;

/**
 * @brief Previous Value as Current Value at on step behind
 */
adcsample_t vprev;

/**
 * @brief Difference between Current and Previous Value
 */
adcsample_t dval=0;

/**
 * @brief Timer Period between two @p dval value that more than @p C_DVAL
 * @pre @p C_DVAL must suitable for experiment setup
 */
icucnt_t Tchange;

/**
 * @brief Counter on reset thread
 * @details Make sure it is not too fast and not too slow
 */
icucnt_t Tcount;

/*===========================================================================*/
/* GENERATE DATA PART                                                        */
/*===========================================================================*/

/**
 * @brief   data point array for display.
 */
point vdata[N_DATA];

/**
 * @brief   data point array as 16bit integer
 */
uint16_t pdata[N_DATA];

/**
 * @brief   data array for actual power analysis
 */
uint16_t rdata[R_DATA];

/**
 * @brief   actual power analysis data counter
 */
uint16_t rdata_cnt=0;

/**
 * @brief   actual power analysis data full status
 */
uint8_t rdata_ful=0;

/**
 * @brief   set data array to zero.
 *
 */
void data_zeroing(void){
    u_int16_t i;

    for(i=0;i<N_DATA;i++){
       vdata[i].x = i;
       vdata[i].y = 0;
       pdata[i] = 0;
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
        pdata[i] = pdata[i+1];
    }
#else
    for(i=N_DATA-1;i>0;i--){
        vdata[i].y = vdata[i-1].y;
        pdata[i] = pdata[i-1];
    }
#endif
}

/**
 * @brief set actual power data array to zero
 */
void real_zeroing(void){
     u_int16_t i;

     for(i=0;i<R_DATA;i++){
        rdata[i] = 0;
     }
}

/**
 * @brief shift actual power data array
 */
void real_shifting(void){
     u_int16_t i;

     for(i=R_DATA-1;i>0;i--){
         rdata[i] = rdata[i-1];
     }

     if(rdata_ful==0){
         if(rdata_cnt<=R_DATA){
            rdata_cnt++;
         }
         else{
            rdata_ful = 1;
         }
     }
}

/**
 * @brief   main data processing
 * @details PC.7 set HIGH here to read by Input-Capture
 * @pre     @p C_DVAL and C_OFFSET must suitable for experiment setup
 * @pre     @p LEFT_TO_RIGHT must defined.
 *
 */
void data_process(void){
    data_shifting();
    real_shifting();

    vprev = vcurr;
    vcurr = adc0;

    rdata[0] = vcurr;

    if(vcurr>=vprev){dval = vcurr-vprev;}
    else if(vcurr<vprev){dval = vprev-vcurr;}

    if(dval>C_DVAL){
        Tcount = 0;
        palSetPad(GPIOC,7);
    }

#if LEFT_TO_RIGHT
   vdata[N_DATA-1].y = DATA_SCALE * dval;
   pdata[N_DATA-1] = DATA_SCALE * dval;
#else
    vdata[0].y = DATA_SCALE * dval;
    pdata[0] = DATA_SCALE * dval;
#endif
}

/**
 * @brief Timer Interrupt callback
 * @details Main Data Process run here
 * @details Test on Timer (emulate PWM) and Input-Capture
 */
static void gptcb(GPTDriver *gptp) {
  (void)gptp;

#if TEST_GPT_ICU
  palTogglePad(GPIOC,7);
#endif

  if(run_mode==RUN_STATE)data_process();
}

/**
 * @brief Timer Interrupt Config
 */
static const GPTConfig gptcfg = {
  10000,    /* 10kHz timer clock.*/
  gptcb,   /* Timer callback.*/
  0,
  0
};

static THD_WORKING_AREA(waChange, 128);
#define ThdFunc_FreqReset THD_FUNCTION

/**
 * @brief   Frequency reset thread here.
 * @details PC.7 cleared to LOW here
 * @details Delay sleep in ms is precise but not accurate
 */
static ThdFunc_FreqReset(thdChange, arg) {

    (void)arg;

    chRegSetThreadName("frequencyoverflow");
    Tcount = 0;
    Tchange = 0;

    while(1){
        Tcount++;

        if(Tcount==50){
            Tcount = 0;
            Tchange = 0;
            palTogglePad(GPIOE,6);
            palClearPad(GPIOC,7);
        }

        gfxSleepMilliseconds(1);
    }

}

/**
 * @brief Input-Capture Interrupt Callback
 * @details Frequency of change defined here
 * @details PC.7 cleared to LOW here
 */
static void icuperiodcb(ICUDriver *icup) {
  Tchange = icuGetPeriodX(icup);
  palClearPad(GPIOC,7);
  Tcount = 0;
}

/**
 * @brief Input-Capture Config
 */
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
    gptStartContinuous(&GPTD4,5000);

    data_zeroing();
    real_zeroing();
    chThdCreateStatic(waChange, sizeof(waChange),	NORMALPRIO, thdChange, NULL);
}

/** @} */
