cmake_minimum_required(VERSION 3.17)
project(lab5 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5 main.c Replacement.c tests/test.c tests/test.h ConfigChecker.c ConfigChecker.h Error.c Error.h)