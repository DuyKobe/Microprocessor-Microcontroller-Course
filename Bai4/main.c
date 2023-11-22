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
#define SYSCFG_EN 1<<14
#define MR0 1<<0
#define TR0_EN 1<<0

uint32_t delay_ticks = 200;
void SysTick_Configuration(){

	SysTick ->LOAD = 160000 - 1;//T_systick = 10 ms and clock system = 16Mhz
	SysTick -> CTRL = SysTick_CTRL_ENABLE_Msk 
									| SysTick_CTRL_COUNTFLAG_Msk  
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk;
}
void Interrupt_Configuration(){
	RCC -> APB2ENR = SYSCFG_EN;
	EXTI -> IMR  |= 1;
	EXTI -> RTSR |= TR0_EN;
//	EXTI -> FTSR |= TR0_EN;
	NVIC_EnableIRQ(EXTI0_IRQn); //Enable interrupt
}
int last = 0;
int flag = 0;
int counter =0;
uint8_t count = 2;
typedef enum  {
		reset_order = 2,
		red = 1,
		blue = 0,
} led_state;
int i = 0;
void SysTick_Handler() {
	counter++;
	if (counter >= delay_ticks){
		GPIOD->ODR ^= LED_GREEN;
		counter =0;
	}
	if(count != last){
		i=100;
	}
	if (100==i){
		if(count == red){
			last = count;
			if(flag ==1){
				GPIOD -> ODR |= LED_RED;
				GPIOD -> ODR &= ~(LED_BLUE);
			}if (flag ==0){
				GPIOD -> ODR ^= LED_RED;
				GPIOD -> ODR &= ~(LED_BLUE);
			}
					}
		if(count == blue ||count ==reset_order){
			last = count;
			if(flag ==1){
				GPIOD -> ODR |= LED_BLUE;
				GPIOD -> ODR &= ~(LED_RED);
			}if(flag==0){
				GPIOD -> ODR ^= LED_BLUE;	
				GPIOD -> ODR &= ~(LED_RED);
			}
	   }
			i=0;	
	}
	i++;
}



int num = 0;
int main(){
	//NVIC ->ICER[0] = 1 << 6;
	//NVIC ->ISER[0] = 1 << 6;
	
	SysTick_Configuration();
	Interrupt_Configuration();

	
	//#define GPIOD ((Type_GPIO *)0x40020C00)
	RCC -> AHB1ENR |= GPIODEN |GPIOAEN ;
	GPIOD -> MODER = PD4_OUT | PD5_OUT| PD6_OUT;
	
	//#define GPIOA_0 ((Type_GPIO *)0x40020000)
	GPIOA -> MODER &= ~USER_BUTTON;
	while(1){
		int button_A0 = GPIOA -> IDR & (1<<0);
		if (i==90){
			if (button_A0){
			flag =1;
			}	
			if(button_A0 ==0){
			flag =0;
			}
		}
	}
	return 0;
}


void EXTI0_IRQHandler(void){
	EXTI -> PR |= 1<<0;
	count--;
	if(count==0){
		count  = reset_order;
	}
	num++;
		switch (num){
			case 1:
				delay_ticks = 200;
				break;
			
			case 2:
				delay_ticks = 100;
				break;
			
			case 3: 
				delay_ticks = 50;
				num=0;
				break;
			
			default:
				break;
		}
}
