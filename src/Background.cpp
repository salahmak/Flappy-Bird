#include "Background.h"

namespace GameWrapper
{
Background::Background(GameDataRef data) : _data(data)
{

    sf::Sprite background1(_data->assets.GetTexture("background"));
    sf::Sprite background2(_data->assets.GetTexture("background"));

    // setting the scale and pos of the 1nd background

    background1.setScale(this->_data->window.getSize().x
                             / background1.getGlobalBounds().width,
                         this->_data->window.getSize().y
                             / background1.getGlobalBounds().height);

    background1.setPosition(0, 0);


    // setting the and scale and pos of the 2nd background

    background2.setScale(this->_data->window.getSize().x
                             / background2.getGlobalBounds().width,
                         this->_data->window.getSize().y
                             / background2.getGlobalBounds().height);

    background2.setPosition(background1.getGlobalBounds().width, 0);

    this->_backgroundSprites.push_back(background1);
    this->_backgroundSprites.push_back(background2);
}

void Background::Move(float dt)
{
    for(unsigned short int i = 0; i < _backgroundSprites.size(); ++i)
        {
            float mouvement = (PIPE_SPEED / 2) * dt;

            _backgroundSprites[i].move(-mouvement, 0.0f);

            if(_backgroundSprites[i].getPosition().x
               < -_backgroundSprites[i].getGlobalBounds().width)
                {
                    _backgroundSprites[i].setPosition(this->_data->window.getSize().x - 5,
                                          _backgroundSprites[i].getPosition().y);
                }
        }
}

void Background::Draw()
{
    for(unsigned short int i = 0; i < _backgroundSprites.size(); ++i)
        {
            _data->window.draw(_backgroundSprites[i]);
        }
}


}