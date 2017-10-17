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

#define MAX_ADC 4095

#define Y_LENGTH 44
#define Y_OFFSET 2
#define Y_CONST  0.01 // Y_LENGTH/MAX_ADC
#define X_LENGTH 128

void GUI_StartupLogo(void);
void GUI_DataText(uint16_t v_adc,uint8_t v_rate);
void GUI_Graph(void);
void GUI_GraphTest(uint16_t kons_adc);
void GUI_PlotADC(uint16_t v_adc);

#endif // FO_GUI_H
