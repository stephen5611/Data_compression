/*
 * Common.h
 *
 * 
 *      Author: Stephen
 */

#ifndef COMMON_H_
#define COMMON_H_
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "Error_Code.h"

#define EQUAL                     0
#define NOT_EQUAL                 1
#define INVALID_DATA_SIZE         0
#define DUPLICATE_BYTE_MASK       0x80
#define IMMEDIATE_NEXT_LOC        1

void Print_Array(uint8_t *data_ptr, size_t data_size);

uint8_t Compare_Arrays(uint8_t *array1,size_t size1, uint8_t *array2,size_t size2);

Error_Code_t Invalid_Array_Chk(uint8_t *data_ptr, size_t data_size);

#endif /* COMMON_H_ */
