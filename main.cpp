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
        return 0;
    }

    switch (playSelect){
        case 1:
            Sudoku.PlayDemo();

        case 2:
            // Generates Random puzzle and saves the solution in Status for future reference.
            Sudoku.GeneratePuzzle(PuzzleMatrix, Status);
            std::cout<<"Puzzle Generated = "<<std::endl;
            Sudoku.Print2dVec(PuzzleMatrix);
            goto play;
            break;

        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"\nThe puzzle you entered is = \n";
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
            return 0;

        default:
            break;
    }


   
   
    play:{
        Su1.makeGrid(PuzzleMatrix);
        std::cout<<"Enter position number, follower by value. i.e. (Row, Column, Digit{1-9})"<<std::endl;
        unsigned int count=0, playerResponse[3],x;
        while (std::cin>>x){
            playerResponse[count] = x;
            if (count==2){
                Sudoku.ResponseNumber(PuzzleMatrix, playerResponse);
                count = 0;
            }
            else{
                count++;
            }
        }
        /*std::cout<<x<<std::endl;
        std::cout<<"The puzzle current form = \n";
        Sudoku.Print2dVec(PuzzleMatrix);*/
        std::cout<<"Solution you entered = \n";
        Su1.makeGrid(PuzzleMatrix);
        Status.GameEnd();
        
    }
    
    
    
   
    return 0;
}