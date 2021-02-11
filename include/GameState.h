#ifndef GAME_STATE_H
#define GAME_STATE_H

#endif // GAME_STATE_H

#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "Game.h"
#include "Hud.h"
#include "Land.h"
#include "Pipe.h"
#include "State.h"
#include "config.h"
#include "Background.h"
#include "SoundManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace GameWrapper
{

class GameState : public State
{
  public:
    GameState(GameDataRef data, int highScore);
    ~GameState();

    void Init();
    void Update(float dt);
    void HandleInput();
    void Draw(float dt);
    void Pause();
    void Resume();

  private:
    GameDataRef _data;
    sf::Sprite _background;

    Pipe* pipe;

    Land* land;

    Bird* bird;

    Hud* hud;

    Flash* flash;

    Background* background;


    sf::Clock _clock;

    int _gameState;

    int _score;
    int _highScore;
};
}
