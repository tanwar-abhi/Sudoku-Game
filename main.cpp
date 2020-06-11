// This is the main implementation file for the execution of suDokU

#include <iostream>
#include <vector>
#include "Grid.h"
#include "Puzzle.h"

int main(){

    int m=9, n=9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector<int>> PuzzleMatrix(m, std::vector<int> (n));

    Puzzle Sudoku;
    Grid Su1;

    Sudoku.Welcome(PuzzleMatrix);
    Sudoku.Print2dVec(PuzzleMatrix);
    

    
    if (Sudoku.SolveSudoku(PuzzleMatrix)){
        Sudoku.Print2dVec(PuzzleMatrix);
        //Su1.InitialGrid(PuzzleMatrix);
    }
    else{
        std::cout<<"Solution could not be obtained, check your problem.\nNot enough clues were given to solve the puzzle."<<std::endl;
    }
    
    /*
    Sudoku.GeneratePuzzle(PuzzleMatrix);
    Sudoku.Print2dVec(PuzzleMatrix);
    
    Grid Su1;
    Su1.InitialGrid(PuzzleMatrix);
    
    Sudoku.UserPuzzle(PuzzleMatrix);
    Sudoku.Print2dVec(PuzzleMatrix);
    */
    
   
    return 0;
}