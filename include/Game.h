#ifndef GAME_H
#define GAME_H

#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"
#include "SoundManager.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

namespace GameWrapper
{

struct GameData
{
    GameData() {}
    ~GameData() {}
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    SoundManager sound;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
  public:
    Game(int width, int height, std::string title);

  private:
    const float dt = 1.0f / FRAMERATE;
    sf::Clock _clock;

    GameDataRef _data = std::make_shared<GameData>();

    void run();
};

} // Game

#endif // GAME_H
