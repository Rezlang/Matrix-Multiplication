cmake_minimum_required(VERSION 3.1)
project(Matrix-Multiplication)
set(CMAKE_CXX_STANDARD 11)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(Matrix-Multiplication main.cpp multiply.cpp multiply.h)
