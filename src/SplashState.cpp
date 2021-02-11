#include "SplashState.h"
#include "MainMenuState.h"

namespace GameWrapper
{

SplashState::SplashState(GameDataRef data) : _data(data) {}
SplashState::~SplashState()
{
    this->_data->assets.UnloadTexture("splash background");
}

void SplashState::Init()
{

    // loading the assets
    _data->assets.LoadTexture("splash background", SPLASH_SCENE_IMAGE_PATH);

    // loading the main menu background
    _data->assets.LoadTexture("background", BACKGROUND_PATH);

    // loading the title image
    _data->assets.LoadTexture("game title", GAME_TITLE_PATH);

    // loading the play button image
    _data->assets.LoadTexture("play button", PLAY_BUTTON_PATH);

    // loading the flappyfont font
    _data->assets.LoadFont("score font", FLAPPY_FONT_PATH);

    // loading the pipeDown texture
    _data->assets.LoadTexture("pipe down", PIPE_DOWN_PATH);

    // loading the PipeUp texture
    _data->assets.LoadTexture("pipe up", PIPE_UP_PATH);

    // loading the land texture
    _data->assets.LoadTexture("land", LAND_PATH);

    // loading the bird frames
    _data->assets.LoadTexture("bird 1", BIRD_FRAME_1_PATH);
    _data->assets.LoadTexture("bird 2", BIRD_FRAME_2_PATH);
    _data->assets.LoadTexture("bird 3", BIRD_FRAME_3_PATH);
    _data->assets.LoadTexture("bird 4", BIRD_FRAME_4_PATH);

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