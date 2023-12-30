     #include<stdio.h>
#include"stm32f407xx.h"
#include"core_cm4.h"
#include<stdint.h>



/*
void tim2_10ms_init(){

	//Enable clock access Timer
	RCC -> APB1ENR |= TIM2_EN;

	//Set prescaler value
	TIM2 -> PSC = 1600 -1;
	
	//Set auto_reload value
	TIM2 -> ARR = 100 -1;
 
	//Clear counter
	TIM2 -> CNT = 0;
	
	//Enable Timer
	TIM2 -> CR1 |= CR1_CEN;
	
	//Enable interrupt
	TIM2 -> DIER |=DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
}
*/
void tim4_output_compare(void){
	/*Procedure:
1. Select the counter clock (internal, external, prescaler).
2. Write the desired data in the TIMx_ARR and TIMx_CCRx registers.
3. Set the CCxIE and/or CCxDE bits if an interrupt and/or a DMA request is to be
generated.
4. Select the output mode. For example, the user must write OCxM=011, OCxPE=0,
CCxP=0 and CCxE=1 to toggle OCx output pin when CNT matches CCRx, CCRx
preload is not used, OCx is enabled and active high.
5. Enable the counter by setting the CEN bit in the TIMx_CR1 register
	*/
	
	//Enable clock access GPIOD 
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIODEN ;
	
	//Set PD14 mode alternate function = 10
	GPIOD -> MODER |= GPIO_MODER_MODE14_1;
	
	//Set PD14 alternate function type to TIM4_CH3 (AF2=00010)
	GPIOD -> AFR[1]|= GPIO_AFRH_AFRH6_1;
	
	//Enable clock access Timer 4
	RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;

	//Set prescaler value
	TIM4 -> PSC = 1600 -1;
	
	//Set auto_reload value
	TIM4 -> ARR = 10000 -1;
	
	//Set output compare toggle mode
	TIM4 -> CCMR2 |=0x3 << TIM_CCMR2_OC4M_Pos;
	// Enable Tim4 channel_3 in compare mode
	TIM4 -> CCER |= TIM_CCER_CC3E;
	
	/*Clear counter*/
	TIM4 -> CNT = 0;
	/*Enable Timer*/
	TIM4 -> CR1 |= TIM_CR1_CEN;
	
}




int main(void){
	tim4_output_compare();
	while(1){
		int i =0;
}
}


