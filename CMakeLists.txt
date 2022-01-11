cmake_minimum_required(VERSION 3.21)
project(Coursera_part2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Coursera_part2 main.cpp Node.cpp Node.h)
add_executable(iterator test_iterators.cpp test_iterators.h)
add_executable(string_example simple_string.cpp simple_string.h)

add_executable(3b
        3b/main.cpp
        3b/simple_string.cpp
        3b/simple_string.h
        3b/stack.cpp
        3b/stack.h
        3b/stack.inl)