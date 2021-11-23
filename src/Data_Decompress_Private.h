/*
 * Data_DeCompress_Private.h
 *
 *  Created on: Nov 23, 2021
 *      Author: ubuntu
 */

#ifndef DATA_DECOMPRESS_PRIVATE_H_
#define DATA_DECOMPRESS_PRIVATE_H_

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

size_t Data_Decompress_find_Uncompress_Siz(uint8_t *data_ptr, size_t compressed_data_size);

#endif /* DATA_DECOMPRESS_PRIVATE_H_ */
