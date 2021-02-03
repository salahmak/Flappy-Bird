#include "InputManager.h"

namespace GameWrapper
{

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Event event,
                                   sf::Mouse::Button button,
                                   sf::RenderWindow& window)
{
    if(event.type == event.MouseButtonPressed
       && event.mouseButton.button == button)
        {
            sf::IntRect tempRect(object.getPosition().x,
                                 object.getPosition().y,
                                 object.getGlobalBounds().width,
                                 object.getGlobalBounds().height);

            if(tempRect.contains(sf::Mouse::getPosition(window)))
                {
                    return true;
                }
        }
    return false;
}

bool InputManager::IsKeyPressed(sf::Event event, sf::Keyboard::Key key)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == key)
        {
            return true;
        }
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}

} // Game