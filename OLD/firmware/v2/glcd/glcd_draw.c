#include "glcd_draw.h"
#include "glcd_font.h"
#include "glcd_ks0108.h"
#include "glcd_stm32chibios.h"

extern GlcdStream myGLCD;

const unsigned char color = 1;

void GLCD_Rectangle(unsigned char x, unsigned char y, unsigned char b, unsigned char a)
{
  unsigned char j;

  for (j = 0; j < a; j++) {
        GLCD_SetPixel(x, y + j, color);
        GLCD_SetPixel(x + b - 1, y + j, color);
    }

  for (j = 0; j < b; j++)	{
        GLCD_SetPixel(x + j, y, color);
        GLCD_SetPixel(x + j, y + a - 1, color);
    }
}

void GLCD_Circle(unsigned char cx, unsigned char cy ,unsigned char radius)
{
int x, y, xchange, ychange, radiusError;
x = radius;
y = 0;
xchange = 1 - 2 * radius;
ychange = 1;
radiusError = 0;
while(x >= y)
  {
  GLCD_SetPixel(cx+x, cy+y, color);
  GLCD_SetPixel(cx-x, cy+y, color);
  GLCD_SetPixel(cx-x, cy-y, color);
  GLCD_SetPixel(cx+x, cy-y, color);
  GLCD_SetPixel(cx+y, cy+x, color);
  GLCD_SetPixel(cx-y, cy+x, color);
  GLCD_SetPixel(cx-y, cy-x, color);
  GLCD_SetPixel(cx+y, cy-x, color);
  y++;
  radiusError += ychange;
  ychange += 2;
  if ( 2*radiusError + xchange > 0 )
    {
    x--;
    radiusError += xchange;
    xchange += 2;
    }
  }
}

void GLCD_Line(int X1, int Y1,int X2,int Y2)
{
int CurrentX, CurrentY, Xinc, Yinc,
    Dx, Dy, TwoDx, TwoDy,
    TwoDxAccumulatedError, TwoDyAccumulatedError;

Dx = (X2-X1);
Dy = (Y2-Y1);

TwoDx = Dx + Dx;
TwoDy = Dy + Dy;

CurrentX = X1;
CurrentY = Y1;

Xinc = 1;
Yinc = 1;

if(Dx < 0)
  {
  Xinc = -1;
  Dx = -Dx;
  TwoDx = -TwoDx;
  }

if (Dy < 0)
  {
  Yinc = -1;
  Dy = -Dy;
  TwoDy = -TwoDy;
  }

GLCD_SetPixel(X1,Y1, color);

if ((Dx != 0) || (Dy != 0))
  {

  if (Dy <= Dx)
    {
    TwoDxAccumulatedError = 0;
    do
      {
      CurrentX += Xinc;
      TwoDxAccumulatedError += TwoDy;
      if(TwoDxAccumulatedError > Dx)
        {
        CurrentY += Yinc;
        TwoDxAccumulatedError -= TwoDx;
        }
       GLCD_SetPixel(CurrentX,CurrentY, color);
       }while (CurrentX != X2);
     }
   else
      {
      TwoDyAccumulatedError = 0;
      do
        {
        CurrentY += Yinc;
        TwoDyAccumulatedError += TwoDx;
        if(TwoDyAccumulatedError>Dy)
          {
          CurrentX += Xinc;
          TwoDyAccumulatedError -= TwoDy;
          }
         GLCD_SetPixel(CurrentX,CurrentY, color);
         }while (CurrentY != Y2);
    }
  }
}

void GLCD_TestDraw(void){
    GLCD_Circle(64,32,10);
    GLCD_Line(0,0,128,64);
    GLCD_Rectangle(20,40,20,10);
}

void GLCD_TestString(void){
    GLCD_GoTo(0,0);
    GLCD_WriteString("+-------------------+");
    GLCD_GoTo(0,1);
    GLCD_WriteString("|     Universal     |");
    GLCD_GoTo(0,2);
    GLCD_WriteString("|   KS0108 library  |");
    GLCD_GoTo(0,3);
    GLCD_WriteString("|                   |");
    GLCD_GoTo(0,4);
    GLCD_WriteString("|  en.radzio.dxp.pl |");
    GLCD_GoTo(0,5);
    GLCD_WriteString("|  STM32 Cortex-M3  |");
    GLCD_GoTo(0,6);
    GLCD_WriteString("|  microcontrollers |");
    GLCD_GoTo(0,7);
    GLCD_WriteString("+-------------------+");
}

void GLCD_TestStrData(void){
    char str_data[16];
    chsnprintf(str_data,16,"Test");
    GLCD_GoTo(0,0);
    GLCD_WriteString(str_data);
}
