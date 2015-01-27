cmake_minimum_required(VERSION 2.8.4)
project(ADS_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES main.c sort.c sort.h probing.c probing.h)
if(UNIX)
    link_libraries(m)
endif(UNIX)

add_executable(ADS_3 ${SOURCE_FILES})