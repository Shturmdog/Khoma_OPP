#pragma once
#include <iostream>

class Game {
	int board[4][4] = {};
	int score = 0;
	bool moved = false;

	void printBoard();
	void AddTile();
	void ClearBourd();
	void LeftShift();
	void MergeLeft();
	void ReverseRows();
	void Transpose();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	bool canMove();
	bool hasWon();

public:
	void Game2048();
	void play();
};