#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "Game.h"
#include "State.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

namespace GameWrapper
{

class MainMenuState : public State
{
  public:
    MainMenuState(GameDataRef data);
    ~MainMenuState();

    void Init();
    void Update(float dt);
    void HandleInput();
    void Draw(float dt);
    void Pause();
    void Resume();

  private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _playBtn;
    sf::Sprite _title;

    sf::Text _highScoreText;

    int _highScore;
};
}

#endif // MAIN_MENU_STATE_H
