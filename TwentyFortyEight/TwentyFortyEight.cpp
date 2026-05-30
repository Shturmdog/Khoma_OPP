#include "TwentyFortyEight.h"
#include <iostream>
#include <vector>

using namespace std;

void Game::AddTile() {
	vector<vector<int, int>> emptyCells;
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= 4; j++) {
			emptyCells.push_back({ i, j });
		}
	}
	int value = (rand() % 10) ? 4 : 2;
}