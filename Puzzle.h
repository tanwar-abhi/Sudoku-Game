// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
#include <vector>

class Puzzle{
    

    public:
    Puzzle();
    ~Puzzle();
    int m = 9,n = 9;


    std::vector<std::vector <int>> Matrix(m, std::vector<int> (n));

    void aFuncCall();
    void Print2dVec(std::vector<std::vector<int>> &Matrix);
    void RandomMatrix(std::vector<std::vector<int>> &Mat);



};
