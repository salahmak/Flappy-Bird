#ifndef GAME_STATE_H
#define GAME_STATE_H



#endif // GAME_STATE_H



#include <SFML/Graphics.hpp>
#include <iostream>
#include "config.h"
#include "Game.h"
#include "State.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Hud.h"

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

        Hud *hud;
        

        sf::Clock _clock;

        int _gameState;

        int _score;
};
}




