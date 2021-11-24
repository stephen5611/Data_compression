/*
 * Data_Compress_Interface.h
 *
 *  
 *      Author: Stephen
 */

#ifndef DATA_COMPRESS_INTERFACE_H_
#define DATA_COMPRESS_INTERFACE_H_

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct
{
	uint8_t *data_ptr;
	size_t   size;
}decomp_data_t;

/******************************************************************************
Function Name	: byte_compress

Description		: Function is used for Data compression

Input			: data_ptr : Data pointer to the data buffer which will be compressed
				  data_size: Maximum size that the underlying Machine can support

Return			: Modified compressed bytes in Array and new data size of the array
				  data size will be returned as 0 if data ptr is NULL or data size is 0.
******************************************************************************/
size_t byte_compress(uint8_t *data_ptr, size_t data_size);



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
decomp_data_t* byte_decompress(uint8_t *data_ptr, size_t data_size);

#endif /* DATA_COMPRESS_INTERFACE_H_ */
