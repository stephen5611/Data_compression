/*
 ============================================================================
 Name        : test1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#define INPUT 2
#include "Data_Compress_Interface.h"

int main(void)
{
	size_t new_size = 0;
	size_t len = new_size;
#if INPUT == 1
	uint8_t data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };
	len=24;
#elif INPUT == 2
	uint8_t data_ptr[] = {0x01,0x01, 0x01, 0x01,0x01, 0x01, 0x01,0x09,0x09};
	len = 9;
#elif INPUT == 3
	uint8_t data_ptr[] = {0x01,0x01, 0x01, 0x01};
	len = 4;
#endif

	new_size = byte_compress(data_ptr,len);

	//printf("new size:: %lu data:%d",new_size,data_ptr[0]);
	return EXIT_SUCCESS;
}
