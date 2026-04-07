#include <iostream>
#include "DateTime.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	DateTime data;
	data.input();
	data.basicFormat();
	data.textformat();
	data.shortformat();
	cout << data.DateEaster();
}

