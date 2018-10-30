/**
 * @file    fo_data.h
 * @brief   Data handling.
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
 * @brief   data calibration function.
 *
 * @param[in] vadc		input 16-bit variable from ADC.
 * @return              16-bit integer calibrated value.
 *
 */
u_int16_t data_calib(u_int16_t vadc){
    return C_CALIB*vadc;
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
      vdata[0].y = DATA_SCALE * adc0;
#endif

      gfxSleepMilliseconds(50);
  }
}

/**
 * @brief   Starting Data routine.
 *
 */
void start_data(void){
    chThdCreateStatic(waGenData, sizeof(waGenData),	NORMALPRIO, thdGenData, NULL);
}

/** @} */
