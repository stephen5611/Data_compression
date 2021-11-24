/*
 * test.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Stephen
 */

#include"test.h"
#include "Data_Compress_Interface.h"

uint8_t data_test1[] =
{
	0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09,
};

uint8_t expected_data_test1[] =
{
	0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64,
	0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09,
};

uint8_t data_test2[] =
{
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x09,
	0x09,
};

uint8_t expected_data_test2[] =
{
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x09,
	0x09,
};

uint8_t data_test3[] =
{
	0x01, 0x01, 0x01, 0x01,
};

uint8_t expected_data_test3[] =
{
	0x01, 0x01, 0x01, 0x01,
};


uint8_t data_test4[] =
{
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x09,0x09,0x09,0x01,
};

uint8_t expected_data_test4[] =
{
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0x01,0x01,0x01,0x01,0x09,0x09,0x09,0x01,
};

uint8_t data_test6[] =
{
	0x01, 0x01, 0x01, 0x01
};

uint8_t expected_data_test6[] =
{
	0x01, 0x01, 0x01, 0x01
};

uint8_t data_test7[] =
{
	0x01
};

uint8_t expected_data_test7[] =
{
	0x01
};

uint8_t data_test8[] =
{
	0x01,0x02
};

uint8_t expected_data_test8[] =
{
	0x01,0x02
};

uint8_t test_name1[] = "TEST_CASE_1_RANDOM_DATA";
uint8_t test_name2[] = "TEST_CASE_2_SAME_DATA_SEQ";
uint8_t test_name3[] = "TEST_CASE_3_SAME_DATA";
uint8_t test_name4[] = "TEST_CASE_4_SAME_DATA_COUNT_GREATER_255";
uint8_t test_name5[] = "TEST_CASE_5_NULL_ARRAY";
uint8_t test_name6[] = "TEST_CASE_6_ZER0_DATA_SIZE";
uint8_t test_name7[] = "TEST_CASE_7_DATA_SIZE_1";
uint8_t test_name8[] = "TEST_CASE_8_DATA_SIZE_2";

test_input_t test_scenario[TEST_CASE_MAX]=
{
	{24, data_test1, test_name1},
	{9,  data_test2, test_name2},
	{4,  data_test3, test_name3},
	{512,data_test4, test_name4},
	{24,  NULL,      test_name5},
	{0,  data_test6, test_name6},
	{1,  data_test7, test_name7},
	{2,  data_test8, test_name8}
};

test_input_t expected_test_scenario[TEST_CASE_MAX]=
{
	{24, expected_data_test1, test_name1},
	{9,  expected_data_test2, test_name2},
	{4,  expected_data_test3, test_name3},
	{512,expected_data_test4, test_name4},
	{24,  NULL,      test_name5},
	{0,  expected_data_test6, test_name6},
	{1,  expected_data_test7, test_name7},
	{2,  expected_data_test8, test_name8}
};

/******************************************************************************
Function Name	: test_main

Description		: Test function for data compression and decompression check

Input			: None

Return			: None
******************************************************************************/
void test_main(void)
{
	size_t new_size = 0;
	uint8_t test_index = 0;
	decomp_data_t* decomp_data = NULL;
	uint8_t compare_result = NOT_EQUAL;
	for(test_index = TEST_CASE_1_RANDOM_DATA; test_index < TEST_CASE_MAX; test_index++)
	{
		printf("\n\nTEST SCENARIO : %s\n", test_scenario[test_index].name);

		printf("Actual data:\n");
		Print_Array(test_scenario[test_index].data,test_scenario[test_index].len);
		printf("Actual size: %lu\n",test_scenario[test_index].len);
		printf("\ncompressing--->\n");
		new_size = byte_compress(test_scenario[test_index].data,test_scenario[test_index].len);
		printf("compressed data:\n");
		Print_Array(test_scenario[test_index].data,new_size);
		printf("compressed size: %lu\n",new_size);

		printf("\ndecompressing--->\n");
		decomp_data = byte_decompress(test_scenario[test_index].data,new_size);
		printf("decompressed size: %lu\n",decomp_data->size);
		printf("Reconstructed data:\n");
		Print_Array(decomp_data->data_ptr,decomp_data->size);
		printf("\n");

		switch(test_index)
		{
			case TEST_CASE_1_RANDOM_DATA:

				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			case TEST_CASE_2_SAME_DATA_SEQ:
				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			case TEST_CASE_3_SAME_DATA:
				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			case TEST_CASE_4_SAME_DATA_COUNT_GREATER_255:
				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			case TEST_CASE_5_NULL_ARRAY:
				if(0 == new_size)
				{
					printf("No run time error and returned compressed size is %lu\n",new_size);
					printf("Test case: %s has PASSED\n",expected_test_scenario[test_index].name);
				}
				else
				{
					printf("Returned compressed size is %lu\n",new_size);
					printf("Test case: %s has FAILED\n",expected_test_scenario[test_index].name);
				}
				break;

			case TEST_CASE_6_ZER0_DATA_SIZE:
				if(0 == new_size)
				{
					printf("No run time error and returned compressed size is %lu\n",new_size);
					printf("Test case: %s has PASSED\n",expected_test_scenario[test_index].name);
				}
				else
				{
					printf("Returned compressed size is %lu\n",new_size);
					printf("Test case: %s has FAILED\n",expected_test_scenario[test_index].name);
				}
				break;

			case TEST_CASE_7_DATA_SIZE_1:
				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			case TEST_CASE_8_DATA_SIZE_2:
				compare_result = Compare_Arrays(expected_test_scenario[test_index].data,expected_test_scenario[test_index].len,
								decomp_data->data_ptr,decomp_data->size);

				Test_Compare_Result(compare_result,expected_test_scenario[test_index].name);
				break;

			default:
				break;
		}

		printf("************************************************************************************\n");
		free(decomp_data->data_ptr);
		/*avoiding dangling pointer issue due to repeated freeing */
		decomp_data->data_ptr = NULL;

	}
}


void Test_Compare_Result(uint8_t compare_result,uint8_t *test_case)
{
	if(EQUAL != compare_result)
	{
		printf("Test case: %s has FAILED\n",test_case );
	}
	else
	{
		printf("Test case: %s has PASSED\n",test_case );
	}
}
