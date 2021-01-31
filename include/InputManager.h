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

    // bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf:: RenderWindow &window);
    
    bool IsSpriteClicked(sf::Sprite object, sf::Event event, sf::Mouse::Button button, sf:: RenderWindow &window);

    bool IsKeyPressed(sf::Event event, sf::Keyboard::Key key);

    sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

} // GameWrapper

#endif // INPUT_MANAGER_H
