#include "Render.h"
#include "Board.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Render::clearScreen() {
    system("cls");
}

void Render::drawBoard(const Board& board, int score) {
    clearScreen();
    cout << "Очки: " << score << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "|";
        for (int j = 0; j < 4; j++) {
            int val = board.getCell(i, j);
            if (val == 0)
                cout << setw(6) << " " << "|";
            else
                cout << setw(6) << val << "|";
        }
        cout << endl;
        cout << "-----------------------------" << endl;
    }
}

void Render::drawGameOver(int score) {
    cout << "\nИгра окончена! Счёт: " << score << endl;
}

void Render::drawVictory(int score) {
    cout << "\nВы достигли 2048!" << endl;
    cout << "Ваш счёт: " << score << endl;
}
