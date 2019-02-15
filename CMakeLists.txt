# Sets the minimum required version of cmake for a project.
# If the current version of CMake is lower than that required it will stop
# processing the project.
cmake_minimum_required (VERSION 2.8.3)

project (my-stl-library)

message(STATUS "Building my-stl-library Project")

### enable C++11 standard
set (CMAKE_CXX_STANDARD 11) 
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_subdirectory(UnitTesting)