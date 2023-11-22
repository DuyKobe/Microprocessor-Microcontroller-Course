#include<stdio.h>
#include"stm32f407xx.h"
#include"core_cm4.h"
#include<stdint.h>
#define GPIODEN 1<<3
#define GPIOAEN 1<<0
#define PD4_OUT 1<<24
#define PD5_OUT 1<<28
#define PD6_OUT 1<<30
#define LED_GREEN 1<<12
#define LED_RED 1<<14
#define LED_BLUE 1<<15
#define USER_BUTTON 3<<0
#define USER_BUTTON_PD 2<<0

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
	RCC -> AHB1ENR |= GPIODEN |GPIOAEN;
	GPIOD_1 -> MODER |= PD4_OUT | PD5_OUT| PD6_OUT;
	//GPIOD_1 ->BSRR |= LED_RED;
	
	#define GPIOA_0 ((Type_GPIO *)0x40020000)
	GPIOA_0 -> MODER &= ~USER_BUTTON;
	GPIOA_0 -> PUPDR |= USER_BUTTON_PD ;
	//SysTick ->LOAD = 16000-1;
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
	
	//C2: Interrupt
	/*
	void Init_Syst_Interrupt(
	SysTick -> CTRL = SysTick_CTRL_COUNTFLAG_Msk  
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk;
	
	}
	while(1){
		
	}
	*/
	//turn on - turn off led 4-5-6 and chong doi button
	uint8_t count = 3;
	int button_A0;
	int lastbutton = 0;
	typedef enum  {
		reset_order = 3,
		red = 2,
		green= 1,
		blue = 0,
	} led_state;
	while(1){
		button_A0 = GPIOA_0 -> IDR & (1<<0);
		if (lastbutton != button_A0){
			int i =10;
			while(i>0){
				i--;
			}
			button_A0 = 	;
			if (lastbutton != button_A0){
				if ( button_A0 == 1){
					count--;
					if(count == red){
						GPIOD_1 -> ODR |= LED_RED;
						GPIOD_1 -> ODR &= ~(LED_BLUE);
						GPIOD_1 -> ODR &= ~(LED_GREEN);
					}
					if(count == green){
						GPIOD_1 -> ODR |= LED_GREEN;	
						GPIOD_1 -> ODR &= ~(LED_RED);
						GPIOD_1 -> ODR &= ~(LED_BLUE);
					}
					if(count == blue){
						GPIOD_1 -> ODR |= LED_BLUE;	
						GPIOD_1 -> ODR &= ~(LED_GREEN);
						GPIOD_1 -> ODR &= ~(LED_RED);
					count  = reset_order;
					}	
				}
			}
			lastbutton = button_A0;
		}	
	}
	return 0;
}

