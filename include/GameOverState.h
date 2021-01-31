#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H



#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"
#include "Game.h"
#include "State.h"

namespace GameWrapper
{

class GameOverState: public State
{
public:
    GameOverState(GameDataRef data);

        void Init();
        void Update(float dt);
        void HandleInput();
        void Draw(float dt);
        void Pause();
        void Resume();

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _gameOver;
        sf::Sprite _gameOverBody;

};
}


#endif // GAME_OVER_STATE_H
