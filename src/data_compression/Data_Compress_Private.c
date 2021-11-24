/*
 * Data_Compress_Private.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "Data_Compress_Private.h"
#include "Common.h"

/******************************************************************************
Function Name	: Data_Compress_Chk_Invalid_Scenarios

Description		:

Input			: data_ptr:
                  data_size:


Return			:
******************************************************************************/

Error_Code_t Data_Compress_Chk_Invalid_Scenarios(uint8_t *data_ptr, size_t data_size)
{
	Error_Code_t error_code = ERR_NONE;

	if(NULL == data_ptr)
	{
		error_code = ERR_NULL_POINTER;
	}
	else if(INVALID_DATA_SIZE  == data_size)
	{
		error_code = ERR_INVALID_DATA_SIZE;
	}

	return error_code;
}

/******************************************************************************
Function Name	: Data_Compress_Cont_Repeated_Bytes

Description		:

Input			: data_ptr:
                  data_size:

Return			:
******************************************************************************/


uint8_t Data_Compress_Cont_Repeated_Bytes(uint8_t *data_ptr, size_t data_size)
{
	size_t index = 0;
	uint8_t repeated_bytes = 0;

	/*Continue only if data_size is more than 1*/
	if(MIN_DATA_SIZE != data_size)
	{
		for(index = 1; index < data_size; index++)
		{
			/*check if the next element in the array is equal to the base element of the array*/
			if(data_ptr[BASE_ELEMENT] == data_ptr[index])
			{
				/*increment the number of repeated bytes*/
				repeated_bytes = repeated_bytes + 1;

				/*edge case scenario: repetitive byte count is > 255*/
				if(MAX_REPEAT_BYTE_COUNT <= repeated_bytes)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		repeated_bytes = 0;
	}


	return repeated_bytes;
}


/******************************************************************************
Function Name	: Data_Compress_Modify_Array

Description		:

Input			: data_ptr:
                  repeated_count:
                  data_size:

Return			:
******************************************************************************/

void Data_Compress_Modify_Array(uint8_t *data_ptr, size_t repeated_count,size_t data_size)
{
	size_t index = 0;

	/*Set the MSB of the byte to indicate duplicate entries*/
	data_ptr[BASE_ELEMENT] = data_ptr[BASE_ELEMENT] | DUPLICATE_BYTE_MASK;

	/*insert the count of the repeated bytes to the immediate next location*/
	data_ptr[IMMEDIATE_NEXT_LOC] = repeated_count;

	/*delete the duplicate bytes present after the insertion of repeated count and re-adjust the array */
	for(index = (IMMEDIATE_NEXT_LOC + 1); index < (data_size - (repeated_count - INSERTED_COUNT_BYTE));index++)
	{
		data_ptr[index] = data_ptr[index + (repeated_count - INSERTED_COUNT_BYTE)];
	}
}
