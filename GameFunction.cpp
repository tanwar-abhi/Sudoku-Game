// This File contains all the helping functions for smooth creation and working of the puzzle

#include <iostream>
#include <vector>

void aFuncCall(){
    std::cout<<"\nOk, so when this is called we know i can call a function from another file.\n";
}



void Print2dVec(std::vector<std::vector<int>> &Matrix){
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
void RandomMatrix(std::vector<std::vector<int>> &Mat){
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

