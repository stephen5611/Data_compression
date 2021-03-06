/*
 * Data_Decompress_Engine.c
 *
 *  
 *      Author: Stephen
 */


#include "Common.h"
#include "Data_Compress_Interface.h"
#include "Data_Decompress_Private.h"


/******************************************************************************
Function Name	: byte_decompress

Description		: this function is used to decompress the compressed data bytes

Input			: data_ptr: pointer to a array
				  data_size: size of the array

Return			: Pointer to the dynamically allocated reconstructed array
                  Data size of the reconstructed array

Constraints     : The caller of this function is responsible to free the dynamically
                  allocated reconstructed array

******************************************************************************/

decomp_data_t* byte_decompress(uint8_t *data_ptr, size_t data_size)
{
	size_t index = 0;
	size_t ref_index = 0;
	static decomp_data_t decomp_data = {NULL,0};

	/*find the number of bytes to be allocated*/
	decomp_data.size = Data_Decompress_find_Decompress_Siz(data_ptr,data_size);


	decomp_data.data_ptr = (uint8_t*)malloc(decomp_data.size * sizeof(uint8_t));

	/*NULL check*/
	if((NULL == decomp_data.data_ptr) || (NULL == data_ptr))
	{
		decomp_data.size = 0;

		/*no need for further processing*/
		data_size = 0;
	}

	for(index = 0; index < data_size;index++)
	{
		if(DUPLICATE_BYTE_DETECT == (data_ptr[index] & DUPLICATE_BYTE_MASK))
		{
			/*fill the data byte present in the current index*/
			decomp_data.data_ptr[ref_index] = (data_ptr[index] & EXTRACT_BYTE_MASK);

			/*increment to the next index*/
			ref_index = ref_index + 1;

			/*extract the duplicated byte count from the next immediate index and fill the bytes*/
			while(0 != data_ptr[index + 1])
			{
				decomp_data.data_ptr[ref_index] = (data_ptr[index] & EXTRACT_BYTE_MASK);

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
			decomp_data.data_ptr[ref_index] = data_ptr[index];

			/*increment to the next index*/
			ref_index = ref_index + 1;
		}

	}

	return &decomp_data;

}
