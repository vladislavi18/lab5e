cmake_minimum_required(VERSION 3.20)
project(lab5e C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5e main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/string_/string_.c libs/data_structures/string_/string_.h libs/data_structures/string_/tasks/task1.h)
