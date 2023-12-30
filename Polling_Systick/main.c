#include<stdio.h>
#include"stm32f407xx.h"
#include"core_cm4.h"
#include<stdint.h>
#define GPIODEN 1<<3
#define GPIOAEN 1<<0
#define PD4_OUT 1<<24
#define LED_GREEN 1<<12
int i= 0;
void SysTick_Handler(){
	SysTick ->CTRL ;
	if (1000==i){
		GPIOD -> ODR ^= LED_GREEN;
		i=0;
	}
	i++;
}
int main(){

//	RCC -> AHB1ENR |= GPIODEN;
//	GPIOD ->MODER  |= PD4_OUT;
//	GPIOD ->BSRR |= LED_RED;
	
	typedef struct{
		uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    uint32_t AFR[2];
	}Type_GPIO;
	#define GPIOD_1 ((Type_GPIO *)0x40020C00)
	RCC -> AHB1ENR |= GPIODEN ;
	GPIOD_1 -> MODER = PD4_OUT;
	//GPIOD_1 ->BSRR |= LED_RED;
	
	//#define GPIOA_0 ((Type_GPIO *)0x40020000)

	SysTick ->LOAD = 16000 - 1; // T_systick = 1ms
	SysTick -> CTRL = SysTick_CTRL_ENABLE_Msk 
									| SysTick_CTRL_COUNTFLAG_Msk  
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk;
	
	/*
	//C1: Polling
	SysTick ->CTRL = 1<<0| 1<<2;
	
	uint8_t flag = 0;
	while(1){
		if(SysTick-> VAL <40 && flag ==0){
			GPIOD_1 ->BSRR |= 1<<28;
			flag =1;
		}
		if(SysTick-> VAL <40 && flag ==1){
			GPIOD_1 ->BSRR |= LED_RED;
			flag =0;
		}
	}
	*/
	
	/*
	void Init_Syst_Interrupt(
	SysTick -> CTRL = SysTick_CTRL_ENABLE_Msk 
									| SysTick_CTRL_COUNTFLAG_Msk  
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk;
	
	*/
	int count=0;
	while(1){
		count++;
	}
	
	//turn on - turn off led 4-5-6 and chong doi button
	
	return 0;
}	

