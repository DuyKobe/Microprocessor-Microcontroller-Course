/*
 * button.h
 *
 *  Created on: Nov 13, 2022
 *      Author: Asus
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	SET
#define PRESSED_STATE	RESET

#define MODE_BUTTON 	0
#define INC_BUTTON		1
#define DEC_BUTTON		2
#define APPLY_BUTTON	3

int isButtonPressed(int index);

void subkeyProcess(int index);

void getInputKey();

#endif /* INC_BUTTON_H_ */
