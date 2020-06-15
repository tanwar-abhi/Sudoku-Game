// This is the main implementation file for the execution of suDokU

#include <iostream>
#include <vector>
#include "Grid.h"
#include "Puzzle.h"
#include "GameOver.h"

int main(){

    int m=9, n=9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector<int>> PuzzleMatrix(m, std::vector<int> (n));

    Puzzle Sudoku;
    Grid Su1;
    GameOver Status;

    int playSelect;
    playSelect = Sudoku.Welcome();
    //Sudoku.Print2dVec(PuzzleMatrix);

    try{
        if (playSelect!=1 && playSelect!=2 && playSelect!=3){
            throw "Game aborted!! Run the game again ";
        }
    }
    catch (const char* text){
        std::cout<<"You made an invalid choice. Please make an appropriate choice"<<std::endl;
        std::cout<<text<<std::endl;
    }

    switch (playSelect){
        case 1:
            Sudoku.PlayDemo();

        case 2:
            // Generates Random puzzle and saves the solution in Status for future reference.
            Sudoku.GeneratePuzzle(PuzzleMatrix, Status);
            std::cout<<"Puzzle Generated = "<<std::endl;
            Sudoku.Print2dVec(PuzzleMatrix);

            //Status.PrintSolution();
            //goto play;
            break;

        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"\nThe puzzle grid you enter is = \n";
            Sudoku.Print2dVec(PuzzleMatrix);
            if (Sudoku.SolveSudoku(PuzzleMatrix)){
                std::cout<<"The solution is = "<<std::endl;
                Sudoku.Print2dVec(PuzzleMatrix);
            }
            else{
                std::cout<<"Solution could not be obtained, check your problem."
                <<"\nNot enough clues were given to solve the puzzle."
                <<std::endl;
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
    play:
        


    
   
    return 0;
}