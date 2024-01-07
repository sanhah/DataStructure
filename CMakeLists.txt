cmake_minimum_required(VERSION 3.0)
project(CS_DS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    src
    usr/include
)

set(PROJECT_SOURCES main.cpp src/SinglyLinkedList.cpp )
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})