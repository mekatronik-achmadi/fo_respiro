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
 * @brief   data update thread.
 * @pre     @p LEFT_TO_RIGHT must defined.
 *
 */
static THD_WORKING_AREA(waGenData, 128);
static THD_FUNCTION(thdGenData, arg) {

  (void)arg;

  chRegSetThreadName("dataupdate");

  data_zeroing();

  while (true) {
      data_shifting();

#if LEFT_TO_RIGHT
    vdata[N_DATA-1].y = DATA_SCALE * adc0;
#else
      vdata[0].y = DATA_SCALE * (adc0-C_OFFSET);
#endif

      gfxSleepMicroseconds(50);
      palTogglePad(GPIOE,6);
  }
}

/**
 * @brief   Starting Data routine.
 *
 */
void start_data(void){
    palSetPadMode(GPIOE, 6,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOE,6);

    chThdCreateStatic(waGenData, sizeof(waGenData),	NORMALPRIO, thdGenData, NULL);
}

/** @} */
