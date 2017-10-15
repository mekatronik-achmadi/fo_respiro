#ifndef GLCD_STM32CHIBIOS_H
#define GLCD_STM32CHIBIOS_H

void GLCD_InitalizePorts(void);
void GLCD_WriteData(unsigned char dataToWrite);
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller);
unsigned char GLCD_ReadByteFromROMMemory(char * ptr);

#endif // GLCD_STM32CHIBIOS_H
