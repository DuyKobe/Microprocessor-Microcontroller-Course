#include"systick.h"


void SysTick_Configuration(){

	SysTick ->LOAD = 16000 - 1;//T_systick = 1 ms and clock system = 16Mhz
	SysTick -> CTRL = SysTick_CTRL_ENABLE_Msk 
									| SysTick_CTRL_COUNTFLAG_Msk  
									| SysTick_CTRL_CLKSOURCE_Msk 
									| SysTick_CTRL_TICKINT_Msk;
}


