#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
namespace GameWrapper
{

class InputManager
{
  public:
    InputManager() {}
    ~InputManager() {}

    bool IsSpriteClicked(sf::Sprite object, sf::Event event,
                         sf::Mouse::Button button, sf::RenderWindow& window);

    bool IsKeyPressed(sf::Event event, sf::Keyboard::Key key);

    bool IsMouseClicked(sf::Event event, sf::Mouse::Button button);

    sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};

} // GameWrapper

#endif // INPUT_MANAGER_H
