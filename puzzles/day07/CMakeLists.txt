add_executable(day07 src/main.cpp)
target_include_directories(day07 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day07 PRIVATE aoc_lib)
