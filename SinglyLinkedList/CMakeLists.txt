cmake_minimum_required(VERSION 3.20.0)
project(SinglyLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    src
    usr/include
)

set(PROJECT_SOURCES src/main.cpp src/SinglyLinkedList.hpp)
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})