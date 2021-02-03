#include "Land.h"
#include <iostream>

namespace GameWrapper
{

Land::Land(GameDataRef data) : _data(data)
{
    sf::Sprite sprite(this->_data->assets.GetTexture("land"));
    sf::Sprite sprite2(this->_data->assets.GetTexture("land"));

    sprite.setPosition(
        0, (SCREEN_HEIGHT - (sprite.getGlobalBounds().height / 2)));
    sprite2.setPosition(
        sprite.getGlobalBounds().width,
        (SCREEN_HEIGHT - (sprite.getGlobalBounds().height / 2)));

    _landSprites.push_back(sprite);
    _landSprites.push_back(sprite2);
}

void Land::MoveLand(float dt)
{
    for(unsigned short int i = 0; i < _landSprites.size(); ++i)
        {
            float mouvement = PIPE_SPEED * dt;

            _landSprites[i].move(-mouvement, 0.0f);

            if(_landSprites[i].getPosition().x
               < -_landSprites[i].getGlobalBounds().width)
                {
                    sf::Vector2f position(SCREEN_WIDTH,
                                          _landSprites[i].getPosition().y);
                    _landSprites[i].setPosition(position);
                }
        }
}

void Land::DrawLand()
{
    for(unsigned short int i = 0; i < _landSprites.size(); ++i)
        {
            _data->window.draw(_landSprites[i]);
        }
}

const std::vector<sf::Sprite>& Land::GetSprites() const
{
    return _landSprites;
}

} // GameWrapper
