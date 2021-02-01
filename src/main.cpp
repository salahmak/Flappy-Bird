#include <iostream>
#include "Game.h"
#include "config.h"


int main()
{
	GameWrapper::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    return EXIT_SUCCESS;
}
