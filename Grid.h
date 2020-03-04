//Ok this is a grid header file.

#pragma once

#include <iostream>
#include <vector>

class Grid{
    public:
    //Defalut constructor and destructor
    Grid();
    ~Grid();
    int a, b;

    void makeGrid(std::vector<std::vector<int> > &matrix);
    void updateGrid();

    void InitialGrid(std::vector<std::vector<int>> aMatrix);

    void Print2dVec(std::vector<std::vector<int>> &aMat);

};