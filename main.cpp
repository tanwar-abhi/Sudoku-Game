// This is the main implementation file for the execution of suDokU

#include <iostream>
#include "Puzzle.h"

int main(){
    
    //2D vector that contains the Grid elements (9x9).
    std::vector<std::vector<int>> PuzzleMatrix(9, std::vector<int> (9));

    Puzzle Sudoku;
    Grid GameGrid;
    GameOver GameState;

    int playSelect = Sudoku.Welcome();

    try{
        if (playSelect != 1 && playSelect != 2 && playSelect != 3){
            throw "Game aborted!! Run the game again ";
        }
    }
    catch (const char* text){
        std::cout<<"You made an invalid choice. Please make an appropriate choice"<<std::endl;
        std::cout<<text<<std::endl;
        return 1;
    }

    switch (playSelect){
        case 1:
            Sudoku.PlayDemo();

        case 2:
            unsigned int clues ;
            GameGrid.DisplayMsg("Select puzzle difficulty level");
            clues = Sudoku.SelectLevel();

            // Generates Random puzzle and saves the solution in Status for future reference.
            Sudoku.GeneratePuzzle(PuzzleMatrix, GameState, clues);
            // Sudoku.GeneratePuzzle(PuzzleMatrix, GameState);
            GameGrid.DisplayMsg("Puzzle Generated");
            Sudoku.GamePlay(PuzzleMatrix, Sudoku, GameGrid, GameState);
            break;

        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"\nThe puzzle you entered is = \n";
            GameGrid.Print2dVec(PuzzleMatrix);
            if (Sudoku.SolveSudoku(PuzzleMatrix)){
                std::cout<<"The solution is = "<<std::endl;
                GameGrid.Print2dVec(PuzzleMatrix);
            }
            else{
                std::cout<<"Solution could not be obtained, check your problem."
                <<"\nNot enough clues were given to solve the puzzle."
                <<std::endl;
            }
    }
    return 0;
}
