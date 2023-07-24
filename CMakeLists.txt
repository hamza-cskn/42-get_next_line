cmake_minimum_required(VERSION 3.25)
project(getnextline_remake C)

set(CMAKE_C_STANDARD 11)

add_executable(getnextline_remake get_next_line.c get_next_line_utils.c test.c)
