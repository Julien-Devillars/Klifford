set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

#add_library (Card src/card.cpp include/card.h)

#target_link_libraries(${PROJECT_NAME} Card)
