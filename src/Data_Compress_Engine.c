/*
 * Data_Compress_Engine.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include <stdio.h>
#include "Data_Compress_Interface.h"
#include "Data_Compress_Private.h"
#include "Common.h"

/******************************************************************************
Function Name	: byte_compress

Description		: Function is used for Data compression

Input			: data_ptr - Data pointer to data buffer which will be compressed

Return			: None
******************************************************************************/
size_t byte_compress(uint8_t *data_ptr, size_t data_size)
{
	uint8_t *data_ptr_ref = data_ptr;
	uint8_t repeated_bytes = 0;
	size_t remaining_data_size = data_size;

	while(remaining_data_size != 0)
	{
		repeated_bytes = Data_Compress_Cont_Repeated_Bytes(data_ptr_ref, remaining_data_size);

		if(1 < repeated_bytes)
		{
			Data_Compress_Modify_Array(data_ptr_ref,repeated_bytes,remaining_data_size);
			data_size = data_size - (repeated_bytes - 1);
			data_ptr_ref = data_ptr_ref + 1;
		}
		else
		{
			data_ptr_ref = data_ptr_ref + 1;
		}

		remaining_data_size = data_size - (data_ptr_ref - data_ptr);

	}

	printf("compressed data size: %lu\n",data_size);
	Print_Modified_Array(data_ptr,data_size);

	return data_size;
}
