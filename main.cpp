// This is the main implementation file for the execution of suDokU

#include <iostream>
#include "Grid.h"
#include "Puzzle.h"
#include "GameOver.h"

int main(){
    
    //2D vector that contains the Grid elements (9x9).
    std::vector<std::vector<int>> PuzzleMatrix(9, std::vector<int> (9));

    Puzzle Sudoku;
    Grid SuPuzzle;
    GameOver State;

    int playSelect;
    playSelect = Sudoku.Welcome();

    try{
        if (playSelect!=1 && playSelect!=2 && playSelect!=3){
            throw "Game aborted!! Run the game again ";
        }
    }
    catch (const char* text){
        std::cout<<"You made an invalid choice. Please make an appropriate choice"<<std::endl;
        std::cout<<text<<std::endl;
        return 0;
    }

    switch (playSelect){
        case 1:
            Sudoku.PlayDemo();

        case 2:
            // Generates Random puzzle and saves the solution in Status for future reference.
            Sudoku.GeneratePuzzle(PuzzleMatrix, State);
            std::cout<<"Generated Puzzle = "<<std::endl;
            SuPuzzle.Print2dVec(PuzzleMatrix);
            goto play;
            break;

        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"\nThe puzzle you entered is = \n";
            SuPuzzle.Print2dVec(PuzzleMatrix);
            if (Sudoku.SolveSudoku(PuzzleMatrix)){
                std::cout<<"The solution is = "<<std::endl;
                SuPuzzle.Print2dVec(PuzzleMatrix);
            }
            else{
                std::cout<<"Solution could not be obtained, check your problem."
                <<"\nNot enough clues were given to solve the puzzle."
                <<std::endl;
            }
            return 0;

        default:
            break;
    }


   
   
    play:{
        SuPuzzle.makeGrid(PuzzleMatrix);
        std::cout<<"Enter position number, follower by value. i.e. (Row, Column, Digit{1-9})"
                 <<"\nOnce completed puzzle or if you wish to exit enter any non integer value."
                 <<std::endl;
        unsigned int count=0, playerResponse[3],x;
        while (std::cin>>x){
            playerResponse[count] = x;
            if (count==2){
                Sudoku.AddResponse(PuzzleMatrix, playerResponse);
                count = 0;
                //SuPuzzle.Print2dVec(PuzzleMatrix);
                SuPuzzle.makeGrid(PuzzleMatrix);
            }
            else{
                count++;
            }
        }

        std::cin.ignore();
        std::cout<<"Solution you entered = \n";
        SuPuzzle.Print2dVec(PuzzleMatrix);
        //SuPuzzle.makeGrid(PuzzleMatrix);
        
        /*Problem below*/
        State.GameEnd(PuzzleMatrix);
        std::cout<<State.CurrentState<<std::endl;
        
        
    }
    
    
    return 0;
}