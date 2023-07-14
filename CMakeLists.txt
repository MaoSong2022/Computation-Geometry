cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(GJK LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)