// This is the main implementation file for the execution of suDokU

#include <iostream>
#include <vector>
#include "Grid.h"
#include "Puzzle.h"

int main(){

    Puzzle SuPuzzle;
    SuPuzzle.Welcome();
 
    int m=9, n=9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector<int>> PuzzleMatrix(m, std::vector<int> (n));
    
    
    SuPuzzle.Print2dVec(PuzzleMatrix);
    SuPuzzle.RandomMatrix(PuzzleMatrix);
    SuPuzzle.Print2dVec(PuzzleMatrix);



    Grid Su1;
    //Su1.makeGrid(Answers);
    //Su1.InitialGrid(Answers);

   
    return 0;
}