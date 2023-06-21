cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GJK_test)

add_subdirectory(src)

link_directories(src)
add_executable(GJK_test main.cpp)
target_link_libraries(GJK_test GJK)