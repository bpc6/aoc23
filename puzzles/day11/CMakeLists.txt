add_executable(day11 src/main.cpp)
target_include_directories(day11 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day11 PRIVATE aoc_lib)
