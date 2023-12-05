add_executable(day01 src/main.cpp)
target_include_directories(day01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day01 PRIVATE aoc_lib)
