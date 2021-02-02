#include "MainMenuState.h"
#include "GameState.h"

namespace GameWrapper
{

MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{
    _highScore = 0;
    std::ifstream readFile;
    readFile.open(HIGHSCORE_PATH);
    if(readFile.is_open())
        {
            if(readFile.peek() == std::ifstream::traits_type::eof())
                {
                    _highScore = 0;
                }
            else
                {
                    while(!readFile.eof())
                        {
                            readFile >> _highScore;
                        }
                }
        }
    readFile.close();

}

void MainMenuState::Init()
{
    //loading the main menu background
    _data->assets.LoadTexture("main menu background",
                              MAIN_MENU_BACKGROUND_PATH);

    //loading the title image
    _data->assets.LoadTexture("game title", GAME_TITLE_PATH);

    //loading the play button image
    _data->assets.LoadTexture("play button", PLAY_BUTTON_PATH);


    // loading the flappyfont font
    _data->assets.LoadFont("score font", FLAPPY_FONT_PATH);


    //setting the texture of the background, play btn, title to their sprites
    _background.setTexture(
        this->_data->assets.GetTexture("main menu background"));

    _playBtn.setTexture(this->_data->assets.GetTexture("play button"));

    _title.setTexture(this->_data->assets.GetTexture("game title"));


    //setting the title's position
    _title.setScale(0.15f, 0.15f);

    _title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
        (_title.getGlobalBounds().height / 2));


    //setting the play btn's position
    _playBtn.setScale(2.0f, 2.0f);
    _playBtn.setPosition((SCREEN_WIDTH / 2) - (_playBtn.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2) - (_playBtn.getGlobalBounds().height / 2 ));


    //setting the highScore font
    _highScoreText.setFont(this->_data->assets.GetFont("score font"));

    _highScoreText.setString("High score: " + std::to_string(_highScore));

    _highScoreText.setCharacterSize(30);

    _highScoreText.setOutlineColor(sf::Color::Black);

    _highScoreText.setOutlineThickness(1.0f);

    _highScoreText.setFillColor(sf::Color::White);

    _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width/2, _highScoreText.getGlobalBounds().height/2);

    _highScoreText.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - _playBtn.getGlobalBounds().height);

}

void MainMenuState::HandleInput()
{
    sf::Event event;

    while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                {
                    _data->window.close();
                }

            if(this->_data->input.IsSpriteClicked(_playBtn, event, sf::Mouse::Left, this->_data->window)){
                std::cout << "clicked"<<std::endl;
                this->_data->machine.AddState(StateRef(new GameState(_data, _highScore)), true);
            }
        }
}

void MainMenuState::Update(float dt)
{
    // if(_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
    //     {
    //         std::cout << "go to main menu" << std::endl;
    //     }
}

void MainMenuState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playBtn);
    _data->window.draw(_highScoreText);
    _data->window.display();
}

void MainMenuState::Pause() {}

void MainMenuState::Resume() {}

} // GameWrapper