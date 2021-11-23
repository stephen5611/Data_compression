/*
 * Data_Compress_Private.h
 *
 *  Created on: Nov 22, 2021
 *      Author: ubuntu
 */

#ifndef DATA_COMPRESS_PRIVATE_H_
#define DATA_COMPRESS_PRIVATE_H_

#include <stdint.h>
#include <stddef.h>

/*Edge case checks */

/*check if the Address of Array is not NULL*/

/*Check if the data size is not zero*/

/*Check if the data size is 1 or 2*/

/* Return Number of continuous repeated Bytes*/
size_t Data_Compress_Cont_Repeated_Bytes(uint8_t *data_ptr, size_t data_size);

/*Insert the Count for the repeated bytes in the next immediate location of the repeating byte
 *  and then delete the Repeated bytes*/
void Data_Compress_Modify_Array(uint8_t *data_ptr, size_t repeated_count,size_t data_size);

void Print_Modified_Array(uint8_t *data_ptr, size_t data_size);


#endif /* DATA_COMPRESS_PRIVATE_H_ */
