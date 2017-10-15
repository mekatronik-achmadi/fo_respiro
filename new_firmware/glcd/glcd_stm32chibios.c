#include "glcd_font.h"
#include "glcd_ks0108.h"

#include "ch.h"
#include "hal.h"

#define KS0108_PORT  GPIOC

#define KS0108_RS    10
#define KS0108_RW    11
#define KS0108_EN    13

#define KS0108_CS1   8
#define KS0108_CS2   9

#define KS0108_D0    0

#define DISPLAY_STATUS_BUSY	0x80

extern unsigned char screen_x;
extern unsigned char screen_y;

void GLCD_Delay(void)
{
#if KS0108_NOP_DLY
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");

        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");

        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");

        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");
        asm("nop");asm("nop");asm("nop");asm("nop");

    #else
        chThdSleepMicroseconds(1);
    #endif
}

void GLCD_EnableController(unsigned char controller)
{
switch(controller){
    case 1 : palClearPad(KS0108_PORT, KS0108_CS1); break;
    case 0 : palClearPad(KS0108_PORT, KS0108_CS2); break;
    }
}

void GLCD_DisableController(unsigned char controller)
{
switch(controller){
    case 1 : palSetPad(KS0108_PORT, KS0108_CS1); break;
    case 0 : palSetPad(KS0108_PORT, KS0108_CS2); break;
    }
}

void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
    palClearPad(KS0108_PORT, KS0108_RS);
    palClearPad(KS0108_PORT, KS0108_RW);

    GLCD_Delay();
    GLCD_EnableController(controller);
    GLCD_Delay();

    palSetPort(KS0108_PORT, (commandToWrite << KS0108_D0));
    commandToWrite ^= 0xFF;
    palClearPort(KS0108_PORT, (commandToWrite << KS0108_D0));


    GLCD_Delay();
    palSetPad(KS0108_PORT, KS0108_EN);
    GLCD_Delay();
    palClearPad(KS0108_PORT, KS0108_EN);
    GLCD_Delay();

    GLCD_DisableController(controller);
}

void GLCD_WriteData(unsigned char dataToWrite)
{

    palClearPad(KS0108_PORT, KS0108_RW);
    GLCD_Delay();
    palSetPad(KS0108_PORT, KS0108_RS);
    GLCD_Delay();

    palSetPort(KS0108_PORT, (dataToWrite << KS0108_D0));
    dataToWrite ^= 0xFF;
    palClearPort(KS0108_PORT, (dataToWrite << KS0108_D0));

    GLCD_Delay();
    GLCD_EnableController(screen_x / 64);
    GLCD_Delay();

    palSetPad(KS0108_PORT, KS0108_EN);
    GLCD_Delay();
    palClearPad(KS0108_PORT, KS0108_EN);

    GLCD_Delay();
    GLCD_DisableController(screen_x / 64);
    screen_x++;
}

void GLCD_InitalizePorts(void)
{
    uint8_t i;
    for(i=0;i<8;i++){
        palSetPadMode(KS0108_PORT,i,PAL_MODE_OUTPUT_PUSHPULL);
    }

    palSetPadMode(KS0108_PORT,KS0108_CS1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(KS0108_PORT,KS0108_CS2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(KS0108_PORT,KS0108_RS,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(KS0108_PORT,KS0108_RW,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(KS0108_PORT,KS0108_EN,PAL_MODE_OUTPUT_PUSHPULL);
}

unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
  return *(ptr);
}
