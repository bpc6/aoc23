add_executable(day12 src/main.cpp)
target_include_directories(day12 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day12 PRIVATE aoc_lib)
