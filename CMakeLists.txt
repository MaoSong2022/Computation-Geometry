cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(GJK)

include_directories(${GJK_SOURCE_DIR}/include)

file(GLOB SOURCES src/*.cpp)

add_executable(GJK main.cpp ${SOURCES})