#include "Game.h"
#include "config.h"
#include <iostream>

#ifdef _WIN32
	#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif

    GameWrapper::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    return EXIT_SUCCESS;
}
