add_executable(day05 src/main.cpp)
target_include_directories(day05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(day05 PRIVATE aoc_lib)
