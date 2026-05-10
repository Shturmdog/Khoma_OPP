#include <iostream>
#include "Field.h"
using namespace std;

Field::Field(bool isRedFirst) {
	clear(isRedFirst);
}

void Field::clear(bool isRedFirst) {
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i = 0; i < FIELD_WIDTH; i++) {
		for (int j = 0; j < FIELD_HEIGHT; j++) {
			cells[i][j] = EMPTY;
		}
	}
}

bool Field::makeTurn(int column) {
	if (winner != EMPTY || column < 1 || column > FIELD_WIDTH)
		return false;

	int i = column - 1;
	for (int j = 0; i < FIELD_HEIGHT; j++)
		if (cells[i][j] == EMPTY) {
			cells[i][j] = isRedTurn ? RED : YELLOW;
			checkWinner();
			isRedTurn = !isRedTurn;
			return true;
		}
	return false;
}

void Field::checkWinner() {
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++) {
			Cell start = cells[i][j];
			if (start == EMPTY) continue;
			for (int dir = 0; dir < DIR_NUMBER; dir++) {
				int lenght = 0, iline = i, jline = j;
				while (++lenght < WIN_LENGTH) {
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH || jline < 0 || jline >= FIELD_HEIGHT)
						break;
					if (cells[iline][jline] != start) break;
				}
				if (lenght == WIN_LENGTH) {
					winner = start;
					return;
				}
			}
		}
}

bool Field::isOver() const {
	if (winner != EMPTY)
		return true;
	for (int i = 0; i < FIELD_WIDTH; i++)
		for (int j = 0; j < FIELD_HEIGHT; j++)
			if (cells[i][j] == EMPTY)
				return false;
	return true;
}

Cell Field::getCell(int i, int j) const {
	return cells[i][j];
}

bool Field::isRedTurnNow() const {
	return isRedTurn;
}

void Field::print() const {
	for (int i = FIELD_WIDTH - 1; i >= 0; i--) {
		for (int j = 0; j < FIELD_HEIGHT; j++) {
			if (cells[i][j] == RED) cout << "R|";
			else if (cells[i][j] == YELLOW) cout << "Y|";
			else cout << "_";
		}
	}
}