cmake_minimum_required(VERSION 3.26)
project(aoc23)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Google Test using FetchContent
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        URL https://github.com/google/googletest/archive/b10fad38c4026a29ea6561ab15fc4818170d1c10.zip
#)
#FetchContent_MakeAvailable(googletest)
#enable_testing()

# Include directories for common headers
#include_directories(${CMAKE_SOURCE_DIR})

# Add subdirectories for each puzzle
add_subdirectory(lib)
add_subdirectory(puzzles/day01)
add_subdirectory(puzzles/day02)
