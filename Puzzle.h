// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
#include <vector>

class Puzzle{    

    public:
    Puzzle();
    ~Puzzle();

    void Welcome();
    void PlayDemo();
    void Print2dVec(std::vector<std::vector<int>> Vec);
    void RandomMatrix(std::vector<std::vector<int>> &Mat);
    void PuzzleSetup(std::vector<std::vector<int>> &Vec2D);

};
