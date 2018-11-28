/*
 * UART_capture.h
 *
 *  Created on: Nov 27, 2018
 *      Author: LuisFernando
 */

#ifndef UART_CAPTURE_H_
#define UART_CAPTURE_H_

#include "UART_TERM.h"

#define PSW_SIZE 4

typedef enum {
	ASCII_NUMBER_0 = 48,
	ASCII_NUMBER_1 = 49,
	ASCII_NUMBER_2 = 50,
	ASCII_NUMBER_3 = 51,
	ASCII_NUMBER_4 = 52,
	ASCII_NUMBER_5 = 53,
	ASCII_NUMBER_6 = 54,
	ASCII_NUMBER_7 = 55,
	ASCII_NUMBER_8 = 56,
	ASCII_NUMBER_9 = 57,
	ASCII_ENTER = 13,
	ASCII_SPACE = 32
}Deco_type;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	Funct to capture the value obtained by the terminal and stored it in a buffer.
 	 \param[in] void
 	 \return void
 */
void capture_psw(void);

#endif /* UART_CAPTURE_H_ */
