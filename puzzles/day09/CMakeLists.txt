add_executable(day09 src/main.cpp)
target_include_directories(day09 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day09 PRIVATE aoc_lib)
