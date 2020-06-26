// This File contains all the helping functions for smooth creation and working of the puzzle

#include <iostream>
#include "Puzzle.h"
// The header for computer time {ctime}, used for generating seeds for random numbers.
#include <ctime>
// <iomanip> is for the I/O manipulator for formating purpose {setw}
#include <iomanip>


Puzzle::Puzzle(){
    // Defalut constructor  
}

Puzzle::~Puzzle(){
    //Default Destructor
}

int Puzzle::Welcome(){
    //Generate random seeds for random number creation.
    srand(time(NULL));

    std::cout<<"\n############################################################\n";
    std::cout<<"#"<<std::setw(60)<<"#\n";
    std::cout<<"#    *** Welcome to the game of Sudoku, My Friend ****"<<std::setw(6)<<"#"<<std::endl;
    std::cout<<"#"<<std::setw(59)<<"#"<<std::endl;
    std::cout << "############################################################\n"<<std::endl;

    std::cout<<"Press 1 for Instructions on how to play."
            <<"\nPress 2 to randomly generate puzzle and start playing"
            <<"\nPress 3 to enter a user defined puzzle which will be solved by the solver"
            <<std::endl;
    int x;
    std::cin >> x;
    return x;
}

void Puzzle::PlayDemo(){
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout<<std::setw(50)<<"Rules of Sudoku\n";
    std::cout<<"The classic Sudoku game involves a grid of 81 cells.\n"
             <<"Each row, column and square (9 spaces each) needs to be filled out with the numbers 1-9,"
             <<"\nwithout repeating any numbers within the row, column or square (box of 3x3).\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "\nThe Grid is a 2D matrix of (9x9), i.e. 9 rows and 9 columns\n"
              << std::endl;
    std::cout << "General View of all elements of grid are as follows :\n"
              << std::endl;
    for (int i = 1; i < 10; i++){
        for (int j = 1; j < 10; j++){
            if (j == 9){
                std::cout << i << j << std::endl;
            }
            else{
                std::cout << i << j << ",";
            }
        }
    }
    std::cout << "\nSo to play enter the postion of each element first (m,n) then, value to be added in puzzle.\n";
    std::cout << "For Example :: to enter value 5 at 3rd row, 4th column write '3 4 5'{should be space seperated}\n"
              << std::endl;
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
// This returns "True" if number is present in either Row,Column or box. Otherwise returns "false".
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
            return true;
        }
    }
    return false;
}


// Randomly fills the grid box of puzzle, required argument, box's staring row and colum numbers.
void puzzleBoxFill(std::vector<std::vector <int>> &Matrix,int Row, int Col){
    for (int i=Row; i<Row+3; i++){
        for (int j=Col; j<Col+3; j++){
            int number = rand()%10;
            while (RowColBoxCheck(Row,Col,number, Matrix)){
                number = rand()%10;
            }
            Matrix[i][j] = number;
        }
    }
}


void Puzzle::GeneratePuzzle(std::vector<std::vector<int>> &Matrix, GameOver &GameState){
    
    //Randomly fill 3x3 first box to initialize the puzzle so that each generated puzzle is different.
    puzzleBoxFill(Matrix,0,0);
    if (SolveSudoku(Matrix)){
        GameState.SetSolution(Matrix);
    }
    else{
        std::cout<<"Puzzle Generation failed!!!!!"<<std::endl;
    }
    
    unsigned int i,j,clues = 40;
    // Randomly removes elements till defined clues are remaining in the puzzle.
    for (int x=0; x<81-clues; x++){
        // rand()%number will generate random number in range [0,number-1].
        i = rand()%9;
        j = rand()%9;
        while (Matrix[i][j] == 0){
            i = rand()%9;
            j = rand()%9;
        }
        Matrix[i][j] = 0; 
    }

    for (i=0;i<9;i++){
        for (j=0; j<9; j++){
            if (Matrix[i][j] != 0){
                FixedPosition[i][j] = Matrix[i][j];
            }
        }
    }

    /*
    for (auto itr = FixedPosition.begin(); itr!=FixedPosition.end(); itr++){
        for (auto ptr = itr->second.begin(); ptr!=itr->second.end(); ptr++){
            std::cout<<itr->first<<" "<<ptr->first<<" "<<ptr->second<<",";
        }
    }
    std::cout<<std::endl;
    */
}



// Enter user defined puzzle to be solved by the algorithm.
void Puzzle::UserPuzzle(std::vector<std::vector<int>> &Matrix){
    
    std::cout<<"Enter the digits( with spaces after each digit) of your puzzle you wish to solve\nStarting from top left corner keep on entering the digits"<<std::endl;
    std::cout<<"Enter '0' to signify the blank spaces in the puzzle."<<std::endl;
    int digit;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            std::cin>>digit;
            Matrix[i][j] = digit;
        }
    }
  
    /* Initially for checking lets enter a puzzle whose solution we already know.
    
    Matrix = {{0,0,0,0,5,0,0,4,0},
            {0,0,6,7,4,1,2,8,5},
            {4,8,0,9,0,0,0,0,6},
            {2,0,0,0,6,0,0,0,0},
            {0,9,8,1,0,2,5,6,0},
            {0,0,0,0,9,0,0,0,7},
            {3,0,0,0,0,9,0,1,2},
            {8,7,2,3,1,6,4,0,0},
            {0,1,0,0,7,0,0,0,0}};
            */
    
}


// Recursively calling the SolveSudoku function and empolying backtracking to solve grid.
bool Puzzle::SolveSudoku(std::vector<std::vector<int>> &Matrix){
    int m = Matrix.size();

    for (int i=0; i<m; i++){
        int n = Matrix[i].size();
        for (int j=0; j<n; j++){
            if (Matrix[i][j] == 0){
                for (int value = 1; value<10; value++ ){
                    if (!RowColBoxCheck(i,j,value,Matrix)){
                        Matrix[i][j] = value;
                    
                        if (SolveSudoku(Matrix)){
                            return true;
                        }
                        else{
                            Matrix[i][j] = 0;
                        }
                    }
                }
                // This triggers backtracking
                return false;
            }
        }
    }
}



void Puzzle::AddResponse(std::vector<std::vector<int>> &Matrix, unsigned int array[]){
    //Setting user responses to allign with index of Puzzle Matrix.
    for (int i=0; i<2; i++){
        array[i] -= 1;
    }

    // Check if incorrect grid positions are entered {by mistake}
    try{
        if (array[0]>8 || array[1]>8){
            throw "Rows and colums number should only be in range [1,9].";
        }
    }
    catch(const char* text){
        std::cout<<"Invalid position selected."<<std::endl;
        std::cout<<text<<std::endl;
        return;
    }


    if (Matrix[array[0]][array[1]] == 0){
        Matrix[array[0]][array[1]] = array[2];
    }
    else if(Matrix[array[0]][array[1]] != FixedPosition[array[0]][array[1]] ){
        Matrix[array[0]][array[1]] = array[2];
    }
    else{
        std::cout<<"This is a clue and can't be changed by player."
                 <<"Select only empty positions to fill."<<std::endl;
    }
}

