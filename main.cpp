// This is the main implementation file for the execution of suDokU

#include <iostream>
#include <vector>
#include "Grid.h"
#include <ctime>
#include "GameFunction.cpp"

int main(){
    
    srand(time(NULL));

    std::cout<<"Welcome to the game of Sudoku, My Friend"<<std::endl;
    int m = 9 , n = 9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector <int>> Puzzle(m, std::vector<int> (n));

    Print2dVec(Puzzle);
    RandomMatrix(Puzzle);
    Print2dVec(Puzzle);
    

    Grid Su1;
    aFuncCall();
    //Su1.makeGrid(Answers);
    //Su1.InitialGrid(Answers);

   
    return 0;
}