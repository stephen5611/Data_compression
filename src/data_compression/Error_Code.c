/*
 * Error_Code.c
 *
 *  
 *      Author: Stephen
 */

#include <stdio.h>

#include "Error_Code.h"


/******************************************************************************
Function Name	: Print_Error_Message

Description		: this function is used to print the error code on the console

Input			: error_code

Return			: None
******************************************************************************/

void Print_Error_Message(Error_Code_t error_code)
{
	switch(error_code)
	{
		case ERR_NULL_POINTER:
			printf("Error : NULL pointer\n");
			break;
		case ERR_INVALID_DATA_SIZE:
			printf("Error : Data size is zero\n");
			break;

		default:
			break;
	}

}
