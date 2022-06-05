# The top level file for building the Sudoku game project using CMAKE

# Minimum version of CMake Required to build this project
cmake_minimum_required(VERSION 3.15)

# Name and version of the project
project(SudokuGame VERSION 1.4)


# C++ standard 20 is required to correctly run the game code
# Hence, building the project to call c++20 standard at the time of compilation
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add library to call code from the different classes defined for the code
add_library(gameGrid Grid.h Grid.cpp)

add_library(gameState GameOver.h GameOver.cpp)

add_library(gamePuzzle Puzzle.h Puzzle.cpp)


# The executable to be created from invoking the makefile
add_executable(${PROJECT_NAME} main.cpp)


# Link the libraries created above with the executable
target_link_libraries(${PROJECT_NAME} PUBLIC gameGrid gameState gamePuzzle)


