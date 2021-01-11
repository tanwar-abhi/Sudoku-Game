//This is the header file containing definitions of the checks to be performed at Game's end

#pragma once
#include <vector>
#include <string>

class GameOver {
    private:
    std::vector<std::vector<int>> Solution;
    
    public:
    std::string CurrentState;

    GameOver();
    ~GameOver();

    // Decides the state of game based on user input, states possible = end, solved, reset
    void GameEnd(std::vector<std::vector<int>> Vector2D);

    // Copies the correct solution of puzzle into another matrix which is later used for checking.
    void SetSolution(std::vector<std::vector<int>> Vector2D);

    // Print actual solution of puzzle if user fails to solve puzzle.
    void PrintSolution();
    
};

