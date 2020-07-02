// Implementation file for Game Over.

#include "GameOver.h"
#include <iostream>
#include <iomanip>

GameOver::GameOver(){
    //Default Constructor
}

GameOver::~GameOver(){
    //Default Destructor
}

// This function checks whether the grid is solved or not.
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

void GameOver::SetSolution(std::vector<std::vector<int>> Matrix){
    Solution = Matrix;
}


void GameOver::GameEnd(std::vector<std::vector<int>> GameVector){
    std::cout<<"If you are done with puzzle type 'end', type 'reset' to reset the same puzzle, "
             <<"Otherwise type 'play' to keep playing :: ";
    std::cin>>CurrentState;

    if (CurrentState == "end"){
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
    else if(CurrentState == "play" || CurrentState == "reset"){
        return;
    }
    else{
        std::cout<<std::right<<"Invalid choice \nEnter a selection again.\n";
        std::cin>>CurrentState;
    }
}


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