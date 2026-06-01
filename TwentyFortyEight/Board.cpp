#include "Board.h"

Board::Board() {
    clear();
}

void Board::clear() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = 0;
}

//Установить значение клетки
void Board::setCell(int row, int col, int value) {
    board[row][col] = value;
}

//Получить значение клетки
int Board::getCell(int row, int col) const {
    return board[row][col];
}
//Проверить, пуста ли клетка
bool Board::isEmpty(int row, int col) const {
    return board[row][col] == 0;
}

void Board::shiftLeft() {
    for (int i = 0; i < 4; i++) {
        int temp[4];
        int count = 0;

        // Собираем ненулевые
        for (int j = 0; j < 4; j++)
            if (board[i][j] != 0) {
                temp[count] = board[i][j];
                count++;
            }

        // Записываем обратно
        for (int j = 0; j < 4; j++)
            if (j < count)
                board[i][j] = temp[j];
            else
                board[i][j] = 0;
    }
}

void Board::mergeLeft(int& score, bool& moved) {
    //Проверяем не пустая ли клетка и она равна соседней
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            //Увуличиваем клетку и убираем соседнию
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
                board[i][j] *= 2;
                score += board[i][j];
                board[i][j + 1] = 0;
                moved = true;
            }
        }
    }
}

void Board::reverseRows() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            int temp = board[i][j];
            board[i][j] = board[i][3 - j]; //Даёт симметричный индекс справа
            board[i][3 - j] = temp;
        }
    }
}

//Транспонирование матрицы
void Board::transpose() {
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++) {
            int temp = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = temp;
        }
}

void Board::moveLeft(int& score, bool& moved) {
    int oldBoard[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            oldBoard[i][j] = board[i][j];

    shiftLeft();
    mergeLeft(score, moved);
    shiftLeft();

    // Проверяем, изменилось ли поле
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != oldBoard[i][j])
                moved = true;
}

void Board::moveRight(int& score, bool& moved) {
    reverseRows();
    moveLeft(score, moved);
    reverseRows();
}

void Board::moveUp(int& score, bool& moved) {
    transpose();
    moveLeft(score, moved);
    transpose();
}

void Board::moveDown(int& score, bool& moved) {
    transpose();
    moveRight(score, moved);
    transpose();
}

//Проверяем можно ли сделать ход
bool Board::canMove() const {
    // Пустые клетки
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
                return true;

    // Слияния
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (j < 3 && board[i][j] == board[i][j + 1]) return true;
            if (i < 3 && board[i][j] == board[i + 1][j]) return true;
        }

    return false;
}

bool Board::hasWon() const {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == 2048)
                return true;
    return false;
}
