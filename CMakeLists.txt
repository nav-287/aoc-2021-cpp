
cmake_minimum_required(VERSION 2.6)

# set the project name
project(AOC)

add_definitions(-DWITH_CPP_11)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++0x")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -std=c++0x")


SET(EXECUTABLE_OUTPUT_PATH ../bin)
SET(LIBRARY_OUTPUT_PATH ../bin)

#add_subdirectory(BaseClasses)
#add_subdirectory(Day1)

# add the executable
add_executable(aoc 
  main.cpp
  BaseClasses/puzzle.cpp
  Day1/puzzle1/puzzle1.cpp
  Day1/puzzle2/puzzle2.cpp
  Day2/puzzle1/puzzle1.cpp
  Day2/puzzle2/puzzle2.cpp
  Day3/puzzle1/puzzle1.cpp
  )
