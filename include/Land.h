#ifndef LAND_H
#define LAND_H

#include "Game.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameWrapper
{
class Land
{
  public:
    Land(GameDataRef data);

    void MoveLand(float dt);
    void DrawLand();

    const std::vector<sf::Sprite>& GetSprites() const;

  private:
    GameDataRef _data;
    std::vector<sf::Sprite> _landSprites;
};

} // GameWraper

#endif // LAND_H
