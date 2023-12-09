add_executable(day10 src/main.cpp)
target_include_directories(day10 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day10 PRIVATE aoc_lib)
