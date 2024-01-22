cmake_minimum_required(VERSION 3.20.0)
project(Queue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(
    src
    usr/include
)

set(PROJECT_SOURCES src/main.cpp src/Queue.hpp )
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES})