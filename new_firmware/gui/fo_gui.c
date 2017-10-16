#include "fo_gui.h"
#include "logolab.h"

void GUI_StartupLogo(void){
    GLCD_Bitmap(LogoLab,0,0,100,52);
    GLCD_GoTo(0,6);
    GLCD_WriteString("|  by Photonic Labs |");

    chThdSleepMilliseconds(2000);
}

void GUI_Frame(void){
    GLCD_Rectangle(0,1,128,44);
}

void GUI_DataText(uint16_t v_adc, uint8_t v_rate){
    char str_data[20];
    chsnprintf(str_data,20,"Rate= %2i | %4i",v_rate,v_adc);
    GLCD_GoTo(0,7);
    GLCD_WriteString(str_data);
}
