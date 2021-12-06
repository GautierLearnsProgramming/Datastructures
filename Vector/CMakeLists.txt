cmake_minimum_required(VERSION 3.19)
project(Vector)

set(CMAKE_CXX_STANDARD 98)

add_executable(Vector main.cpp dynamicarray_impl.h dynamicarray.h)