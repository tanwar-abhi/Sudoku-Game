//This is a grid header file.
// This file contains all the definations of member variables and functions.

#pragma once
#include <vector>

class Grid{
    public:
    //Defalut constructor and destructor
    Grid();
    ~Grid();

    void Print2dVec(std::vector<std::vector<int>> Vec);
    void makeGrid(std::vector<std::vector<int>> matrix);
    void updateGrid();
    void DisplayMsg(std::string text);

};