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
    for (int i=0;i<9;i++){
        for (int j=0; j<9; j++){
            if (j==8){
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


// Check by adding random value to random positions
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
    }*/
    

   for (int i=0;i<m;i++){
       for (int j=0; j<n; j++){
           Mat[i][j] = rand()%10;
       }
   }
}



// gives subsequent row and column numbers for the box pertaining to each element of sudoku.
void getBoxRCno(int RowNo, int ColNo, int &boxRN, int &boxCN){
    if (ColNo<3){
        if (RowNo<3){
            boxRN = 0, boxCN = 0;
        }
        else if(RowNo>2 && RowNo<6){
            boxRN = 3, boxCN = 0;
        }
        else{
            boxRN = 6, boxCN = 0;
        }
    }
    else if (ColNo>2 && ColNo<6){
        if (RowNo<3){
            boxRN = 0, boxCN = 3;
        }
        else if(RowNo>2 && RowNo<6){
            boxRN = 3, boxCN = 3;
        }
        else{
            boxRN = 6, boxCN = 3;
        }
    }
    else{
        if (RowNo<3){
            boxRN = 0, boxCN = 6;
        }
        else if(RowNo>2 && RowNo<6){
            boxRN = 3, boxCN = 6;
        }
        else{
            boxRN = 6, boxCN = 6;
        }
    }
}


bool Condition(std::vector<int> vec1D,int value){
    int count = 0;
    for (auto i=vec1D.begin(); i!=vec1D.end(); i++){
        if (*i == value){
            count++;
        }
    }
    switch (count){
    case 0:
        return false;
    default:
        return true;
    }
}


bool RowColBoxCheck(int RN ,int CN, int number, std::vector<std::vector<int>> Matrix){ 
    int m = Matrix.size();
    int n = Matrix[1].size();
    std::vector<int> RowVector, ColumnVector, BoxVector;
    RowVector = Matrix[RN];
    bool result[3];
    result[0] = Condition(RowVector,number);

    for (int j=0;j<m;j++){
        ColumnVector.push_back(Matrix[j][CN]);
    }
    result[1] = Condition(RowVector,number);

    // Row number and column nunber for the first element of the box matrix.
    int bRN, bCN, count=0;
    getBoxRCno(RN,CN,bRN, bCN);
    for (int k=bRN; k<bRN+3; k++){
        for (int j=bCN; j<bCN+3; j++){
            BoxVector.push_back(Matrix[k][j]);
        }
    }
    result[2] = Condition(BoxVector,number);
    for (int i=0; i<3;i++){
        if (result[i] == true){
            count++;
        }
    }

    switch (count){
    case 0:
        return false;
    default:
        return true;
    }
}


void Puzzle::GeneratePuzzle(std::vector<std::vector<int>> &Matrix){
    srand(time(NULL));
    int m = Matrix.size();
    int n = Matrix[1].size(),value;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            value = rand()%10;
            bool result = RowColBoxCheck(i,j,value,Matrix);
            while (result==true || value == 0){
                value = rand()%10;
                result = RowColBoxCheck(i,j,value,Matrix);
            }
            Matrix[i][j] = value;
        }
    }
}
