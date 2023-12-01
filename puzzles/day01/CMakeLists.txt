project(Day01)

# Add executable for puzzle1
add_executable(day01 src/main.cpp src/puzzle1.cpp)

# Add unit tests for puzzle1
add_subdirectory(tests)