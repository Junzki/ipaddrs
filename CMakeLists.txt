cmake_minimum_required(VERSION 3.8)
project(ipaddrs C)

set(CMAKE_C_STANDARD 90)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(ipaddrs STATIC src/ipaddrs.c)


add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
