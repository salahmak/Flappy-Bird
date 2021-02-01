#include "Flash.h"

namespace GameWrapper
{

Flash::Flash(GameDataRef data) : _data(data)
{

    _shape = sf::RectangleShape(sf::Vector2f(this->_data->window.getSize()));

    _shape.setFillColor(sf::Color(255, 255, 255, 0));

    _isFlashOn = true;
}

void Flash::Update(float dt)
{
    if(_isFlashOn)
        {
            int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

            if(alpha >= 255)
                {
                    alpha = 255;
                    _isFlashOn = false;
                }

            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    else
        {
            int alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);

            if(alpha <= 0)
                {
                    alpha = 0;
                    _isFlashOn = false;
                }

            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
}

void Flash::Draw()
{
    this->_data->window.draw(_shape);
}

}
