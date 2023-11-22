#include "adc.h"

void PA1_ADC_Init(void){
	/***Configure ADC GPIO pin ***/
	//Enable clock access GPIOA
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	//Set mode PA1 to analog
	GPIOA -> MODER |= GPIO_MODER_MODE1_1;
	/***Configure the ADC module***/
	//Enable clock access to ADC
	RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;
	
  // Conversion sequence start
	ADC1 -> SQR3 |= ADC_SQR3_SQ1_0;	
	
	// Conversion sequence length 
	ADC1 -> SQR1 |= ADC_SQR1_L;
	
	//Enable ADC module 
	ADC1-> CR2 |= ADC_CR2_ADON;
  
	//Configure ADC parameter
	
}

void Start_Conversion(void){
	//Start conversion mode
	ADC1 -> CR2 |= ADC_CR2_SWSTART;
}

uint32_t ADC_Read(void){
	//Waiting conversion completet
	while(!(ADC1 -> SR & ADC_SR_EOC)){}
		
	//Read conversion result
		return (ADC1 -> DR);
}