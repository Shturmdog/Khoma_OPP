#include "Array.h"
#include <iostream>
using namespace std;

int main() {
	clock_t start = clock();

	int k = 3;
	Array arr(9);
	for (int i = 0; i < 9; i++) {
		arr.insert(i + 1);
	}

	int size = arr.getSize();

	int i = 0;
	while (size > 1) {
		i = (i + k - 1) % size;
		arr.remove(i);
		size--;
	}

	clock_t end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << time << 's' << endl;

	return 0;
}