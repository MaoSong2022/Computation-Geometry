cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GJK)

# Find the Google Test library
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# file(GLOB SOURCES src/*.cpp)
add_subdirectory(src)
add_subdirectory(test)