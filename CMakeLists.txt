cmake_minimum_required(VERSION 3.10.2)
project(decoder_wrapper_test)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(lib/)
include_directories(lib/include/)
link_directories(lib/)

add_executable(decoder_wrapper_test
        lib/include/WoffDecoder.h
        main.c)

target_link_libraries(decoder_wrapper_test libwoffdecoder.so)