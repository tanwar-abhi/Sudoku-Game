# Sudoku, puzzle Game

This repository contains the implementation of a text based {without GUI} game of sudoku, which I coded in c++.
It is the result of my personal interest in c++, sudoku and mathematical optimization.

`Grid.h`,`Grid.cpp` -> Implementation file containing declaration and definition of all the member functions and variables of `Grid` class. The Grid class takes care of the aesthetic portion of the puzzle. It displays the puzzle in a tabular and graphic view for ease of user.

`Puzzle.h`,`Puzzle.cpp` -> Puzzle class definition, declaration and implementation file, this essentially deals in generating the Puzzle which is simply a Matrix (i.e. 2D Vector). This class also handles the user play aspects of the game.

`GameOver.h`,`GameOver.cpp` -> This file contains the declaration and implementation definition of code for checking whether a particular puzzle is solved correctly or not by the user. This class controls the status of the game.

`main.cpp` -> The main file that contains all the objects and function calls that run's the game efficiently.

## Some observations and lessons learned.
* To generate the puzzle initially, i used a naive brute force box method approach. Wherein I filled all the diagonal boxes of the puzzle first, i.e. right diagonal first then left diagonal and then finally all the remaining elements as per the condition of Sudoku.

* The brute force method of Box filling a Sudoku grid with random numbers failed due to unoptimized constraints conflict(as observed here, mathematical optimization) from implementing the brute force random method.

* Thus, to improve the implementation and satisfy the constraint optimization, I implemented the recursive backtracking algorithm. Backtracking allows us to retrace our steps and make changes in cells as per the requirement in order to satisfy all constraints of a Sudoku Board.

* In order for a puzzle to be solvable i.e. have only single solution, the user must be given atleast 17 clues. For more details check [Reference](#Reference).


## How to Compile and Run
This games was coded in Linux, using the open source **g++ *version=5.4.0 20160609*** compiler and currently can only run on Linux terminal. Revision *C++17* of the ISO/IEC 14882 standard for the C++ programming language was used for build.

1. To run this game simply fork or clone/download this repository.
2. Go to the folder containing all the files and type *make*.
3. Start game by simply launching `RunSudoku` *{ ./RunSudoku }*.

## Reference 
McGuire, Gary & Tugemann, Bastian & Civario, Gilles. (2012). There Is No 16-Clue Sudoku: Solving the Sudoku Minimum Number of Clues Problem via Hitting Set Enumeration. Experimental Mathematics. 23. 10.1080/10586458.2013.870056.

https://www.researchgate.net/publication/51978217_There_Is_No_16-Clue_Sudoku_Solving_the_Sudoku_Minimum_Number_of_Clues_Problem_via_Hitting_Set_Enumeration

## Call for Contributions
If you find any mistakes in my code or if you sensed there's a better and optimized way to write/simplify implementation of some part of code then raise a pull request to let me know. Suggestions, Improvements or fixes are always appreciated as it not only improves the code but also improves my coding skills. 
Thanks for your Contributions. :)

**A Work in progress {current updates}**
This repository is a work in progress for a text based game of sudoku.

- [x] Puzzle solver implemented using backtracking algorithm.
- [x] Terminal text based user interface build, terminal aesthetic rendition for user.
- [ ] Create a GUI and an app based on this solver code so that it can be run on multiple platforms, for fun.
