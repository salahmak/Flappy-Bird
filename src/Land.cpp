#include "Land.h"
#include <iostream>

namespace GameWrapper
{

Land::Land(GameDataRef data) : _data(data)
{
    sf::Sprite sprite;
    sf::Sprite sprite2;

    sprite.setTexture(this->_data->assets.GetTexture("land"));
    sprite2.setTexture(this->_data->assets.GetTexture("land"));

    sprite.setScale(this->_data->window.getSize().x / sprite.getLocalBounds().width, 1);
    sprite2.setScale(this->_data->window.getSize().x / sprite2.getLocalBounds().width, 1);


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
                    _landSprites[i].setPosition(this->_data->window.getSize().x - 5,
                                          _landSprites[i].getPosition().y);
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
