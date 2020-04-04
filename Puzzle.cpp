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
    std::cout << "\n#####################################################\n#\n# *** Welcome to the game of Sudoku, My Friend ****\n#\n#####################################################\n\n";
    std::cout << "Press 1 for Instructions on playing\nPress 2 to directly start playing\n";
    int x;
    std::cin >> x;
    switch (x){
    case 1:
        Puzzle::PlayDemo();
        break;
    default:
        break;
    }
}

void Puzzle::PlayDemo(){
    std::cout << "\nThe Grid is a 2D matrix of (m*n), i.e. 'm' rows and 'n' columns\n"
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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Mat[i][j] = rand() % 10;
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


// gives subsequent row and column numbers for the box pertaining to each element of sudoku.
void getBoxRCno(int RowNo, int ColNo, int &boxRN, int &boxCN){
    if (ColNo < 3){
        if (RowNo < 3){
            boxRN = 0, boxCN = 0;
        }
        else if (RowNo > 2 && RowNo < 6){
            boxRN = 3, boxCN = 0;
        }
        else{
            boxRN = 6, boxCN = 0;
        }
    }
    else if (ColNo > 2 && ColNo < 6){
        if (RowNo < 3){
            boxRN = 0, boxCN = 3;
        }
        else if (RowNo > 2 && RowNo < 6){
            boxRN = 3, boxCN = 3;
        }
        else{
            boxRN = 6, boxCN = 3;
        }
    }
    else{
        if (RowNo < 3){
            boxRN = 0, boxCN = 6;
        }
        else if (RowNo > 2 && RowNo < 6){
            boxRN = 3, boxCN = 6;
        }
        else{
            boxRN = 6, boxCN = 6;
        }
    }
}


bool Condition(std::vector<int> vec1D, int value){
    int count = 0;
    for (auto i = vec1D.begin(); i != vec1D.end(); i++){
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
    int bRN, bCN, count = 0;
    getBoxRCno(RN, CN, bRN, bCN);
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


// If there is a conflict then reset that box(block of sudoku puzzle) and try again.
void ResetBox(std::vector<std::vector<int>> &Vector2D, int &RowN, int &ColN, int &iter){
    int BoxRN, BoxCN;
    getBoxRCno(RowN, ColN, BoxRN, BoxCN);
    for (int i = BoxRN; i < BoxRN + 3; i++){
        for (int j = BoxCN; j < BoxCN + 3; j++){
            Vector2D[i][j] = 0;
        }
    }
    RowN = BoxRN;
    ColN = BoxCN;
    iter = 1;
}


void setDiagonalBox(std::vector<std::vector<int>> &Matrix){
    srand(time(NULL));
    //Right diagonal box fill
    std::vector<int> boxDiaElement = {0, 3, 6};
    for (auto i = boxDiaElement.begin(); i != boxDiaElement.end(); i++){
        for (int k = *i; k < *i + 3; k++){
            for (int j = *i; j < *i + 3; j++){
                int value = Matrix[k][j];
                bool result = RowColBoxCheck(k, j, value, Matrix);
                int iteration = 0;
                while (result){
                    iteration++;
                    value = rand() % 10;
                    result = RowColBoxCheck(k, j, value, Matrix);
                    Matrix[k][j] = value;
                    if (iteration>500){
                        ResetBox(Matrix,k,j,iteration);
                    }
                }
            }
        }

    }

    /*
    boxDiaElement = {0, 6};
    for (auto i=boxDiaElement.begin(); i!=boxDiaElement.end(); i++){
        // Left Digonal box elementss
        if (*i == 0){
            for (int l = *i; l<*i+3; l++){
                for (int m = 6; m < 9; m++){
                    int value = Matrix[l][m];
                    bool result = RowColBoxCheck(l, m, value, Matrix);
                    int iteration = 0;
                    while (result){
                        iteration++;
                        value = rand() % 10;
                        result = RowColBoxCheck(l, m, value, Matrix);
                        Matrix[l][m] = value;
                        if (iteration > 500){
                            ResetBox(Matrix, l, m, iteration);
                        }
                    }
                }
            }
        }

        else if (*i == 6){
            for (int m=*i; m<*i+3; m++){
                for (int n = 0; n < 3; n++){
                    int value = Matrix[m][n];
                    bool result = RowColBoxCheck(m, n, value, Matrix);
                    int iteration = 0;
                    while (result){
                        iteration++;
                        value = rand() % 10;
                        result = RowColBoxCheck(m, n, value, Matrix);
                        Matrix[m][n] = value;
                        if (iteration > 500){
                            ResetBox(Matrix, m, n, iteration);
                        }
                    }
                }
            }
        }
    }
    */
    
}



void puzzleBoxFill(std::vector<std::vector<int>> &vec2D, int RowN, int ColN){
    for (int i=RowN; i<RowN+3; i++){
        for (int j=ColN; j<ColN+3; j++){
            int value = rand()%10, iteration = 0;
            bool result = RowColBoxCheck(i,j,value,vec2D);
            vec2D[i][j] = value;
            while (result){
                iteration++;
                value = rand()%10;
                result = RowColBoxCheck(i,j,value,vec2D);
                if (iteration>500){
                    ResetBox(vec2D,i,j,iteration);
                }
                vec2D[i][j] = value;
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



void FillAllRow(std::vector<std::vector<int>> &vec2DD){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (vec2DD[i][j] == 0 ){
                for (int num=1; num<10; num++){
                    bool result = RowColBoxCheck(i,j,num,vec2DD);
                    if (result == false){
                        vec2DD[i][j] = num;
                    }
                }
            }
        }
    }
}




void Puzzle::GeneratePuzzle(std::vector<std::vector<int>> &Matrix){
    setDiagonalBox(Matrix);
    Puzzle::Print2dVec(Matrix);
    //FillAllRow(Matrix);
    

    
    puzzleBoxFill(Matrix,3,0);
    Puzzle::Print2dVec(Matrix);
    puzzleBoxFill(Matrix,0,3);
    Puzzle::Print2dVec(Matrix);
    puzzleBoxFill(Matrix,0,6);
    Puzzle::Print2dVec(Matrix);
    
    //puzzleBoxFill(Matrix,6,0);
    

    //FillbyRow(Matrix);

}


/*
void setNonDiagonalEmenets(std::vector<std::vector<int>> &Matrix){
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



void FillbyColumn(std::vector<std::vector<int>> &vec2D){
    srand(time(NULL));
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (vec2D[j][i] == 0){
                int value = rand()%10, iteration=0, lo=0;
                bool result = RowColBoxCheck(j,i,value,vec2D);
                vec2D[j][i] = value;
                while (result){
                    iteration++;
                    value = rand()%10;
                    result = RowColBoxCheck(j,i,value,vec2D);
                    vec2D[j][i] = value;
                    if (iteration>500){
                        if (lo>500){
                            goto Stuck;
                        }
                        ResetBox(vec2D,j,i,iteration);
                    }
                }
                printMatrix(vec2D);
            }
        }
    }

Stuck:
    std::cout<<"###Program Stuck########\n";
}


*/