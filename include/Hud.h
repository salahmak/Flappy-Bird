#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "config.h"
#include <string>
#include "Game.h"

namespace GameWrapper
{


class Hud
{
public:
	Hud(GameDataRef data, int highScore);

    void Draw();
    void UpdateScore(int score);

  private:
    GameDataRef _data;
    sf::Text _scoreText;
    sf::Text _highScoreText;
	
};

}

#endif
