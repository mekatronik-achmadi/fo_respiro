/*
 * http://en.radzio.dxp.pl/ks0108/
 */

#include "glcd_font.h"
#include "glcd_ks0108.h"
#include "glcd_stm32chibios.h"

GlcdStream myGLCD;

static msg_t put(void *ip, uint8_t chr) {
    (void)ip;
    GLCD_WriteChar(chr);
    return MSG_OK;
}

static const struct GlcdStreamVMT vmt = {NULL, NULL, put, NULL};
void lsObjectInit(GlcdStream *msp) {
    msp->vmt = &vmt;
}

unsigned char screen_x = 0, screen_y = 0;

void GLCD_Initalize(void)
{
    unsigned char i;
    GLCD_InitalizePorts();
    for(i = 0; i < 3; i++)
      GLCD_WriteCommand((DISPLAY_ON_CMD | ON), i);
}

void GLCD_GoTo(unsigned char x, unsigned char y)
{
    unsigned char i;
    screen_x = x;
    screen_y = y;

    for(i = 0; i < KS0108_SCREEN_WIDTH/64; i++)
    {
      GLCD_WriteCommand(DISPLAY_SET_Y | 0,i);
      GLCD_WriteCommand(DISPLAY_SET_X | y,i);
      GLCD_WriteCommand(DISPLAY_START_LINE | 0,i);
    }
    GLCD_WriteCommand(DISPLAY_SET_Y | (x % 64), (x / 64));
    GLCD_WriteCommand(DISPLAY_SET_X | y, (x / 64));
}

void GLCD_ClearScreen(void)
{
    unsigned char i, j;
    for(j = 0; j < KS0108_SCREEN_HEIGHT/8; j++)
      {
      GLCD_GoTo(0,j);
      for(i = 0; i < KS0108_SCREEN_WIDTH; i++)
        GLCD_WriteData(0x00);
      }
}

void GLCD_WriteChar(char charToWrite)
{
    int i;
    charToWrite -= 32;
    for(i = 0; i < 5; i++)
      GLCD_WriteData(GLCD_ReadByteFromROMMemory((char *)((int)font5x8 + (5 * charToWrite) + i)));
    GLCD_WriteData(0x00);
}

void GLCD_WriteString(char * stringToWrite)
{
    while(*stringToWrite)
      GLCD_WriteChar(*stringToWrite++);
}

void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char pixel)
{
    unsigned char tmp = 0;

#if KS0108_NEED_READ
    GLCD_GoTo(x, (y / 8));
    tmp = GLCD_ReadData();
    GLCD_GoTo(x, (y / 8));
    tmp = GLCD_ReadData();
#endif
    GLCD_GoTo(x, y/8);
    if(pixel)
        tmp |= (1 << (y%8));
    else
        tmp &= ~(1 << (y%8));
    GLCD_WriteData(tmp);
}

void GLCD_Bitmap(char * bmp, unsigned char x, unsigned char y, unsigned char dx, unsigned char dy)
{
    unsigned char i, j;
    for(j = 0; j < dy / 8; j++)
    {
      GLCD_GoTo(x,y + j);
      for(i = 0; i < dx; i++)
        GLCD_WriteData(GLCD_ReadByteFromROMMemory(bmp++));
    }
}
