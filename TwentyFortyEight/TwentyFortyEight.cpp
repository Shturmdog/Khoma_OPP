#include "TwentyFortyEight.h"
#include <iostream>
#include <vector>

using namespace std;

void Game::AddTile() {
	//Список пустых клеток
	vector<pair<int, int>> emptyCells;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//Если клетка пустая добавляем добавляем координинаты
			if (board[i][j] == 0)
				emptyCells.push_back({ i, j });
		}
	}
	if (emptyCells.empty()) return; //Если пустых клеток нет выходим

	//Выбираем случайную клеку и подставляем случайное значение
	int x = rand() % emptyCells.size();
	int value = (rand() % 10) ? 4 : 2;

	int row = emptyCells[x].first;
	int col = emptyCells[x].second;
	board[row][col] = value;

}

void Game::ClearBoard() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = 0;
}

void Game::LeftShift() {
	for (int i = 0; i < 4; i++) {
		vector<int> row;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0)
				row.push_back(board[i][j]);
		}

		for (int j = 0; j < 4; j++) {
			int newVal = (j < row.size()) ? row[j] : 0;
			if (board[i][j] != newVal) moved = true;
			board[i][j] = newVal;
		}
	}
}

void Game::MergeLeft() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 0 && board[i][j] == board[i][j + 1]) {
				board[i][j] *= 2;
				score += board[i][j];
				board[i][j + 1] = 0;
				moved = true;
			}
		}
	}
}

void Game::ReverseRows() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			int temp = board[i][j];
			board[i][j] = board[i][3 - j];
			board[i][3 - j] = temp;
		}
	}
}

void Game::Transpose() {
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			int temp = board[i][j];
			board[i][j] = board[j][i];
			board[j][i] = temp;
		}
}

void Game::MoveLeft() {
	LeftShift();
	MergeLeft();
	LeftShift();
}

void Game::MoveRight() {
	ReverseRows();
	MoveLeft();
	ReverseRows();
}

void Game::MoveUp() {
	Transpose();
	MoveLeft();
	Transpose();
}

void Game::MoveDown() {
	Transpose();
	MoveRight();
	Transpose();
}