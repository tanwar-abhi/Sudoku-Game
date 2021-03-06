# The make file used to compile the sudoku game and sub classes.

CXXFLAGS = -std=c++17

all:Sudoku

Grid: Makefile Grid.h Grid.cpp
	$(CXX) $(CXXFLAGS) -c Grid.cpp

GameState: Makefile GameOver.h GameOver.cpp
	$(CXX) $(CXXFLAGS) -c GameOver.cpp

Puzzle: Makefile Puzzle.h Puzzle.cpp
	$(CXX) $(CXXFLAGS) -c Puzzle.cpp
	
main: Makefile main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Sudoku: Makefile main.o Grid.o Puzzle.o GameOver.o
	$(CXX) $(CXXFLAGS) main.o Grid.o Puzzle.o GameOver.o -o RunSudoku
