/*
 * Error_Code.h
 *
 *  
 *      Author: Stephen
 */

#ifndef ERROR_CODE_H_
#define ERROR_CODE_H_

#include <stdint.h>

typedef enum
{
	ERR_NONE = 0,
	ERR_NULL_POINTER,
	ERR_INVALID_DATA_SIZE,
	ERR_MAX
}Error_Code_t;

void Print_Error_Message(Error_Code_t error_code);

#endif /* ERROR_CODE_H_ */
