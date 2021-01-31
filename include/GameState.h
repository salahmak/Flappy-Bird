#ifndef GAME_STATE_H
#define GAME_STATE_H



#endif // GAME_STATE_H



#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
#include "Game.h"
#include "State.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"

namespace GameWrapper
{

class GameState: public State
{
public:
    GameState(GameDataRef data);

        void Init();
        void Update(float dt);
        void HandleInput();
        void Draw(float dt);
        void Pause();
        void Resume();

    private:
        GameDataRef _data;
        sf::Sprite _background;

        Pipe *pipe;

        Land *land;

        Bird *bird;

        Collision collision;


        sf::Clock _clock;

        int _gameState;
};
}




