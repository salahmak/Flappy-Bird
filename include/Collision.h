#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

namespace GameWrapper
{

class Collision
{
  public:
    bool CheckSpriteCollision(sf::Sprite sprite1, float scale1,
                              sf::Sprite sprite2, float scale2);
};

} // GameWrapper

#endif // COLLISION_H
