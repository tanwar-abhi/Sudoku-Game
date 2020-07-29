// This is the main implementation file for the execution of suDokU

#include <iostream>
#include "Grid.h"
#include "Puzzle.h"
#include "GameOver.h"
// <iomanip> is for the I/O manipulator for formating purpose {setw}
#include <iomanip>


int main(){
    
    //2D vector that contains the Grid elements (9x9).
    std::vector<std::vector<int>> PuzzleMatrix(9, std::vector<int> (9));

    Puzzle Sudoku;
    Grid SuGrid;
    GameOver State;

    int playSelect = Sudoku.Welcome();

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
            std::cout<<"\n  Puzzle Generated  \n"<<std::endl;
            goto play;
            break;

        case 3:
            Sudoku.UserPuzzle(PuzzleMatrix);
            std::cout<<"\nThe puzzle you entered is = \n";
            SuGrid.Print2dVec(PuzzleMatrix);
            if (Sudoku.SolveSudoku(PuzzleMatrix)){
                std::cout<<"The solution is = "<<std::endl;
                SuGrid.Print2dVec(PuzzleMatrix);
            }
            else{
                std::cout<<"Solution could not be obtained, check your problem."
                <<"\nNot enough clues were given to solve the puzzle."
                <<std::endl;
            }
            return 0;
    }


    play:{
        SuGrid.makeGrid(PuzzleMatrix);
        std::cout<<"Enter position number, follower by value. i.e. (Row, Column, Digit{1-9})"
                 <<"\nOnce completed puzzle or if you wish to exit, enter any non integer value."
                 <<std::endl;
        unsigned int count=0, playerResponse[3];
        std::string x;
        while (std::cin>>x){
            try{
                playerResponse[count] = stoi(x);
            }
            catch(...){
                break;
            }
            if (count==2){
                Sudoku.AddResponse(PuzzleMatrix, playerResponse);
                count = 0;
                SuGrid.makeGrid(PuzzleMatrix);
            }
            else{
                count++;
            }
        }

        std::cout<<"Solution you entered = \n";
        SuGrid.Print2dVec(PuzzleMatrix);
        
        State.GameEnd(PuzzleMatrix);
        //std::cout<<State.CurrentState<<std::endl;
        if (State.CurrentState == "play"){
            goto play;
        }
        else if (State.CurrentState == "reset"){
            Sudoku.Reset(PuzzleMatrix);
            goto play;
        }
        else{
            std::cout<<std::setw(30); SuGrid.Draw(60,'#'); std::cout<<std::endl;
            std::cout<<std::setw(30);SuGrid.Draw(1,'#');SuGrid.Draw(24,' ');std::cout<<"Game Over!";
            SuGrid.Draw(24,' ');SuGrid.Draw(1,'#');std::cout<<std::endl;
            std::cout<<std::setw(30); SuGrid.Draw(60,'#'); std::cout<<std::endl;          
        }
    }
    
    return 0;
}