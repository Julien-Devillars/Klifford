
include_directories (${TEST_SOURCE_DIR}/src
                     )



add_executable (Test test_card.cpp)

target_link_libraries (Test
                       Card
                       )

add_test (NAME MyTest COMMAND Test)