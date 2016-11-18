# This is an example cmake project
cmake_minimum_required(VERSION 2.8)

# Example for setting policy for using VERSION in project
if(POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
else()
    message(FATAL_ERROR "!!Policy CMP0048 not known!!")
endif(POLICY CMP0048)

project(Example VERSION 0.0.1 LANGUAGES CXX)

# example using x11 compiler
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Example for using an option and message
option(${PROJECT_NAME}_CMAKE_DEBUG "Set to on if you want some debug output" OFF)
if(${PROJECT_NAME}_CMAKE_DEBUG)
    message(STATUS "[${CMAKE_CURRENT_LIST_DIR}:${CMAKE_CURRENT_LIST_LINE}] "
            "${PROJECT_NAME} starting")
endif()

# uncomment for using the example
## example for including other cmake files
#set(I_AM_AN_OPTION ON CACHE BOOL "Set option of child.cmake from parent scope" FORCE)
#include(${CMAKE_CURRENT_LIST_DIR}/child.cmake)

#set(SOURCE_FILES main.cpp)
#add_executable(CMake ${SOURCE_FILES})