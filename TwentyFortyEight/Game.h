#pragma once
#include "Board.h"
#include "Render.h"

class Game {
private:
    Board board;
    Render render;
    int score;
    bool moved;
    bool alreadyWon;

public:
    Game();

    void init();
    void play();
    void addTile();
    bool Input(char key);

    int getScore() const;
};
