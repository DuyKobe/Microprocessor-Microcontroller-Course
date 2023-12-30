#ifndef __ADC_H
#define __ADC_H

#include "main.h"

void PA1_ADC_Init(void);
void Start_Conversion(void);
uint32_t ADC_Read(void);

#endif 
