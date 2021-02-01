#ifndef FLASH_H
#define FLASH_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "config.h"

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