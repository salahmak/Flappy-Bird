#include "GameOverState.h"

namespace GameWrapper
{

GameOverState::GameOverState(GameDataRef data) : _data(data) {}

void GameOverState::Init()
{
    //loading the main menu background
    _data->assets.LoadTexture("game over background",
                              MAIN_MENU_BACKGROUND_PATH);


    

    //loading the game over texture
    _data->assets.LoadTexture("game over", GAME_OVER);


    //loading the game over body texture
    _data->assets.LoadTexture("game over body", GAME_OVER_BODY);
    


    //setting the texture of the background
    _background.setTexture(
        _data->assets.GetTexture("game over background"));

    //setting the texture of the gameover
   _gameOver.setTexture(_data->assets.GetTexture("game over"));

   //setting the texture of the gameover body
   _gameOverBody.setTexture(_data->assets.GetTexture("game over body"));



   //setting the position of the game over body
   _gameOverBody.setScale(0.5f, 0.5f);
   _gameOverBody.setPosition((SCREEN_WIDTH / 2) - (_gameOverBody.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2) - (_gameOverBody.getGlobalBounds().height / 2 ));



   //setting the position of the game over title
    _gameOver.setScale(0.75f, 0.75f);
    _gameOver.setPosition((SCREEN_WIDTH / 2) - (_gameOver.getGlobalBounds().width / 2),
        (_gameOver.getGlobalBounds().height / 2));



 
}

void GameOverState::HandleInput()
{
    sf::Event event;

    while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                {
                    _data->window.close();
                }

            if(this->_data->input.IsSpriteClicked(_background, event, sf::Mouse::Left, this->_data->window)){
                std::cout << "clicked" <<std::endl;
            }
        }
}

void GameOverState::Update(float dt)
{
    // if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    //     {
    //         std::cout << "go to main menu" << std::endl;
    //     }
}

void GameOverState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_gameOver);
    _data->window.draw(_gameOverBody);
    _data->window.display();
}

void GameOverState::Pause() {}

void GameOverState::Resume() {}

} // GameWrapper