// This File contains all the helping functions for smooth creation and working of the puzzle

#include <iostream>
#include "Puzzle.h"
#include <ctime>
// <iomanip> is for the manipulator using "setw" for adding width{formating purpose}
#include <iomanip>
//#include <algorithm>

// Global vector to track the possible elements in a row.
std::vector<int> ElementTracker;


//Default emplty constructor
Puzzle::Puzzle(){
    // Defalut constructor
    
}

Puzzle::~Puzzle(){
    //Default Destructor
}

void Puzzle::Welcome(std::vector<std::vector<int>> &Vector2D){
    //Generated random seed for random number creation.
    srand(time(NULL));

    std::cout<<"\n############################################################\n";
    std::cout<<"#"<<std::setw(60)<<"#\n";
    std::cout<<"#    *** Welcome to the game of Sudoku, My Friend ****"<<std::setw(6)<<"#"<<std::endl;
    std::cout<<"#"<<std::setw(59)<<"#"<<std::endl;
    std::cout << "############################################################\n"<<std::endl;

    std::cout<<"Press 1 for Instructions on playing"
            <<"\nPress 2 to randomly generate puzzle and start playing"
            <<"\nPress 3 to enter a user defined puzzle which will be solved by the solver"
            <<std::endl;
    int x;
    std::cin >> x;
    switch (x){
    case 1:
        Puzzle::PlayDemo();
        break;
    case 3:
        UserPuzzle(Vector2D);
    default:
        break;
    }
}

void Puzzle::PlayDemo(){
    std::cout << "\nThe Grid is a 2D matrix of (9x9), i.e. 9 rows and 9 columns\n"
              << std::endl;
    std::cout << "General View of all elements of grid are as follows :\n"
              << std::endl;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (j == 8){
                std::cout << i << j << std::endl;
            }
            else{
                std::cout << i << j << ",";
            }
        }
    }
    std::cout << "\nSo to play enter the postion of each element first (m,n) then, value to be added in puzzle.";
    std::cout << "For Example :: to enter value 5 at 3rd row, 4th column write '3 4 5'{should be space seperated}\n"
              << std::endl;
}

void Puzzle::Print2dVec(std::vector<std::vector<int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    std::cout << "The matrix is as follows :: " << std::endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j == n - 1){
                std::cout << Matrix[i][j] << std::endl;
            }
            else{
                std::cout << Matrix[i][j] << " ";
            }
        }
    }
}


void printMatrix(std::vector<std::vector<int>> Mat){
    int m = Mat.size();
    int n = Mat[1].size();
    std::cout<<"The matrix is :: "<<std::endl;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (j==n-1){
                std::cout<<Mat[i][j]<<std::endl;
            }
            else{
                std::cout<<Mat[i][j]<<" ";
            }
        }
    }
}


