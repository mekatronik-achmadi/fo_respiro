#ifndef GLCD_DRAW_H
#define GLCD_DRAW_H

void GLCD_Rectangle(unsigned char x, unsigned char y, unsigned char b, unsigned char a);
void GLCD_Circle(unsigned char cx, unsigned char cy ,unsigned char radius);
void GLCD_Line(int X1, int Y1,int X2,int Y2);
void GLCD_TestDraw(void);
void GLCD_TestString(void);
void GLCD_TestStrData(void);

#endif // GLCD_DRAW_H
