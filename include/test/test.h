/*
 * test.h
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#ifndef TEST_H_
#define TEST_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include "Common.h"

typedef enum {
	TEST_CASE_1_RANDOM_DATA = 0,
	TEST_CASE_2_SAME_DATA_SEQ,
	TEST_CASE_3_SAME_DATA,
	TEST_CASE_4_SAME_DATA_COUNT_GREATER_255,
	TEST_CASE_5_NULL_ARRAY,
	TEST_CASE_6_ZER0_DATA_SIZE,
	TEST_CASE_7_DATA_SIZE_1,
	TEST_CASE_8_DATA_SIZE_2,
	TEST_CASE_MAX
}test_case_t;

typedef struct {
	size_t len;
	uint8_t *data;
	uint8_t *name;
}test_input_t;


void test_main(void);

void Test_Compare_Result(uint8_t compare_result,uint8_t *test_case);

#endif /* TEST_H_ */
