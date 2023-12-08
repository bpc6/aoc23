add_executable(day06 src/main.cpp)
target_include_directories(day06 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day06 PRIVATE aoc_lib)
