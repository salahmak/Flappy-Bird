#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "Game.h"
#include "State.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

namespace GameWrapper
{

class GameOverState : public State
{
  public:
    GameOverState(GameDataRef data, int score);

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
    sf::Sprite _playBtn;
    sf::Text _scoreText;
    sf::Text _highScoreText;

    int _score;
    int _highScore;
};
}

#endif // GAME_OVER_STATE_H
