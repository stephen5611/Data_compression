/*
 * Common.c
 *
 *  
 *      Author: Stephen
 */

#include "Common.h"

/******************************************************************************
Function Name	: Print_Array

Description		: This funciton is used to display the array

Input			: data_ptr : pointer to a valid array
				  data_size: size of the array

Return			: None
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

Description		: This function is used to compare two different arrays

Input			: array1: pointer to a valid array 1
                  arr_size1: size of the array
                  array2: pointer to a valid array 2
                  arr_size2: size of the array

Return			: EQUAL    : If both the arrays have same byte values in all of its location
				  NOT_EQUAL: If atleast one byte is different betwwent both the arrays in any of its location
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

Description		: this functions validates the input parameters for a given aray

Input			: data_ptr : pointer to a array
				  data_size: size of the array

Return			: ERR_NULL_POINTER     : If the Address of the data pointer is NULL
				  ERR_INVALID_DATA_SIZE: If the Data size provided is 0
				  ERR_NONE             : If both Adress and Data are valid
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
