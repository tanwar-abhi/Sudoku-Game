# So this is the make file used to compile the sudoku game and sub objects.

CXXFLAGS = -std=c++17

all:Sudoku

Grid: Makefile Grid.h Grid.cpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

Sudoku: Makefile main_file.o Grid.o
	$(CXX) $(CXXFLAGS) main_file.o Grid.o -o RunSudokuGame
