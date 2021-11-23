/*
 * Data_Compress_Engine.c
 *
 *  Created on: Nov 22, 2021
 *      Author: ubuntu
 */

#include <stdio.h>
#include "Data_Compress_Interface.h"
#include "Data_Compress_Private.h"
#include "Common.h"

size_t byte_compress(uint8_t *data_ptr, size_t data_size)
{
	//size_t new_size = 0;
	uint8_t *data_ptr_ref = data_ptr;
	uint8_t repeated_bytes = 0;
	size_t remaining_data_size = data_size;

	//printf("data_size : %lu\n",data_size);

	while(remaining_data_size != 0)
	{
		repeated_bytes = Data_Compress_Cont_Repeated_Bytes(data_ptr_ref, remaining_data_size);

		//printf("repeated bytes %d\n",repeated_bytes);

		if(1 < repeated_bytes)
		{
			Data_Compress_Modify_Array(data_ptr_ref,repeated_bytes,remaining_data_size);
			data_size = data_size - (repeated_bytes - 1);
			//data_ptr_ref = data_ptr_ref + (repeated_bytes - 1);
			data_ptr_ref = data_ptr_ref + 1;

		}
		else
		{
			data_ptr_ref = data_ptr_ref + 1;
		}

		//data_ptr_ref = data_ptr_ref + (repeated_bytes - 1);
		//printf("data_ptr_ref - data_ptr %d\n",(data_ptr_ref - data_ptr));
		remaining_data_size = data_size - (data_ptr_ref - data_ptr);
		//printf("remaining_data_size : %lu\n",remaining_data_size);
		//break;
	}

	//printf("remaining_data_size : %lu\n",remaining_data_size);
	printf("compressed data size: %lu\n",data_size);
	Print_Modified_Array(data_ptr,data_size);

	//printf("repeated_bytes:%lu", repeated_bytes);
	return data_size;
}
