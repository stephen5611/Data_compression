/*
 * Data_Compress_Private.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#ifndef DATA_COMPRESS_PRIVATE_H_
#define DATA_COMPRESS_PRIVATE_H_

#include <stdint.h>
#include <stddef.h>
#include "Error_Code.h"


#define INSERTED_COUNT_BYTE       1
#define MINIMUM_BYTE_REPEAT       1
#define BASE_ELEMENT              0
#define MAX_REPEAT_BYTE_COUNT     255
#define MIN_DATA_SIZE             1 


/*Negative case checks */
Error_Code_t Data_Compress_Chk_Invalid_Scenarios(uint8_t *data_ptr, size_t data_size);

/* Return Number of continuous repeated Bytes*/
uint8_t Data_Compress_Cont_Repeated_Bytes(uint8_t *data_ptr, size_t data_size);

/*Insert the Count for the repeated bytes in the next immediate location of the repeating byte
 *  and then delete the Repeated bytes*/
void Data_Compress_Modify_Array(uint8_t *data_ptr, size_t repeated_count,size_t data_size);




#endif /* DATA_COMPRESS_PRIVATE_H_ */
