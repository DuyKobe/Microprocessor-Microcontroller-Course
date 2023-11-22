#include "main.h"
#include <string.h>
#include "UART.h"
#include "adc.h"
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
#define TIM2_EN (1U<<0)
#define CR1_CEN (1U<<0)
#define SR_UIF (1U<<0)
#define DIER_UIE (1U<<0)
#define UART2_EN (1U<<17)
int k = 0;
char RxComByte = 0;
uint8_t buffer[BufferSize];
char str[] = "Hello World\r\n";
char data;
	int a, n;
	float b;
	int flag =0;
void SysTick_Handler();

uint32_t Sensor_value =0;
int main(){
	UART2_Init();
	SysTick_Configuration();
	PA1_ADC_Init();
	Start_Conversion();
	
	while (1){	
		/*
		if (flag ==1){
			flag=0;
			
			n = sprintf((char *)buffer, "a = %d\t", a);
			n += sprintf((char *)buffer + n, "  b = %f\r\n", b);
			USART_Write(USART2, buffer, n);
			a = a + 1;
			b = (float)a/100;		
			
			//USART_Write(USART2, (uint8_t *)str, strlen(str));	
		}
		*/
		
  //data = USART_Read(USART2);
	//n = sprintf((char *)buffer, "%c", data);
	//USART_Write(USART2, buffer, n);
		/*
		if (data == 'N' || data == 'n'){
			USART_Write(USART2, (uint8_t *)"Off\r\n\r\n", 9);
		}
		else if (data == 'Y' || data == 'y'){
			USART_Write(USART2, (uint8_t *)"On\r\n\r\n", 8);
		}
		*/
		
		Sensor_value = ADC_Read();
		printf("Sensor value: %d\n\r", (int)Sensor_value);
	}
	return 0;
}
void SysTick_Handler(){
	SysTick ->CTRL ;
	if (1000==k){
		flag =1;
		k=0;
	}
	k++;
}

