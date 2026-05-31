#include <iostream>
#include "TwentyFortyEight.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));
    Game game;
    game.play();
    return 0;
}