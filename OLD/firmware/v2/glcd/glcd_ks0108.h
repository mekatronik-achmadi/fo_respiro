#ifndef GLCD_KS0108_H
#define GLCD_KS0108_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "ch.h"
#include "hal.h"
#include "chprintf.h"
#include "memstreams.h"
#include "chstreams.h"

#define _glcd_stream_data _base_sequential_stream_data

struct GlcdStreamVMT {
    _base_sequential_stream_methods
};

typedef struct {
    const struct GlcdStreamVMT *vmt;
    _base_sequential_stream_data
} GlcdStream;

#ifdef __cplusplus
extern "C" {
#endif
void lsObjectInit(GlcdStream *msp);
#ifdef __cplusplus
}
#endif

#define KS0108_SCREEN_WIDTH		128
#define KS0108_SCREEN_HEIGHT	64

#define DISPLAY_SET_Y       0x40
#define DISPLAY_SET_X       0xB8
#define DISPLAY_START_LINE  0xC0
#define DISPLAY_ON_CMD		0x3E
  #define ON	0x01
  #define OFF	0x00
#define DISPLAY_STATUS_BUSY	0x80
#define KS0108_NOP_DLY      TRUE

#define DISPLAY_STATUS_BUSY	0x80
#define KS0108_NEED_READ  FALSE

void GLCD_Initalize(void);
void GLCD_ClearScreen(void);
void GLCD_GoTo(unsigned char x, unsigned char y);
void GLCD_WriteChar(char charToWrite);
void GLCD_WriteString(char * stringToWrite);
void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char pixel);
void GLCD_Bitmap(char * bmp, unsigned char x, unsigned char y, unsigned char dx, unsigned char dy);

#endif // GLCD_KS0108_H
