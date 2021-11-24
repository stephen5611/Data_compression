/*
 * Data_Compress_Engine.c
 *
 *
 *      Author: Stephen
 */

#include <stdio.h>
#include "Data_Compress_Interface.h"
#include "Data_Compress_Private.h"
#include "Common.h"


/******************************************************************************
Function Name	: byte_compress

Description		: Function is used for Data compression

Input			: data_ptr : Data pointer to the data buffer which will be compressed
				  data_size: Maximum size that the underlying Machine can support

Return			: Modified compressed bytes in Array and new data size of the array
******************************************************************************/
size_t byte_compress(uint8_t *data_ptr, size_t data_size)
{
	uint8_t *data_ptr_ref = data_ptr;
	uint8_t repeated_bytes = 0;
	size_t remaining_data_size = 0;
	Error_Code_t error_code = ERR_NONE;

	/*Handle error condition*/
	error_code = Data_Compress_Chk_Invalid_Scenarios(data_ptr,data_size);

	/*if error is present return size = 0*/
	if(ERR_NONE != error_code)
	{
		data_size = 0;
		remaining_data_size = data_size;
	}
	else
	{
		/*remaining_data_size is used as a reference to go through the entire array*/
		remaining_data_size = data_size;
	}

	/*loop till there is no data to be processed*/
	while(remaining_data_size != 0)
	{
		/*calculate the repeated count if a current byte is being repeated in the next immediate location continuously*/
		repeated_bytes = Data_Compress_Cont_Repeated_Bytes(data_ptr_ref, remaining_data_size);

		/*compress the repeated bytes only when the byte has repeated more than once:
		 * for instance: [0x01,0x01,0x01] is valid for compression but [0x01,0x01] is not valid*/
		if(MINIMUM_BYTE_REPEAT < repeated_bytes)
		{
			/*delete the repeated bytes and enable MSB of the repeated byte to indicate a repeated byte.
			 *  This bit will be used for verifying duplication during decompression
			 * Also insert the repeated count of the byte in the next immediate location of the repeated byte.
			 * */
			Data_Compress_Modify_Array(data_ptr_ref,repeated_bytes,remaining_data_size);

			/*reduce the data size after deleting the repeated bytes. Also, since,
			 * the repeated count is being inserted in the immediate next location,
			 *  this also needs to be taken into account*/
			data_size = data_size - (repeated_bytes - INSERTED_COUNT_BYTE);
		}
		else
		{
			/*Do nothing*/
		}

		/*Move the data_ptr_ref pointer to the next location*/
		data_ptr_ref = data_ptr_ref + 1;

		/*calculate the remaining data size*/
		remaining_data_size = data_size - (data_ptr_ref - data_ptr);

	}

	return data_size;
}
