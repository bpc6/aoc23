add_executable(day02 src/main.cpp)
target_include_directories(day02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day02 PRIVATE aoc_lib)
