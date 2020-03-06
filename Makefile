# So this is the make file used to compile the sudoku game and sub objects.

CXXFLAGS = -std=c++17

all:Sudoku

Grid: Makefile Grid.h Grid.cpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

Puzzle: Makefile Puzzle.h Puzzle.cpp
	$(CXX) $(CXXFLAGS) -c Puzzle.cpp
	
main: Makefile main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Sudoku: Makefile main.o Grid.o Puzzle.o
	$(CXX) $(CXXFLAGS) main.o Grid.o Puzzle.o -o RunSudoku
