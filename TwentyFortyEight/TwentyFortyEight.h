#pragma once
#include <iostream>

class Game {
	int board[4][4];
	int score;
	bool moved;

	void AddTile();
	void ClearBourd();
	void LeftShift();
};