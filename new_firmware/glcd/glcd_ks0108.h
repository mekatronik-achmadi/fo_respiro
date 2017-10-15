#ifndef GLCD_KS0108_H
#define GLCD_KS0108_H

#include "hal.h"

#define KS0108_SCREEN_WIDTH		128
#define KS0108_SCREEN_HEIGHT	64

#define DISPLAY_SET_Y       0x40
#define DISPLAY_SET_X       0xB8
#define DISPLAY_START_LINE  0xC0
#define DISPLAY_ON_CMD		0x3E
  #define ON	0x01
  #define OFF	0x00
#define DISPLAY_STATUS_BUSY	0x80
#define KS0108_NOP_DLY      FALSE

#define DISPLAY_STATUS_BUSY	0x80
#define KS0108_READ_STATUS  FALSE

void GLCD_Initalize(void);
void GLCD_ClearScreen(void);
void GLCD_GoTo(unsigned char x, unsigned char y);
void GLCD_WriteString(char * stringToWrite);
unsigned char GLCD_ReadData(void);
void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char color);
void GLCD_Bitmap(char * bmp, unsigned char x, unsigned char y, unsigned char dx, unsigned char dy);
void GLCD_TestString(void);

#endif // GLCD_KS0108_H
