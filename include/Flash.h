#ifndef FLASH_H
#define FLASH_H

#include "Game.h"
#include "config.h"
#include <SFML/Graphics.hpp>

namespace GameWrapper
{

class Flash
{
  public:
    Flash(GameDataRef data);

    void Update(float dt);

    void Draw();

  private:
    GameDataRef _data;

    sf::RectangleShape _shape;

    bool _isFlashOn;
};
}

#endif