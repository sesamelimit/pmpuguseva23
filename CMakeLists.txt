cmake_minimum_required(VERSION 3.22)
project(PersonTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(PersonTest main.cpp PersonTest.cpp PersonTest.h TestNode.h TestNode.cpp)
