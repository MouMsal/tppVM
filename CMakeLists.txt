cmake_minimum_required(VERSION 3.23)
project(tppVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(tppVM lc3.cpp Memory.cpp Memory.h opcodes.cpp opcodes.h CPU.cpp CPU.h)
