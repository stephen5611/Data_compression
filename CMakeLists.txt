cmake_minimum_required(VERSION 3.10.2)

project(data_compression)

file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(data_compression main.c ${SRC_FILES})

target_include_directories(data_compression PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/data_compression)
target_include_directories(data_compression PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/test)
