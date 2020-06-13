//This is the header file containing definitions of the checks to be performed at Game's end

#pragma once
#include "Puzzle.h"

// GameOver taking public Inherritance from Puzzle class
class GameOver : public Puzzle{
    private:
    std::vector<std::vector<int>> Solution;

    public:
    GameOver();
    ~GameOver();
    bool GameEnd(std::vector<std::vector<int>> Vec2D);


};

