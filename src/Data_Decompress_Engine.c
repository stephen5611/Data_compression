/*
 ============================================================================
 Name        : Data_Decompress_Engine.c
 Author      : Stephen
 Email		 : stephen5611@gmail.com
 Version     : 1.0
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Common.h"
#include "Data_Compress_Interface.h"
#include "Data_Decompress_Private.h"

size_t byte_decompress(uint8_t *data_ptr, size_t data_size)
{
	size_t decompressed_num_of_bytes = 0;
	uint8_t *decomp_data_ptr = NULL;
	size_t index = 0;
	size_t ref_index = 0;

	/*find the number of bytes to be allocated*/
	decompressed_num_of_bytes = Data_Decompress_find_Uncompress_Siz(data_ptr,data_size);

	printf("size of byte array %lu\n",decompressed_num_of_bytes);

	decomp_data_ptr = (uint8_t*)malloc(decompressed_num_of_bytes * sizeof(uint8_t));

	for(index = 0; index < data_size;index++)
	{
		if(0x80 == (data_ptr[index] & 0x80))
		{
			/*fill the data byte present in the current index*/
			decomp_data_ptr[ref_index] = (data_ptr[index] & 0x7F);

			/*increment to the next index*/
			ref_index = ref_index + 1;

			/*extract the duplicated byte count from the next immediate index and fill the bytes*/
			while(0 != data_ptr[index + 1])
			{
				decomp_data_ptr[ref_index] = (data_ptr[index] & 0x7F);

				/*decrement the duplicate byte count*/
				data_ptr[index + 1] = data_ptr[index + 1] - 1;

				/*increment to the next index*/
				ref_index = ref_index + 1;
			}

			/*increment the index considering the next index is already
			 *  processed for duplicate count*/
			index = index + 1;

		}
		else
		{
			/*fill the data byte present in the current index*/
			decomp_data_ptr[ref_index] = data_ptr[index];

			/*increment to the next index*/
			ref_index = ref_index + 1;
		}

	}

	Print_Modified_Array(decomp_data_ptr,decompressed_num_of_bytes);

	free(decomp_data_ptr);
	return 0;

}
