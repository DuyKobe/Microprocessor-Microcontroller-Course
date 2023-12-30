#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

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
#define TIM2_EN (1U<<0)
#define CR1_CEN (1U<<0)
#define SR_UIF (1U<<0)
#define DIER_UIE (1U<<0)
#define UART2_EN (1U<<17)
#endif
#ifdef __cplusplus
}
#endif

