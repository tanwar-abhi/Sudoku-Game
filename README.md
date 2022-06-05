# Sudoku, puzzle Game
## Version 1.4


**Version 1.4 updates**
- [x] Build system updated from privitive *MakeFile* to modern and cross platform suppored **CMAKE**


This repository contains the implementation of a text based {without GUI} game of sudoku, which I coded in c++.
It is the result of my personal interest in c++, sudoku and mathematical optimization.

## Directory Structure
This directory contains a `build` directory that will contain all build files when cmake is invoked.

`src` is the subdirectory containing source code.

`CMakeLists.txt` top level file that invokes all calls to compile and build the project.

`compileRun.sh` shell script to automate the call to cmake to build and run the game.

## Some observations and lessons learned.
* To generate the puzzle initially, i used a naive brute force box method approach. Wherein I filled all the diagonal boxes of the puzzle first, i.e. right diagonal first then left diagonal and then finally all the remaining elements as per the condition of Sudoku.

* The brute force method of Box filling a Sudoku grid with random numbers failed due to unoptimized constraints conflict(as observed here, mathematical optimization) from implementing the brute force random method.

* Thus, to improve the implementation and satisfy the constraint optimization, I implemented the recursive backtracking algorithm. Backtracking allows us to retrace our steps and make changes in cells as per the requirement in order to satisfy all constraints of a Sudoku Board.

* In order for a puzzle to be solvable i.e. have only single solution, the user must be given atleast 17 clues. For more details check [Reference](#Reference).


## How to Compile and Run
This games was coded in Linux, using the open source **g++ *version=9.3.0 20160609*** compiler and currently can only run on Command Line Interface (CLI). Revision *C++20* of the ISO/IEC 14882 standard for the C++ programming language was used for build.

1. To run this game simply fork or clone/download this repository.
2. To compile the game and run simply run the shell script `compileRun.sh` *{ ./compileRun.sh }*.


**A Work in progress {current updates}**
This repository is a work in progress for a text based game of sudoku.

- [x] Puzzle solver implemented using backtracking algorithm.
- [x] Terminal text based user interface build, terminal aesthetic rendition for user.
- [ ] Create a GUI and an app based on this solver code so that it can be run on multiple platforms, for fun.


## Reference 
McGuire, Gary & Tugemann, Bastian & Civario, Gilles. (2012). There Is No 16-Clue Sudoku: Solving the Sudoku Minimum Number of Clues Problem via Hitting Set Enumeration. Experimental Mathematics. 23. 10.1080/10586458.2013.870056.

https://www.researchgate.net/publication/51978217_There_Is_No_16-Clue_Sudoku_Solving_the_Sudoku_Minimum_Number_of_Clues_Problem_via_Hitting_Set_Enumeration


## Call for Contributions
If you find any mistakes in my code or if you sensed there's a better and optimized way to write/simplify implementation of some part of code then raise a pull request to let me know. Suggestions, Improvements or fixes are always appreciated as it not only improves the code but also improves my coding skills. 
Thanks for your Contributions. 
