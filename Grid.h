//This is a grid header file.
// This file contains all the definations of member variables and functions.

#pragma once

#include <vector>

class Grid{
    public:
    //Defalut constructor and destructor
    Grid();
    ~Grid();
    int a, b;

    void makeGrid(std::vector<std::vector<int>> matrix);
    void updateGrid();

    //void InitialGrid(std::vector<std::vector<int>> aMatrix);
    //void Print2dVec(std::vector<std::vector<int>> &aMat);

};