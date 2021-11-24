/*
 * Data_Compress_Interface.h
 *
 *  Created on: Nov 23, 2021
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

size_t byte_compress(uint8_t *data_ptr, size_t data_size);

decomp_data_t* byte_decompress(uint8_t *data_ptr, size_t data_size);

#endif /* DATA_COMPRESS_INTERFACE_H_ */
