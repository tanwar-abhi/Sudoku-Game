// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
//#include <vector>
#include "GameOver.h"
#include <map>

class Puzzle{

    private:
    /* Creating a 2D hash map, keys would be the positions of constant values {clues}
    that must never be allowed to be edited by user.*/
    std::map<int,std::map<int,int>> FixedPosition;

    public:
    Puzzle();
    ~Puzzle();

    int Welcome();
    void PlayDemo();
    void Print2dVec(std::vector<std::vector<int>> Vec);

    void GeneratePuzzle(std::vector<std::vector<int>> &VecDD, GameOver &StateObject);

    void UserPuzzle(std::vector<std::vector<int>> &vect2D);

    bool SolveSudoku(std::vector<std::vector<int>> &vector2D);

    void AddResponse(std::vector<std::vector<int>> &Vector2D, unsigned int UserArray[]);

    //bool isGridFull(std::vector<std::vector <int>> VecR2D);

};
