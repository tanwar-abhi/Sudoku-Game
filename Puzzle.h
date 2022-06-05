// The header file for puzzle.
// Puzzle is a 2D vector (i.e) matrix of size (m*n)

#pragma once
#include "Grid.h"
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

    // Generates random puzzle as per selected difficulty.
    void GeneratePuzzle(std::vector<std::vector<int>> &VecDD, GameOver &StateObject, const unsigned int);

    void UserPuzzle(std::vector<std::vector<int>> &vect2D);

    bool SolveSudoku(std::vector<std::vector<int>> &vector2D);

    // Check user input, if correct format enetered by user then add value in puzzle grid.
    void AddResponse(std::vector<std::vector<int>> &Vector2D, unsigned int UserArray[]);

    // Reset the game to initial puzzle, removing all user response
    void Reset(std::vector<std::vector<int>> &Vector2D);

    // Ask user to select a particular dificulty level.
    unsigned int SelectLevel();

    // Game play for generated sudoku puzzle
    void GamePlay(std::vector<std::vector<int>> &, Puzzle &, Grid &, GameOver &);

};
