#include "Game.h"
#include "config.h"
#include <iostream>

int main()
{
    GameWrapper::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    return EXIT_SUCCESS;
}
