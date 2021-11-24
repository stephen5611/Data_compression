

## Describe your project

Data Compression Design

Design an algorithm that will compress a given data buffer of bytes. Please describe your design and submit an implementation in a language of your choice.
The algorithm will live within a function.  This function will be called with two arguments; a pointer to the data buffer (data_ptr) and the number of bytes to compress (data_size).  After the function executes the data in the buffer will be modified and the size of the modified buffer will be returned.
Assumptions:
1.	The data_ptr will point to an array of bytes.  Each byte will contain a number from 0 to 127 (0x00 to 0x7F).  It is common for the data in the buffer to have the same value repeated in the series.
2.	The compressed data will need to be decompressable.  Please ensure that your algorithm allows for a decompression algorithm to return the buffer to it’s previous form.
Example data and function call:
// Data before the call
// data_ptr[] = { 0x03, 0x74, 0x04, 0x04, 0x04, 0x35, 0x35, 0x64, 
//                0x64, 0x64, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00,
//                0x56, 0x45, 0x56, 0x56, 0x56, 0x09, 0x09, 0x09 };
// data_size = 24;

new_size = byte_compress( data_ptr, data_size );


## Design Approach

Compression:
1. Redundancy of the repeated data bytes is the key point here to compress the array of bytes. By removing the removing the redundant bytes and
   marking a byte as duplicate and a location to store the count of the redundant bytes can help compress the data array.
2. Since the data bytes can have a value only in the range of 0x00 to 0x7F, the MSB of a byte in this array can be used to mark duplication.
3. The count of the Redundant bytes can be stored in the immediate next location of the byte which is repeated and the remaining redundant bytes 
   can be deleted.

Constraints:
1. If any of the bytes in the provided array of bytes has a value greater than 127, the algorithm will result in an undefined behavior
2. If the count of the redundant bytes exceeds 255, the remaining redundant bytes will be considered as new set of bytes and processed.
    For eg: data_array[0x01,0x01,0x01.....repeats for 512 times]
    the output of compression will be data_array[81 ff 81 ff]
3. For invalid data array such as data_array pointer pointing to NULL or data size of the array as zero, the algorithm will return compressed 
   data size as zero and will not process the array.
4. The Maximum size of the array depends on the maximum size that the underlying Machine provides.

Decompression:
1. The first step for decompression is to understand how much memory would be needed to reconstruct the compressed array
2. This is done by counting each byte in the array and if any of the bytes is marked as duplicate, then the value of the duplicated byte and 
   its next immediate byte(which contains count of the redundant byte) is added to the count.
3. With the knowledge of the above calculated, a array is created in the heap memory of size count.
4. The newly created array is now compared with the compressed array and its locations are filled byte by byte. if any of the bytes is marked as
    duplicate, then the next immediate byte is looked at to understand how many redundant bytes are needed to be filled in the array.

Constraints:
1. The Decompression algorithm returns pointer to the heap memory for the reconstructed array. The caller of this function is responsible to free the memory in the heap.

Note: Design flow chart for both compression and decompression algorithm is provided in the documents folder.

## Folder structure
1. src folder:
   data_compression folder: Contains source code for data compression and decompression algorithm. 
                            The Data_Compress_Engine.c is the core file for the 
                            compression algorithm.
                            The Data_Decompress_Engine.c is the core file for the 
                            decompression algorithm.

   test folder            : Contains code for test cases.

2. include folder         : Contains header files for both data_compression and test source files.
                            Data_Compress_Interface.h is the API header file for both data compression and decompression API's
                   
3. documents folder       : Contains design flow chart for both data compression and decompression algorithm.


## Build procedure
The code has been compiled and tested on Linux platform(Ubuntu)
cmake build tool system is used to build the code.

1. mkdir build
2. cd build
3. cmake ..
4. make
5. ./data_compression 

 