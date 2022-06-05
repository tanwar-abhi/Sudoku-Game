//This is a grid header file.
// This file contains all the definations of member variables and functions.

#pragma once
#include <vector>

class Grid{
    public:
    //Defalut constructor and destructor
    Grid();
    ~Grid();

    // Prints whole puzzle matrix
    void Print2dVec(std::vector<std::vector<int>> Vec);
    
    // Makes an aethetical grid for user interface.
    void makeGrid(std::vector<std::vector<int>> matrix);

    void updateGrid();

    // Display's in game messages in format, based on the state of game determined by user inputs.
    void DisplayMsg(std::string text);

};