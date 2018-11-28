/*
 * UART_capture.c
 *
 *  Created on: Nov 27, 2018
 *      Author: LuisFernando
 */

#include "UART_capture.h"

/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

/*Flags so we can change to the next state*/
static uint8 flag_master = FALSE;
static uint8 flag_wrong = FALSE;
static uint8 flag_open = FALSE;
static uint8 flag_add = FALSE;

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
			if(psw_buffer[PSW_SIZE] == NULL)
			{
				flag_master = TRUE;
			}
		}
	}
	UART0_MailBox.flag = FALSE;
}

void choose(uint8 flag_master)
{
	TERA_choose();
	if(flag_master == TRUE)
	{
		if (UART0_MailBox.flag)
		{
			if((ASCII_NUMBER_1 == UART0_MailBox.mailBox) || (ASCII_NUMBER_2 == UART0_MailBox.mailBox))
			{
				if(ASCII_NUMBER_1 == UART0_MailBox.mailBox)
				{
					flag_open = TRUE;
				}
				if(ASCII_NUMBER_2 == UART0_MailBox.mailBox)
				{
					flag_add = TRUE;
				}
			}
			else
			{
				flag_wrong = TRUE;
			}
		}
		UART0_MailBox.flag = FALSE;
	}
}
