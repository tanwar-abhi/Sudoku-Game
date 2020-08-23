// This is the main implementation file for the execution of suDokU

#include <iostream>
#include "Grid.h"
#include "Puzzle.h"
#include "GameOver.h"

void GamePlay(std::vector<std::vector<int>> &, Puzzle &, Grid &, GameOver &);


int main(){
    
    //2D vector that contains the Grid elements (9x9).
    std::vector<std::vector<int>> PuzzleMatrix(9, std::vector<int> (9));

    Puzzle Sudoku;
    Grid GameGrid;
    GameOver GameState;

    int playSelect = Sudoku.Welcome();

    try{
        if (playSelect!=1 && playSelect!=2 && playSelect!=3){
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
            // Generates Random puzzle and saves the solution in Status for future reference.
            Sudoku.GeneratePuzzle(PuzzleMatrix, GameState);
            GameGrid.DisplayMsg("Puzzle Generated");
            GamePlay(PuzzleMatrix, Sudoku, GameGrid, GameState);
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
            return 0;
    }
    
    return 0;
}




void GamePlay(std::vector<std::vector<int>> &PuzzleMatrix, Puzzle &Sudoku, Grid &SuGrid, GameOver &State){

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

    if (State.CurrentState == "play"){
        //goto play
        GamePlay(PuzzleMatrix, Sudoku, SuGrid, State);
        }
    else if (State.CurrentState == "reset"){
        Sudoku.Reset(PuzzleMatrix);
        SuGrid.DisplayMsg("Puzzle Reseted to initial state");
        //goto play;
        GamePlay(PuzzleMatrix, Sudoku, SuGrid, State);
    }
    else{
        SuGrid.DisplayMsg("Game Over!");
    }

}
