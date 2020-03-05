// This is the main implementation file for the execution of suDokU

#include <iostream>
#include <vector>
#include "Grid.h"
#include "Puzzle.h"

int main(){
    
    srand(time(NULL));

    std::cout<<"\nWelcome to the game of Sudoku, My Friend\n#########################\n"<<std::endl;
 
    //2D vector that contains the Grid elements.

    Puzzle *SuPuzzle = new Puzzle();

    SuPuzzle->Print2dVec(SuPuzzle->Matrix);

    /*
    Print2dVec(Puzzle);
    RandomMatrix(Puzzle);
    Print2dVec(Puzzle);
    */



    Grid Su1;
    //Su1.makeGrid(Answers);
    //Su1.InitialGrid(Answers);

   
    return 0;
}