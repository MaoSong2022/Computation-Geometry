
set(BINARY ${CMAKE_PROJECT_NAME})

find_package (glog 0.6.0 REQUIRED)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cpp)
set(SOURCES ${SOURCES})
add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
target_link_libraries(${BINARY}_run glog)