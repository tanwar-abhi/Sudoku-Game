// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
#include <vector>

class Puzzle{    

    public:
    Puzzle();
    ~Puzzle();

    void Welcome(std::vector<std::vector<int>> &vec2DD);
    void PlayDemo();
    void Print2dVec(std::vector<std::vector<int>> Vec);

    void GeneratePuzzle(std::vector<std::vector<int>> &VecDD);

    void UserPuzzle(std::vector<std::vector<int>> &vect2D);

    bool SolveSudoku(std::vector<std::vector<int>> &vector2D);

    //bool isGridFull(std::vector<std::vector <int>> VecR2D);

};
