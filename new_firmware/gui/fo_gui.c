#include "fo_gui.h"
#include "logolab.h"

void GUI_StartupLogo(void){
    GLCD_Bitmap(LogoLab,0,0,100,52);
    GLCD_GoTo(0,6);
    GLCD_WriteString("|  by Photonic Labs |");

    chThdSleepMilliseconds(2000);
}
