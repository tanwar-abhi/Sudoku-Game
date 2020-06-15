// Implementation file for Game Over check

#include "GameOver.h"
#include <iostream>

GameOver::GameOver(){
    //Default Constructor
}

GameOver::~GameOver(){
    //Default Destructor
}

// This function checks whether the grid is solved or not.
bool isGridFull(std::vector<std::vector <int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
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

bool GameOver::GameEnd(std::vector<std::vector<int>> Matrix){


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