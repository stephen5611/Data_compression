/*
 * Data_Compress_Private.c
 *
 *  
 *      Author: Stephen
 */


#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "Data_Compress_Private.h"
#include "Common.h"



/******************************************************************************
Function Name	: Data_Compress_Cont_Repeated_Bytes

Description		: this function returns the count of a byte if it is contiguously repeated

Input			: data_ptr : pointer to a array
				  data_size: size of the array

Return			: 1 : If the byte is not repeated
                  greater than 1 : If the byte is repeated
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

Description		: this function is used to set a byte as duplicate and store 
                  its count in the next immediate location and readjust the array

Input			: data_ptr: pointer to a array
				  data_size: size of the array
                  repeated_count: count of the repeated byte
                  

Return			: None
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
