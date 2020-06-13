// Implementation file for Game Over check

#include "GameOver.h"

GameOver::GameOver(){
    //Default Constructor
    
}

GameOver::~GameOver(){
    //Default Destructor
}

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

bool GameOver::GameEnd(std::vector<std::vector<int>> Matrix){
    

}