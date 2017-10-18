#include "fo_gui.h"
#include "logolab.h"

extern uint16_t data_array[X_LENGTH];

void GUI_StartupLogo(void){
    GLCD_Bitmap(LogoLab,0,0,100,52);
    GLCD_GoTo(0,6);
    GLCD_WriteString("|  by Photonic Labs |");

    chThdSleepMilliseconds(2000);
}

void GUI_DataText(uint16_t v_adc, uint8_t v_rate){
    char str_data[20];
    chsnprintf(str_data,20,"Rate= %2i | %4i",v_rate,v_adc);
    GLCD_GoTo(0,7);
    GLCD_WriteString(str_data);
}

void GUI_Graph(void){
    uint8_t x_val,y_val,y_draw;

    for(x_val=0;x_val<X_LENGTH;x_val++){
        y_val = (uint8_t) data_array[x_val]*Y_CONST;
        y_draw = Y_LENGTH + Y_OFFSET - y_val;

        GLCD_SetPixel(x_val,y_draw,1);
    }
}
