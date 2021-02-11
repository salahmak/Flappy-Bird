#ifndef BACKGROUND_H
#define BACKGROUND_H



#include "Game.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameWrapper
{
class Background
{
  public:
    Background(GameDataRef data);

    void Move(float dt);
    void Draw();

  private:
    GameDataRef _data;
    std::vector<sf::Sprite> _backgroundSprites;
};

} // GameWraper

#endif