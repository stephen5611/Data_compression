/*
 * Data_Compress_Private.c
 *
 *  Created on: Nov 22, 2021
 *      Author: ubuntu
 */
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "Data_Compress_Private.h"



size_t Data_Compress_Cont_Repeated_Bytes(uint8_t *data_ptr, size_t data_size)
{
	size_t index = 0;
	size_t repeated_bytes = 0;

	/*Continue only if data_size is more than 1*/
	if(1 != data_size)
	{
		for(index = 1; index < data_size; index++)
		{
			/*check if the next element in the array is equal to the base element of the array*/
			if(data_ptr[0] == data_ptr[index])
			{
				/*increment the number of repeated bytes*/
				repeated_bytes = repeated_bytes + 1;
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


void Data_Compress_Modify_Array(uint8_t *data_ptr, size_t repeated_count,size_t data_size)
{
	size_t index = 0;

	/*Set the MSB of the byte to indicate duplicate entries*/
	data_ptr[0] = data_ptr[1] | 0x80;

	/*insert the count of the repeated bytes to the immediate next location*/
	data_ptr[1] = repeated_count;

	/*delete the duplicate bytes present after the insertion of repeated count and re-adjust the array */
	for(index = 2; index < (data_size - (repeated_count - 1));index++)
	{
		data_ptr[index] = data_ptr[index + (repeated_count - 1)];
	}
}




