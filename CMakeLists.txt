cmake_minimum_required(VERSION 3.25)
project(42_get_next_line C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(42_get_next_line
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        test.c
        test.txt)
