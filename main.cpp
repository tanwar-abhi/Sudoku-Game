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
    int playSelect;
    playSelect = Sudoku.Welcome();
    //Sudoku.Print2dVec(PuzzleMatrix);

    try{
        if (playSelect!=1 && playSelect!=2 && playSelect!=3){
            throw "Game aborted!! Run the game again ";
        }
    }
    catch (const char* text){
        std::cout<<"You made an invalid choice. Please make appropriate choice"<<std::endl;
        std::cout<<text<<std::endl;
    }

    switch (playSelect){
        case 1:
            Sudoku.PlayDemo();
            break;
        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"The puzzle grid you enter is = \n";
            Sudoku.Print2dVec(PuzzleMatrix);
               if (Sudoku.SolveSudoku(PuzzleMatrix)){
                   Sudoku.Print2dVec(PuzzleMatrix);
                }
                else{
                    std::cout<<"Solution could not be obtained, check your problem.\nNot enough clues were given to solve the puzzle."<<std::endl;
                }
        default:
            break;
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