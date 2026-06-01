#pragma once

class Board {
private:
    int board[4][4] = {};   // Игровое поле

public:
    Board();

    // Базовые операции
    void clear();
    void setCell(int row, int col, int value);
    int getCell(int row, int col) const;
    bool isEmpty(int row, int col) const;

    // Трансформации поля
    void shiftLeft();
    void mergeLeft(int& score, bool& moved);
    void reverseRows();
    void transpose();

    // Ходы
    void moveLeft(int& score, bool& moved);
    void moveRight(int& score, bool& moved);
    void moveUp(int& score, bool& moved);
    void moveDown(int& score, bool& moved);

    // Проверки
    bool canMove() const;
    bool hasWon() const;

};