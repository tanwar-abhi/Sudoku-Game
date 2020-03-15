// This File contains all the helping functions for smooth creation and working of the puzzle

#include <iostream>
#include "Puzzle.h"
#include <ctime>
#include <algorithm>

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
    std::cout<<"General View of all elements of grid are as follows :\n"<<std::endl;
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

    /* Putting random values [0,9] at random positions of the matrix.
    int pos1,pos2;
    for (int i=0; i<70;i++){
        pos1 = (rand()%m);
        pos2 = (rand()%n);
        int value = rand()%10;
        Mat[pos1][pos2] = value;
    }
    */

   for (int i=0;i<m;i++){
       for (int j=0; j<n; j++){
           Mat[i][j] = rand()%10;
       }
   }
}


// gives subsequent box row and column numbers
void getBoxRCno(int RN, int CN, int &bRN, int &bCN){
    if (CN<3){
        if (RN<3){
            bRN = 0, bCN = 0;
        }
        else if(RN>2 && RN<6){
            bRN = 3, bCN = 0;
        }
        else{
            bRN = 6, bCN = 0;
        }

    }
    else if (CN>2 && CN<6){
        if (RN<3){
            bRN = 0, bCN = 3;
        }
        else if(RN>2 && RN<6){
            bRN = 3, bCN = 3;
        }
        else{
            bRN = 6, bCN = 3;
        }
        
    }
    else{
        if (RN<3){
            bRN = 0, bCN = 6;
        }
        else if(RN>2 && RN<6){
            bRN = 3, bCN = 6;
        }
        else{
            bRN = 6, bCN = 6;
        }
        
    }
}


bool Condition(std::vector<int> vec1D,int value){
    int count = 0;
    for (auto i=vec1D.begin(); i!=vec1D.end(); i++){
        if (*i == value){
            count += 1;
        }
    }
    switch (count){
    case 1:
        return true;
    
    default:
        return false;
    }
}


void RowColBoxCheck(int RN ,int CN, std::vector<std::vector<int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    std::vector<int> RowVector, ColumnVector, BoxVector;
    RowVector = Matrix[RN];

    for (int j=0;j<m;j++){
        ColumnVector.push_back(Matrix[j][CN]);
    }
    
    // Box Row number and column row nunber of the box matrix.
    int bRN, bCN;

    getBoxRCno(RN,CN,bRN, bCN);

    for (int k=bRN; k<bRN+3; k++){
        for (int j=bCN; j<bCN+3; j++){
            BoxVector.push_back(Matrix[k][j]);
        }
    }
}


void Puzzle::MakePuzzle(std::vector<std::vector<int>> &Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            Matrix[i][j] = rand()%10;

        }
    }
}
