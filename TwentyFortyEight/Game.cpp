#include "Game.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>


using namespace std;

Game::Game() : score(0), moved(false), alreadyWon(false) {}

void Game::init() {
    score = 0;
    moved = false;
    alreadyWon = false;
    board.clear();
    addTile();
    addTile();
}

void Game::addTile() {
    //Список пустых клеток
    vector<pair<int, int>> emptyCells;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            //Если клетка пустая добавляем добавляем координинаты
            if (board.isEmpty(i, j))
                emptyCells.push_back({ i, j });

    if (emptyCells.empty()) return; //Если пустых клеток нет выходим

    //Выбираем случайную клеку и подставляем случайное значение
    int x = rand() % emptyCells.size();
    int value = (rand() % 10 == 0) ? 4 : 2;
    board.setCell(emptyCells[x].first, emptyCells[x].second, value);
}

//Управление клавишами
bool Game::Input(char key) {
    moved = false;

    switch (key) {
    case 75: board.moveLeft(score, moved); break;   // Left
    case 72: board.moveUp(score, moved); break;     // Up
    case 77: board.moveRight(score, moved); break;  // Right
    case 80: board.moveDown(score, moved); break;   // Down
    default: return false;
    }
    return true;
}

void Game::play() {
    init();
    render.drawBoard(board, score);

    while (true) {
        // Проверка победы
        if (!alreadyWon && board.hasWon()) {
            render.drawVictory(score);
            cout << "Продолжить игру? (y/n): ";

            char c;
            do {
                c = _getch();
            } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');

            cout << c << endl;

            if (c != 'y' && c != 'Y')
                break;
            alreadyWon = true;
            render.drawBoard(board, score);
        }

        // Проверка поражения
        if (!board.canMove()) {
            render.drawGameOver(score);
            break;
        }

        char key = _getch();

        // ESC — выход
        if (key == 27) {
            cout << "\nИгра завершена. Счёт: " << score << endl;
            break;
        }

        // Стрелки
        if (key == -32 || key == 0) {
            key = _getch();
            if (!Input(key))
                continue;
        }
        else {
            continue;
        }

        // Если ход изменил поле
        if (moved) {
            addTile();
            render.drawBoard(board, score);
        }
    }
}

int Game::getScore() const {
    return score;
}