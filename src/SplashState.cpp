#include "SplashState.h"
#include "MainMenuState.h"

namespace GameWrapper
{

SplashState::SplashState(GameDataRef data) : _data(data) {}
SplashState::~SplashState() {}

void SplashState::Init()
{
    _data->assets.LoadTexture("splash background", SPLASH_SCENE_IMAGE_PATH);
    _background.setTexture(
        this->_data->assets.GetTexture("splash background"));
}

void SplashState::HandleInput()
{
    sf::Event event;

    while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                {
                    _data->window.close();
                }
        }
}

void SplashState::Update(float dt)
{
    if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)));
        }
}

void SplashState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}

void SplashState::Pause() {}

void SplashState::Resume() {}

} // GameWrapper