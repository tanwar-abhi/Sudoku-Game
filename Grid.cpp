// This is a file for implementation of grid

#include <iostream>
#include <vector>
#include "Grid.h"

Grid::Grid(){
    //Defalut Constructor
}


Grid::~Grid(){
    //Default Destructor
}

void Grid::makeGrid(std::vector<std::vector <int>> &Ans){
    std::cout<<"Initial grid for Sudoku is as follows :: "<<std::endl;
    //Matrix is of size (m,n); "m" rows and "n" columns
    int m = Ans.size();
    int n = Ans[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if ( j==n-1){
                std::cout<<Ans[i][j]<<" | "<<std::endl;
                std::cout<<"|---|---|---|---|---|---|---|---|---|"<<std::endl;
            }
            else if(j==0){
                std::cout<<"| "<<Ans[i][j]<<" | ";
            }
            else{
                std::cout<<Ans[i][j]<<" | ";
            }
        }
    }
}


void Grid::Print2dVec(std::vector<std::vector<int>> &Matrix){
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


void Grid::InitialGrid(std::vector<std::vector <int>> Ans){
    std::cout<<"Initial grid for Sudoku is as follows :: "<<std::endl;
    //Matrix is of size (m,n); "m" rows and "n" columns
    int m = Ans.size();
    int n = Ans[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if ( j==n-1){
                std::cout<<Ans[i][j]<<" | "<<std::endl;
            }
            else if(j==0){
                std::cout<<"| "<<Ans[i][j]<<" : ";
            }
            else if ( j==2 || j==5){
                std::cout<<""<<Ans[i][j]<<" | ";
            }
            
            else{
                std::cout<<Ans[i][j]<<" : ";
            }
        }
        if (i==2 || i==5 ){
            std::cout<<"|~~~:~~~:~~~|~~~:~~~:~~~|~~~:~~~:~~~|"<<std::endl;
            
        }
        else if ( i==8){
            std::cout<<"|-----------|-----------|-----------|"<<std::endl;
        }
        else{
            std::cout<<"|---:---:---|---:---:---|---:---:---|"<<std::endl;
        }
    }
}