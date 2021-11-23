/*
 * Common.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include "Common.h"

void Print_Modified_Array(uint8_t *data_ptr, size_t data_size)
{
	size_t index = 0;

	for(index = 0; index < data_size;index++)
	{
		printf("%x ",data_ptr[index]);
	}

	printf("\n");
}
