add_executable(day13 src/main.cpp)
target_include_directories(day13 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day13 PRIVATE aoc_lib)
