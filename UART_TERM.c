/*
 * UART_TERM.c
 *
 *  Created on: Nov 27, 2018
 *      Author: LuisFernando
 */

#include "UART_TERM.h"


void TERA_master()
{
	/**The following sentences send strings to PC using the UART_putString function. Also, the string
	 * is coded with terminal code*/
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for text in white and background in black*/
	UART_putString(UART_0, "\033[0;37;40m");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Ingrese clave maestra\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[11;10H");
}
void TERA_choose()
{
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[12;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Chose either to add user or open safe\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[12;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "1) Open safe\r");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[13;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "2)Add user\r");
}
void TERA_wrong()
{
	/*VT100 command for clearing the screen*/
	UART_putString(UART_0,"\033[2J");
	/** VT100 command for positioning the cursor in x and y position*/
	UART_putString(UART_0, "\033[10;10H");
	/** Set the text in a string*/
	UART_putString(UART_0, "Put a correct number\r");
}
