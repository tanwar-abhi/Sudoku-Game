// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
#include "GameOver.h"
#include <map>

class Puzzle{

    private:
    /* Creating a 2D hash map, keys would be the positions of constant values {clues}
    that must never be allowed to be edited by user.*/
    std::map<int,std::map<int,int>> FixedPosition;

    public:
    // Default constructor called during creation of an object using puzzle.
    Puzzle();
    // Default destructor for puzzle object, called at destruction of puzzle object.
    ~Puzzle();

    // Displays initial welcome message, prompt user to make choice between game or solver.
    int Welcome();

    // Displays a demo about how to play game using CLI.
    void PlayDemo();

    // Generates puzzle randomly.
    void GeneratePuzzle(std::vector<std::vector<int>> &VecDD, GameOver &StateObject);

    void UserPuzzle(std::vector<std::vector<int>> &vect2D);

    bool SolveSudoku(std::vector<std::vector<int>> &vector2D);

    void AddResponse(std::vector<std::vector<int>> &Vector2D, unsigned int UserArray[]);

    void Reset(std::vector<std::vector<int>> &Vector2D);

};
