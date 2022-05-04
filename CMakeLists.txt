cmake_minimum_required(VERSION 3.21)
project(PersonTest_version2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PersonTest_version2 main.cpp PersonTest.h PersonTest.cpp TestNode.h TestNode.cpp)
