// This is the main implementation file for the execution of suDokU


#include <iostream>
#include <vector>
#include "Grid.h"
#include <ctime>

int main(){
    
    srand(time(NULL));

    std::cout<<"Welcome to the game of Sudoku, My Friend"<<std::endl;
    int m = 9 , n = 9;
    //2D vector that contains the Grid elements.
    std::vector<std::vector <int>> Answers(m, std::vector<int> (n));

    for (int i=0; i<m; i++){
        for (int j=0;j<n;j++){
            Answers[i][j] = 0;
        }
    }

    //Check by adding random value to random positions
    int pos1,pos2;
    for (int i=0; i<70;i++){

        pos1 = (rand()%m);
        pos2 = (rand()%n);
        int value = rand()%10;
        //std::cout<<"\n ######## CHEECKPOINT ####### \n"<<pos1<<" "<<pos2<<" "<<value;
        Answers[pos1][pos2] = value;
    }
    
    Grid Su1;

    Su1.Print2dVec(Answers);

    //Su1.makeGrid(Answers);
    Su1.InitialGrid(Answers);

   
    return 0;
}