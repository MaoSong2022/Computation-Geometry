cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GJK)

# Find the Google Test library
find_package(GTest REQUIRED)

# set(CMAKE_PREFIX_PATH "/home/PJLAB/maosong/glog/build" ${CMAKE_PREFIX_PATH})



set(CMAKE_CXX_STANDARD 11)

include_directories(include)



add_subdirectory(src)
add_subdirectory(test)