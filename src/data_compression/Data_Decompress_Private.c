/*
 * Data_Decompress_Private.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#include "Data_Decompress_Private.h"
#include "Common.h"


/******************************************************************************
Function Name	: Data_Decompress_find_Decompress_Siz

Description		:

Input			: data_ptr:
                  compressed_data_size:

Return			:
******************************************************************************/

size_t Data_Decompress_find_Decompress_Siz(uint8_t *data_ptr, size_t compressed_data_size)
{
	size_t index = 0;
	size_t byte_count = 0;

	for(index = 0;index < compressed_data_size;index++)
	{
		if(DUPLICATE_BYTE_DETECT == (data_ptr[index] & DUPLICATE_BYTE_MASK))
		{
			/*increment the byte count. The count of the repeated byte
			 * is provided in the next immediate byte. The "+ 1" is for the
			 * byte that the current index is pointing at*/

			byte_count = byte_count + data_ptr[index + IMMEDIATE_NEXT_LOC] + CURRENT_DATA_BYTE_COUNT;

			/*increment the index since we have already processed the next byte for the count*/
			index = index + 1;
		}
		else
		{
			/*increment the byte count*/
			byte_count = byte_count + 1;
		}
	}

	return byte_count;
}
