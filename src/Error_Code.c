/*
 * Error_Code.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include <stdio.h>

#include "Error_Code.h"


/******************************************************************************
Function Name	: Print_Error_Message

Description		:

Input			: error_code:

Return			:
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