bool isGridSolved(std::vector<std::vector <int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[0].size();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (Matrix[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}



// Simply checks whether value is present in the vector or not. Called from RowColBoxCheck
bool Condition(std::vector<int> vec1D, int value){
    for (auto i = vec1D.begin(); i != vec1D.end(); i++){
        if (*i == value){
            return true;
        }
    }
    return false;
}


// This function checks the constraint condition that must always be satisfied to fill the value
// in puzzle grid, i.e value should not already be present in row, colum or box
// This function returns "True" if number is present in either Row,Column or box. Otherwise returns "false".
bool RowColBoxCheck(int RN, int CN, int number, std::vector<std::vector<int>> Matrix){
    int m = Matrix.size();
    int n = Matrix[1].size();
    std::vector<int> RowVector, ColumnVector, BoxVector;
    RowVector = Matrix[RN];
    bool result[3];
    result[0] = Condition(RowVector, number);

    for (int j = 0; j < m; j++){
        ColumnVector.push_back(Matrix[j][CN]);
    }
    result[1] = Condition(ColumnVector, number);

    // Row number and column nunber for the first element of the box matrix.
    int count = 0;
    
    int bRN = (RN/3)*3;
    int bCN = (CN/3)*3;
    for (int k = bRN; k < bRN + 3; k++){
        for (int j = bCN; j < bCN + 3; j++){
            BoxVector.push_back(Matrix[k][j]);
        }
    }
    result[2] = Condition(BoxVector, number);
    for (int i = 0; i < 3; i++){
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



void setDiagonalBox(std::vector<std::vector<int>> &Matrix){

    //Right diagonal box fill
    std::vector<int> boxDiaElement = {0, 3, 6};
    for (auto i = boxDiaElement.begin(); i != boxDiaElement.end(); i++){
        for (int k = *i; k < *i+3; k++){
            for (int j = *i; j < *i+3; j++){
                int value = Matrix[k][j];
                bool result = RowColBoxCheck(k, j, value, Matrix);
                int iteration = 0;
                while (result){
                    iteration++;
                    value = rand() % 10;
                    result = RowColBoxCheck(k, j, value, Matrix);
                    /*
                    if (iteration>500){
                        ResetBox(Matrix,k,j,iteration);
                    }
                    */
                }
                Matrix[k][j] = value;
            }
        }
    }
}




void Puzzle::GeneratePuzzle(std::vector<std::vector<int>> &Matrix){
    //puzzleBoxFill(Matrix,0,0);


}




void Puzzle::UserPuzzle(std::vector<std::vector<int>> &Matrix){
    /*
    std::cout<<"Enter the digits( with spaces after each digit) of your puzzle you wish to solve\nStarting from top left corner keep on entering the digits"<<std::endl;
    std::cout<<"Enter '0' to signify the blank spaces in the puzzle."<<std::endl;
    int digit;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            std::cin>>digit;
            Matrix[i][j] = digit;
        }
    }
    Initially for checking lets enter a puzzle whose solution we already know.
    */
   Matrix = {{0,0,0,0,5,0,0,4,0},
            {0,0,6,7,4,1,2,8,5},
            {4,8,0,9,0,0,0,0,6},
            {2,0,0,0,6,0,0,0,0},
            {0,9,8,1,0,2,5,6,0},
            {0,0,0,0,9,0,0,0,7},
            {3,0,0,0,0,9,0,1,2},
            {8,7,2,3,1,6,4,0,0},
            {0,1,0,0,7,0,0,0,0}};
}



bool Puzzle::SolveSudoku(std::vector<std::vector<int>> &Matrix){
    int m = Matrix.size();
    int n = Matrix[0].size();

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (Matrix[i][j] == 0){
                for (int value = 1; value<10; value++ ){
                    bool result = RowColBoxCheck(i,j,value,Matrix);
                    if (result == false){
                        //ElementTracker.push_back(value);
                        Matrix[i][j] = value;
                        if (isGridSolved(Matrix)){
                            return true; 
                        }
                        if (SolveSudoku(Matrix)){
                            return true;
                        }
                        else{
                            Matrix[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
}




/*

void FillRow(std::vector<std::vector<int>> &Vector2D, int RowN, int ColN){
    int m = Vector2D.size();
    int n = Vector2D[1].size();
    int value;
    for (int i=0; i<m; i++ ){
        for (int j=0; j<n; j++){
            if (i==0){
                value = rand()%10;
                bool result = RowColBoxCheck(i,j,value,Vector2D);
                while(result){
                    value = rand()%10;
                    result = RowColBoxCheck(i,j,value,Vector2D);
                }
                Vector2D[i][j] = value;
            }
            else{
                for (int value=1; value<10; value++){
                    bool result = RowColBoxCheck(i,j,value,Vector2D);
                    if (result == false){
                        Vector2D[i][j] = value;
                        break;
                    }
                }
                if(value==9){
                        //Run BackTracking Algorithm here.
                }
         
            }
        }
    }
}





void setNonDiagonalElements(std::vector<std::vector<int>> &Matrix){
    srand(time(NULL));
 
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if ( Matrix[i][j] == 0 ){
                int num = rand()%10;
                bool result = RowColBoxCheck(i,j,num,Matrix);
                Matrix[i][j] = num;
                int iter = 0;
                while (result){
                    iter++;
                    num = rand()%10;
                    result = RowColBoxCheck(i,j,num,Matrix);
                    Matrix[i][j] = num;
                    if (iter>500){
                        ResetBox(Matrix,i,j,iter);
                    }
                }
                printMatrix(Matrix);
            }
        }
    }
}




void FillbyRow(std::vector<std::vector<int>> &vec2D ){
    
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (vec2D[i][j] == 0){
                int value = rand()%10;
                bool result = RowColBoxCheck(i,j,value,vec2D);
                vec2D[i][j] = value;
                int iteration = 0;
                while (result){
                    iteration++;
                    value = rand()%10;
                    result = RowColBoxCheck(i,j,value,vec2D);
                    vec2D[i][j] = value;
                    if (iteration>500){
                        std::cout<<"Stuck here\nPosition :: "<<i<<","<<j<<";\nValue = "<<value<<std::endl;
                        printMatrix(vec2D);
                        ResetBox(vec2D,i,j,iteration);
                    }
                }
            }
        }
        //printMatrix(vec2D);
    }

} 


bool BinarySearch(std::vector<int> vec1D, int value){
    int start = 0, end = vec1D.size()-1;
    while (start<=end){
        int mid = (start+end)/2;
        if (vec1D[mid] == value ){
            return true;
        }
        else if (vec1D[mid]>value){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return false;
}




void puzzleBoxFill(std::vector<std::vector<int>> &vec2D, int RowN, int ColN){
    for (int i=RowN; i<RowN+3; i++){
        for (int j=ColN; j<ColN+3; j++){
            int value = rand()%10, iteration = 0;
            bool result = RowColBoxCheck(i,j,value,vec2D);
            while (result){
                iteration++;
                value = rand()%10;
                result = RowColBoxCheck(i,j,value,vec2D);
                if (iteration>500){
                    ResetBox(vec2D,i,j,iteration);
                }
            }
            vec2D[i][j] = value;
        }
    }
}



// If there is a conflict then reset that box(block of sudoku puzzle) and try again.
void ResetBox(std::vector<std::vector<int>> &Vector2D, int &RowN, int &ColN, int &iter){
    int BoxRN, BoxCN;
    getBoxRCno(RowN, ColN, BoxRN, BoxCN);
    for (int i = BoxRN; i < BoxRN + 3; i++){
        for (int j = BoxCN; j < BoxCN + 3; j++){
            Vector2D[i][j] = 0;
        }
    }
    // After resetting the box, reset row, column number, iteration to resume from first element of resetted box.
    RowN = BoxRN;
    ColN = BoxCN;
    iter = 1;
}



*/