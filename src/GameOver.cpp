// Implementation file for Game Over.

#include "GameOver.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

GameOver::GameOver(){
    //Default Constructor
}

GameOver::~GameOver(){
    //Default Destructor
}

// This function checks if the grid is filled or not, return true if filled else fasle if anything empty.
bool isGridFull(std::vector<std::vector <int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (Matrix[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}


// Simply makes the copy of soution in another vector, it's used to check if puzzle solved correclty.
void GameOver::SetSolution(std::vector<std::vector<int>> Matrix){
    Solution = Matrix;
}


// Decides the state of game based on user input, states possible = end, solved, reset
// it user select solved then the puzzle matrix is passed to the function for checking.
void GameOver::GameEnd(std::vector<std::vector<int>> GameVector){
    std::cout<<"If you are done with puzzle type 'end', else type 'reset' to reset the same puzzle, "
             <<"Otherwise type 'play' to keep playing :: ";
    
    //std::cin>>CurrentState;
    CurrentState = "state";

    // Keeps on asking until user gives valid response.
    do{
	std::cout<<std::right<<"Invalid choice!! Enter a correct response.\n";
	std::cin>>CurrentState;
	std::transform(CurrentState.begin(), CurrentState.end(), CurrentState.begin(), ::toupper);
    }
    while(CurrentState!="END" && CurrentState!="RESET" && CurrentState!="PLAY");

    if (CurrentState == "END"){
        if (GameVector == Solution){
            CurrentState = "Solved";std::cout<<std::endl;
            std::cout<<std::setw(30)<<"Congratulations!! you solved the puzzle correctly.\n"<<std::endl;
        }
        else{
            CurrentState = "Wrong Solution!!!!";
            std::cout<<std::setw(50)<<" ~~~~~~~~~~ "<<CurrentState<<" ~~~~~~~~~~ "<<std::endl;
            PrintSolution();
        }
    }
    else if(CurrentState == "PLAY" || CurrentState == "RESET"){
        return;
    }
}


// Prints the actual solution of puzzle if played failed to solve puzzle.
void GameOver::PrintSolution(){
    std::cout<<"The solution to puzzle is = \n";
    int m = Solution.size();
    for (int i=0; i<m; i++){
        for (auto j=Solution[i].begin(); j!=Solution[i].end(); j++){
            if (j==Solution[i].end()-1){
                std::cout<< *j<<std::endl;
            }
            else{
                std::cout<< *j<<" ";
            }
        }
    }
    std::cout << std::endl;
}
