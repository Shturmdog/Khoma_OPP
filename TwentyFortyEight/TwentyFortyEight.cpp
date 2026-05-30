#include "TwentyFortyEight.h"
#include <iostream>
#include <vector>

using namespace std;

void Game::AddTile() {
	vector<pair<int, int>> emptyCells;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			emptyCells.push_back({ i, j });
		}
	}
	int x = rand() % emptyCells.size();
	int value = (rand() % 10) ? 4 : 2;

	int row = emptyCells[x].first;
	int col = emptyCells[x].second;
	board[row][col] = value;
}