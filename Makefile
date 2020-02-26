# So this is the make file used to compile the sudoku game and sub objects.

CXXFLAGS = -std=c++17

all:Sudoku

Grid: Makefile Grid.h Grid.cpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp
	
main: Makefile main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Sudoku: Makefile main.o Grid.o
	$(CXX) $(CXXFLAGS) main.o Grid.o -o RunSudoku
