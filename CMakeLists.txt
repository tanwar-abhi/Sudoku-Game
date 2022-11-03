# The top level file for building the Sudoku game project using CMAKE

# Minimum version of CMake Required to build this project
cmake_minimum_required(VERSION 3.15)

# Name and version of the project
project(SudokuGame VERSION 1.4)


# C++ standard 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add the path and name of the subdirectory that contains the code to be called for creating executable.
add_subdirectory(src)


# The executable to be created from invoking the makefile
add_executable(${PROJECT_NAME} main.cpp)


# Link the libraries created in the source subdirectory with the executable
target_link_libraries(${PROJECT_NAME} PUBLIC gameGrid gameState gamePuzzle)


