add_executable(day08 src/main.cpp)
target_include_directories(day08 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day08 PRIVATE aoc_lib)
