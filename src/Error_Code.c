/*
 * Error_Code.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include <stdio.h>

#include "Error_Code.h"


void Print_Error_Message(Error_Code_t error_code)
{
	switch(error_code)
	{
		case ERR_NULL_POINTER:
			printf("Error : NULL pointer");
			break;
		case ERR_INVALID_DATA_SIZE:
			printf("Error : Data size is zero");
			break;

		default:
			break;
	}

}
