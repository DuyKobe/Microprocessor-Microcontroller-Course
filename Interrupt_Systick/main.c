     #include<stdio.h>
#include"stm32f407xx.h"
#include"core_cm4.h"
#include<stdint.h>
#define GPIODEN 1<<3
#define GPIOAEN 1<<0
#define PD4_OUT 1<<24
#define LED_GREEN 1<<12
#define USER_BUTTON 3<<0
#define USER_BUTTON_PD 2<<0
#define SYSCFG_EN 1<<14
#define MR0 1<<0
#define TR0_EN 1<<0

uint32_t delay_ticks = 2000;
void SysTick_Configuration(){

	SysTick ->LOAD = 16000 - 1;//T_systick = 1 ms and clock system = 16Mhz
	SysTick -> CTRL = SysTick_CTRL_ENABLE_Msk 
									| SysTick_CTRL_COUNTFLAG_Msk   
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk; //Enable System Interrupt
}

int counter =0;
void SysTick_Handler() {
	counter++;
	if (counter >= delay_ticks){
		GPIOD->ODR ^= LED_GREEN;
		counter =0;
	}
	
}
void Interrupt_Configuration(){
	RCC -> APB2ENR = SYSCFG_EN;
	EXTI -> IMR  |= 1;
	EXTI -> RTSR |= TR0_EN;
//	EXTI -> FTSR |= TR0_EN;
	NVIC_EnableIRQ(EXTI0_IRQn); //Enable interrupt
	
}
int num = 0;
int main(){
	//NVIC ->ICER[0] = 1 << 6;
	//NVIC ->ISER[0] = 1 << 6;
	
	SysTick_Configuration();
	Interrupt_Configuration();

	
	//#define GPIOD ((Type_GPIO *)0x40020C00)
	RCC -> AHB1ENR |= GPIODEN |GPIOAEN ;
	GPIOD -> MODER = PD4_OUT;
	
	//#define GPIOA_0 ((Type_GPIO *)0x40020000)
	GPIOA -> MODER &= ~USER_BUTTON;
	
	
	while(1){

  }
	return 0;
}


void EXTI0_IRQHandler(void){
	EXTI -> PR |= 1<<0;
	num++;
		switch (num){
			case 1:
				delay_ticks = 2000;
				break;
			
			case 2:
				delay_ticks = 1000;
				break;
			
			case 3: 
				delay_ticks = 500;
				num=0;
				break;
			
			default:
				break;
		}
}
