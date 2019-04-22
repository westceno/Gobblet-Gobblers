cmake_minimum_required(VERSION 3.13)
project(Gobble-Gobblers C)

set(CMAKE_C_STANDARD 99)

add_executable(Gobblet-Gobblers main.c)
MATH(EXPR stack_size "1024 * 1024 * 1024") # 1024 Mb
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")