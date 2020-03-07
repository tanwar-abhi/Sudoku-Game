// This File contains all the helping functions for smooth creation and working of the puzzle

#include <iostream>
#include "Puzzle.h"
#include <ctime>

//Default emplty constructor
Puzzle::Puzzle(){
    // Defalut constructor
}

Puzzle::~Puzzle(){
    //Default Destructor
}

void Puzzle::Welcome(){
    std::cout<<"\n#####################################################\n#\n# *** Welcome to the game of Sudoku, My Friend ****\n#\n#####################################################\n\n";
    std::cout<<"Press 1 for Instructions on playing\nPress 2 to directly start playing\n";
    int x;
    std::cin>>x;
    switch (x){
    case 1:
        Puzzle::PlayDemo();
        break;
    
    default:
        break;
    }
}


void Puzzle::PlayDemo(){
    std::cout<<"\nThe Grid is a 2D matrix of (m*n), i.e. 'm' rows and 'n' columns\n"<<std::endl;
    std::cout<<"General View of all elements of grid are as follows:\n"<<std::endl;
    for (int i=1;i<10;i++){
        for (int j=1; j<10; j++){
            if (j==9){
                std::cout<<i<<j<<std::endl;
            }
            else{
                std::cout<<i<<j<<",";
            }
        }
    }
    std::cout<<"\nSo to play enter the postion of each element first (m,n) then, value to be added in puzzle.";
    std::cout<<"For Example :: to enter value 5 at 3rd row, 4th column write '3 4 5'{should be space seperated}\n"<<std::endl;
}


void Puzzle::Print2dVec(std::vector<std::vector<int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    std::cout<<"The matrix is as follows :: "<<std::endl;
    for (int i=0; i<m;i++){
        for (int j=0; j<n;j++){
            if (j==n-1){
                std::cout<<Matrix[i][j]<<std::endl;
            }
            else{
                std::cout<<Matrix[i][j]<<" ";
            }
        }
    }
}


//Check by adding random value to random positions
void Puzzle::RandomMatrix(std::vector<std::vector<int>> &Mat){
    srand(time(NULL));
    int m = Mat.size();
    int n = Mat[1].size();
    int pos1,pos2;
    for (int i=0; i<70;i++){
        pos1 = (rand()%m);
        pos2 = (rand()%n);
        int value = rand()%10;
        Mat[pos1][pos2] = value;
    }
}

void Puzzle::PuzzleSetup(std::vector<std::vector<int>> &Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    for (int i=0; i<m; i++){
        std::vector<int> aVec = Matrix[m];

    }
    


}