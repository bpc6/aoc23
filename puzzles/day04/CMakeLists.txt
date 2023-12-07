add_executable(day04 src/main.cpp)
target_include_directories(day04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day04 PRIVATE aoc_lib)
