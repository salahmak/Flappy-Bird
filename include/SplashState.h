#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include "Game.h"
#include "State.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

namespace GameWrapper
{

class SplashState : public State
{
  public:
    SplashState(GameDataRef data);
    ~SplashState();

    void Init();
    void Update(float dt);
    void HandleInput();
    void Draw(float dt);
    void Pause();
    void Resume();

  private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
};

}

#endif // SPLASH_STATE_H
