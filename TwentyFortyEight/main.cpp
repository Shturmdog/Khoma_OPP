#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "rus_ru.UTF-8");
    srand(time(NULL));
    Game game;
    game.play();
    return 0;
}