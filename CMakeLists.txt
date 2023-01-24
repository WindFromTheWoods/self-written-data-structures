cmake_minimum_required(VERSION 3.24)
project(list)

set(CMAKE_CXX_STANDARD 17)

add_executable(list main.cpp src/data/list.cpp src/data/list.h src/data/vector.cpp src/data/vector.h src/data/algo.cpp src/data/algo.h)
