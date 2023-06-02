#include "fsm_automatic.h"

void fsm_automatic_run() {
	switch (state) {
	case INIT:
		number1 = durForRed - 1;
		number2 = durForGreen - 1;
		HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
		setTimerRed();
		setTimerGreen();
		setOneSecond();
		state = EastWest;
		break;
	case EastWest:
		if (oneSecondFlag() == 1) {
			number1--;
			number2--;
			setOneSecond();
		}
		if (greenFlag() == 1) {
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
			number2 = durForRed - durForGreen - 1;
		}
		if (redFlag() == 1) {
			number1 = durForGreen;
			number2 = durForRed;
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
			setTimerRed();
			setTimerGreen();
			setOneSecond();
			state = NorthSouth;
		}
		if (isButtonPressed(MODE_BUTTON))
			state = RED_MODE;
		break;
	case NorthSouth:
		if (oneSecondFlag() == 1) {
			number1--;
			number2--;
			setOneSecond();
		}
		if (greenFlag() == 1) {
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, GPIO_PIN_SET);
			number1 = durForRed - durForGreen - 1;
		}
		if (redFlag() == 1) {
			number1 = durForRed - 1;
			number2 = durForGreen - 1;
			HAL_GPIO_WritePin(R0_GPIO_Port, R0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Y0_GPIO_Port, Y0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G0_GPIO_Port, G0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
			setTimerRed();
			setTimerGreen();
			setOneSecond();
			state = EastWest;
		}
		if (isButtonPressed(MODE_BUTTON))
			state = RED_MODE;
		break;
	default:
		break;
	}
}

