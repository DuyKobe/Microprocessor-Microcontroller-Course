#include "automatic_fsm.h"

extern ADC_HandleTypeDef hadc1;

extern UART_HandleTypeDef huart2;

int status1 = INIT;
int ADC_value = 0;

uint8_t buffer_byte;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t cmd_flag = INIT;
uint8_t cmd_data[MAX_CMD_SIZE];
uint8_t cmd_data_index = 0;

int isCmdEqualToRST(uint8_t str[]) {
	if (str[0] == 'R' && str[1] == 'S' && str[2] == 'T')
		return 1;
	else
		return 0;
}

int isCmdEqualToOK(uint8_t str[]) {
	if (str[0] == 'O' && str[1] == 'K')
		return 1;
	else
		return 0;
}

void cmd_parser_fsm() {
	switch (status1) {
	case INIT:
		if (buffer_byte == '!')
			status1 = READING;
		break;
	case READING:
		if (buffer_byte != '!' && buffer_byte != '#') {
			cmd_data[cmd_data_index] = buffer_byte;
			cmd_data_index++;
		}
		if (buffer_byte == '#') {
			status1 = STOP;
			cmd_data_index = 0;
		}
		break;
	case STOP:
		if (isCmdEqualToRST(cmd_data) == 1) {
			cmd_flag = RST;
			setTimer1(1);
		} else if (isCmdEqualToOK(cmd_data) == 1) {
			cmd_flag = OK;
		}
		status1 = INIT;
		break;
	default:
		break;
	}
}

void uart_comms_fsm() {
	char str[50];
	switch (cmd_flag) {
	case RST:
		if (timer1_flag == 1) {
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*) str,
					sprintf(str, "!ADC=%d#\r\n", ADC_value), 500);
			setTimer1(100);
		}
		break;
	case OK:
		ADC_value = -1;
		cmd_flag = INIT;
		break;
	default:
		break;
	}
}
