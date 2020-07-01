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

    void GameEnd(std::vector<std::vector<int>> Vector2D);
    void SetSolution(std::vector<std::vector<int>> Vector2D);
    void PrintSolution();
    
};

