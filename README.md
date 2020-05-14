# Sudoku, puzzle Game

This repository contains the implementation of a text based {without GUI} game of sudoku, which I coded in c++.
It is the result of my personal interest in c++ and sudoku both.
To generate the puzzle initially i used the brute force box method approach. Wherein I filled all the diagonal boxes of the puzzle first, i.e. right diagonal first then left diagonal and then finally all the remaining elements as per the condition of Sudoku.

* The brute force method of Box filling a Sudoku grid with random numbers failed due to unoptimized constraints (as observed here, mathematical optimization)  from implementing the brute force random method.

*  Thus, to improve the implementation and satify the constraint optimization, I implement the optimized backtracking algorithm.

* Backtracking allows us to retrace our steps and make changes in cells as per the requirement in order to maintain constraints of a Sudoku Board.


`Grid.h` -> Header file for the Grid class, containing all the definitions of the variables and member fucntions of the class.

`Grid.cpp` -> Implementation file containing all the member functions and variables of `Grid` class. The Grid class takes care of the aesthetic portion of the puzzle. It displays the puzzle in a tabular and graphic view for ease of user.

`Puzzle.h` -> Header file for the Puzzle class, contain definition of all member functions for the Puzzle object.

`Puzzle.cpp` -> Puzzle class implementation file, this essentially deals in generating the Puzzle which is simply a Matrix (i.e. 2D Vector).

`GameOver.h` -> To be coded, work in progress {WIP}

`GameOver.cpp` -> This file contains the implementation of code for checking whether a particular puzzle is solved correctly or not by the user. Will use backtracking algorithm to check all digits of the puzzle. To be coded, work in progress {WIP}

`main.cpp` -> The main file that contains all the objects and function calls that run's the game.

*Still under development*

**A Work in progress**
This repository is a work in progress for a text based game of sudoku.

1. Used OOPS principles in the implementation of the game.
2. Box fill technique {falied due to unsatisfied constraints of the puzzle}
3. Backtracking algorithm to generate a solution.
