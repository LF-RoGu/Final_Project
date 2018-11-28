/*
 * UART_capture.c
 *
 *  Created on: Nov 27, 2018
 *      Author: LuisFernando
 */

#include "UART_capture.h"

/**This is mail box to received the information from the serial port*/
extern UART_MailBoxType UART0_MailBox;

/*Buffer to store the new user*/
static sint8 user_buffer[USER_SIZER] = {FALSE};
static sint8 psw_buffer[PSW_SIZE] = {FALSE};

void capture_psw()
{
	volatile uint8 index = FALSE;

	if (UART0_MailBox.flag)
	{
		if ((ASCII_NUMBER_1 <= UART0_MailBox.mailBox) || (ASCII_NUMBER_9 >= UART0_MailBox.mailBox))
		{
			psw_buffer[index] = UART0_MailBox.mailBox;
			UART_putChar(UART_0,psw_buffer[index]);
			index++;
			if(psw_buffer[PSW_SIZE] == NULL)
			{
				flags.flag_master = TRUE;
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
					flags.flag_open = TRUE;
				}
				if(ASCII_NUMBER_2 == UART0_MailBox.mailBox)
				{
					flags.flag_add = TRUE;
				}
			}
			else
			{
				flags.flag_wrong = TRUE;
			}
		}
		UART0_MailBox.flag = FALSE;
	}
}

void add_user()
{
	volatile uint8 index_user = FALSE;
	while(TRUE == flags.flag_add)
	{
		if (UART0_MailBox.flag)
		{
			user_buffer[index_user] = UART0_MailBox.mailBox;
			if(ASCII_ENTER == UART0_MailBox.mailBox)
			{
				flags.flag_add = FALSE;
				counter.users++;
			}
		}
		UART0_MailBox.flag = FALSE;
	}
	/*Clears index to store it in the memory*/
	index_user = FALSE;
	switch(counter.users)
	{
	case BIT1:
		for(uint8 arr_index = FALSE; arr_index < MEM_STEP; arr_index++)
		{
			EEPROM_write_mem(arr_index,user_buffer[index_user]);
			index_user++;
		}
		/*Clears index to store it in the memory*/
		index_user = FALSE;
		break;
	case BIT2:
		for(uint8 arr_index = MEM_STEP; arr_index < (BIT2 * MEM_STEP); arr_index++)
		{
			EEPROM_write_mem(arr_index,user_buffer[index_user]);
			index_user++;
		}
		/*Clears index to store it in the memory*/
		index_user = FALSE;
		break;
	case BIT3:
		for(uint8 arr_index = (BIT2 * MEM_STEP); arr_index < (BIT3 * MEM_STEP); arr_index++)
		{
			EEPROM_write_mem(arr_index,user_buffer[index_user]);
			index_user++;
		}
		/*Clears index to store it in the memory*/
		index_user = FALSE;
		break;
	case BIT4:
		for(uint8 arr_index = (BIT3 * MEM_STEP); arr_index < (BIT4 * MEM_STEP); arr_index++)
		{
			EEPROM_write_mem(arr_index,user_buffer[index_user]);
			index_user++;
		}
		/*Clears index to store it in the memory*/
		index_user = FALSE;
		break;
	case BIT5:
		for(uint8 arr_index = (BIT4 * MEM_STEP); arr_index < (BIT5 * MEM_STEP); arr_index++)
		{
			EEPROM_write_mem(arr_index,user_buffer[index_user]);
			index_user++;
		}
		/*Clears index to store it in the memory*/
		index_user = FALSE;
		break;
	}
}

void add_code()
{
	if (UART0_MailBox.flag)
	{

	}
	UART0_MailBox.flag = FALSE;
}
