cmake_minimum_required(VERSION 3.5) 

project(Klifford CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB SOURCES
	"include/*.h"
	"src/*.cpp"
)
add_executable(${PROJECT_NAME}
  ${SOURCES})

install(TARGETS ${PROJECT_NAME}
  DESTINATION bin)