#ifndef FO_GUI_H
#define FO_GUI_H

#include "ch.h"
#include "hal.h"
#include "chprintf.h"

#include "glcd_font.h"
#include "glcd_draw.h"
#include "glcd_ks0108.h"
#include "glcd_stm32chibios.h"

#define GUI_Start GLCD_Initalize
#define GUI_Clear GLCD_ClearScreen
#define GUI_TestString GLCD_TestString
#define GUI_TestStrData GLCD_TestStrData

#define GUI_Rectangle GLCD_Rectangle
#define GUI_Circle GLCD_Circle
#define GUI_Line GLCD_Line
#define GUI_TestDraw GLCD_TestDraw

void GUI_StartupLogo(void);
void GUI_Frame(void);
void GUI_DataText(uint16_t v_adc,uint8_t v_rate);

#endif // FO_GUI_H
