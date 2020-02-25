// This is the main implementation file for the execution of suDokU


#include <iostream>
#include <vector>
#include "Grid.h"
#include <string>

int main(){
    std::cout<<"Welcome to the game of Sudoku, My Friend"<<std::endl;
    int m = 9 , n = 9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector <int>> Answers(m, std::vector<int> (n));

    for (int i=0; i<m; i++){
        for (int j=0;j<n;j++){
            Answers[i][j] = 0;
        }
    }


    /*
    std::cout<<"Vector is as follows :: "<<std::endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if ( j==n-1){
                std::cout<<Answers[i][j]<<" | "<<std::endl;
                std::cout<<"--|---|---|---|---|---|---|---|---|"<<std::endl;
                
            }
            else{
                std::cout<<Answers[i][j]<<" | ";
            }

        }
    }
    */

   Grid Su1;
   Su1.makeGrid(Answers);
   



    return 0;
}