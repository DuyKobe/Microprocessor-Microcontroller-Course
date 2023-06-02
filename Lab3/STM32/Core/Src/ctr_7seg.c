/*
 * ctr_7seg.c
 *
 *  Created on:  April, 2023
 *      Author: Duy
 */
#include "ctr_7seg.h"

static uint8_t LED7_SEG[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
		0x80, 0x90 };

void turnSeg0(int num) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((LED7_SEG[num] >> 6) & 0x01));
}

void turnSeg1(int num) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, ((LED7_SEG[num] >> 6) & 0x01));
}

void enableSeg(int num1, int num2) {
	switch (stateSeg) {
	case 0:
		turnSeg0(num1 / 10);
		turnSeg1(num2 / 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		stateSeg = 1;
		setTimerEnable();
		break;
	case 1:
		turnSeg0(num1 / 10);
		turnSeg1(num2 / 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		if (enableFlag() == 1) {
			stateSeg = 2;
			setTimerEnable();
		}
		break;
	case 2:
		turnSeg0(num1 % 10);
		turnSeg1(num2 % 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		if (enableFlag() == 1) {
			stateSeg = 1;
			setTimerEnable();
		}
		break;
	default:
		break;
	}
}

