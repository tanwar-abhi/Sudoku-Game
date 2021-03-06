// This is a file for implementation of grid
// It contains all the code and rountines used to build the aesthetical view of puzzle.

#include <iostream>
#include "Grid.h"
// <iomanip> is for the I/O manipulator for formating purpose {setw}
#include <iomanip>

Grid::Grid(){
    //Defalut Constructor
}

Grid::~Grid(){
    //Default Destructor
}

// Print puzzle matrix
void Grid::Print2dVec(std::vector<std::vector<int>> Matrix){
    int m = Matrix.size();
    for (int i = 0; i < m; i++){
        int n = Matrix[i].size();
        for (int j = 0; j < n; j++){
            if (j == n - 1){
                std::cout << Matrix[i][j] << std::endl;
            }
            else{
                std::cout << Matrix[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;
}


// This function is used to diplay a character on CLI as per user defined quantity.
void draw(int count, char text){
    for (int i=0; i<count; i++){
        std::cout<<text;
    }
}


// Creates an aesthetical grid of puzzle for user.
void Grid::makeGrid(std::vector<std::vector <int>> Ans){
    //Matrix is of size (m,n); "m" rows and "n" columns
    int m = Ans.size();
    for (int i=0; i<m; i++){
        int n = Ans[i].size();
        if (i==0 ){
            std::cout<<"|-----------|-----------|-----------|"<<std::endl;
        }
        for (int j=0; j<n; j++){
            if ( j == n-1){
                if (Ans[i][j] == 0){
                    std::cout<<' '<<" | "<<std::endl;
                }
                else{
                    std::cout<<Ans[i][j]<<" | "<<std::endl;
                }         
            }
            else if(j == 0){
                if (Ans[i][j] == 0){
                    std::cout<<"| "<<" "<<" : ";
                }
                else{
                    std::cout<<"| "<<Ans[i][j]<<" : ";
                }
            }
            else if ( j == 2 || j == 5){
                if (Ans[i][j] == 0){
                    std::cout<<' '<<" | ";
                }
                else{
                    std::cout<<Ans[i][j]<<" | ";
                }
            }
            else{
                if (Ans[i][j] == 0){
                    std::cout<<' '<<" : ";
                }
                else{
                    std::cout<<Ans[i][j]<<" : ";
                }         
            }
        }
        if (i == 2 || i == 5 ){
            std::cout<<"|~~~:~~~:~~~|~~~:~~~:~~~|~~~:~~~:~~~|"<<std::endl;
        }
        else if ( i == 8){
            std::cout<<"|-----------|-----------|-----------|"<<std::endl;
        }
        else{
            std::cout<<"|---:---:---|---:---:---|---:---:---|"<<std::endl;
        }
    }
    std::cout<<std::endl;
}


// Another function that prints the state message for the game, based on user selection.
void Grid::DisplayMsg(std::string userInput ){
    int n = userInput.length();
    //Setting output justification to be right alligned.
    std::cout<<"\n"<<std::setw(10); draw(40+n,'#');
    std::cout<<"\n"<<std::setw(10); draw(1,'#'); draw(40/2,' ');
    std::cout<<userInput;draw(36/2,' '); std::cout<<"#";
    std::cout<<"\n"<<std::setw(10); draw(40+n,'#');std::cout<<"\n\n";
}