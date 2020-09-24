cmake_minimum_required(VERSION 3.8) 

set(PROJECT_NAME Klifford)
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(test)