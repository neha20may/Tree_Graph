cmake_minimum_required(VERSION 3.21)
project(Union-find)
set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(UF union-find.cpp union-find.h)