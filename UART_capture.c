/*
 * UART_capture.c
 *
 *  Created on: Nov 27, 2018
 *      Author: LuisFernando
 */

#include "UART_capture.h"

/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

void capture_psw()
{
	sint8 psw_buffer[PSW_SIZE] = FALSE;
	if (UART0_MailBox.flag)
	{
		if ((ASCII_NUMBER_1 <= UART0_MailBox.mailBox) || (ASCII_NUMBER_9 >= UART0_MailBox.mailBox))
		{
			*psw_buffer = UART0_MailBox.mailBox;
			UART_putChar(UART_0,*psw_buffer);
			*psw_buffer++;
		}
	}
	UART0_MailBox.flag = FALSE;
}
