add_executable(day03 src/main.cpp)
target_include_directories(day03 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day03 PRIVATE aoc_lib)
