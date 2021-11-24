/*
 * Common.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include "Common.h"

/******************************************************************************
Function Name	: Print_Array

Description		:

Input			: data_ptr :
				  data_size:

Return			:
******************************************************************************/
void Print_Array(uint8_t *data_ptr, size_t data_size)
{
	size_t index = 0;
	Error_Code_t error_code = ERR_NONE;

	error_code = Invalid_Array_Chk(data_ptr,data_size);

	if(ERR_NONE == error_code)
	{
		for(index = 0; index < data_size;index++)
		{
			printf("%x ",data_ptr[index]);
		}
	}
	else
	{
		Print_Error_Message(error_code);
	}


	printf("\n");
}

/******************************************************************************
Function Name	: Compare_Arrays

Description		:

Input			: array1:
                  arr_size1:
                  array2:
                  arr_size2:

Return			:
******************************************************************************/

uint8_t Compare_Arrays(uint8_t *array1,size_t arr_size1, uint8_t *array2,size_t arr_size2)
{
	size_t index = 0;
	Error_Code_t error_code = ERR_NONE;
	uint8_t result = NOT_EQUAL;

	error_code = Invalid_Array_Chk(array1,arr_size1);

	if(ERR_NONE == error_code)
	{
		error_code = Invalid_Array_Chk(array2,arr_size2);

		if(ERR_NONE == error_code)
		{
			if(arr_size1 == arr_size2)
			{
				for(index = 0; index < arr_size1;index++)
				{
					if(array2[index] != array1[index])
					{
						result = NOT_EQUAL;
						break;
					}
					else
					{
						result = EQUAL;
					}
				}
			}
			else
			{
				result = NOT_EQUAL;
			}

		}
		else
		{
			Print_Error_Message(error_code);
		}
	}
	else
	{
		Print_Error_Message(error_code);
	}

	return result;

}

/******************************************************************************
Function Name	: Invalid_Array_Chk

Description		:

Input			: data_ptr :
				  data_size:

Return			:
******************************************************************************/

Error_Code_t Invalid_Array_Chk(uint8_t *data_ptr, size_t data_size)
{
	Error_Code_t error_code = ERR_NONE;

	if(NULL == data_ptr)
	{
		error_code = ERR_NULL_POINTER;
	}
	else if( INVALID_DATA_SIZE == data_size)
	{
		error_code = ERR_INVALID_DATA_SIZE;
	}

	return error_code;
}
