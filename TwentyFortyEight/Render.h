#pragma once

class Board;

class Render {
public:
    void clearScreen();
    void drawBoard(const Board& board, int score);
    void drawGameOver(int score);
    void drawVictory(int score);
};

