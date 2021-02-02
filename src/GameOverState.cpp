#include "GameOverState.h"
#include "GameState.h"

namespace GameWrapper
{

GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score) 
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

    std::ofstream writeFile(HIGHSCORE_PATH);

    if(writeFile.is_open())
    {
        if(_score > _highScore)
        {
            _highScore = _score;
        }
        writeFile << _highScore;
    }

    writeFile.close();

}

void GameOverState::Init()
{
    //loading the game over texture
    _data->assets.LoadTexture("game over", GAME_OVER);


    //loading the game over body texture
    _data->assets.LoadTexture("game over body", GAME_OVER_BODY);


    //setting the texture of the background
    _background.setTexture(
        _data->assets.GetTexture("game background"));

    //setting the texture of the gameover
   _gameOver.setTexture(_data->assets.GetTexture("game over"));

   //setting the texture of the gameover body
   _gameOverBody.setTexture(_data->assets.GetTexture("game over body"));


   //setting the playBtn texture
    _playBtn.setTexture(this->_data->assets.GetTexture("play button"));



   //setting the position of the game over body
   _gameOverBody.setScale(0.75f, 0.75f);
   _gameOverBody.setPosition((SCREEN_WIDTH / 2) - (_gameOverBody.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2.2) - (_gameOverBody.getGlobalBounds().height / 2 ));



   //setting the position of the game over title
    _gameOver.setScale(0.75f, 0.75f);
    _gameOver.setPosition((SCREEN_WIDTH / 2) - (_gameOver.getGlobalBounds().width / 2),
        (_gameOver.getGlobalBounds().height / 2));



   //setting the play btn's position
    _playBtn.setScale(2.0f, 2.0f);
    _playBtn.setPosition((SCREEN_WIDTH / 2) - (_playBtn.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5) - (_playBtn.getGlobalBounds().height / 2 )));



    //setting the score fonts
    _scoreText.setFont(this->_data->assets.GetFont("score font"));

    _scoreText.setString(std::to_string(_score));

    _scoreText.setCharacterSize(40);

    _scoreText.setOutlineColor(sf::Color::Black);

    _scoreText.setOutlineThickness(1.0f);

    _scoreText.setFillColor(sf::Color::White);

    _scoreText.setOrigin(_scoreText.getGlobalBounds().width/2, _scoreText.getGlobalBounds().height/2);

    _scoreText.setPosition((SCREEN_WIDTH / 10) * 6.7, (SCREEN_HEIGHT / 10) * 4.1);



    //setting the high score fonts
    _highScoreText.setFont(this->_data->assets.GetFont("score font"));

    _highScoreText.setString(std::to_string(_highScore));

    _highScoreText.setCharacterSize(40);

    _highScoreText.setOutlineColor(sf::Color::Black);

    _highScoreText.setOutlineThickness(1.0f);

    _highScoreText.setFillColor(sf::Color::White);

    _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width/2, _highScoreText.getGlobalBounds().height/2);

    _highScoreText.setPosition((SCREEN_WIDTH / 10) * 6.7, (SCREEN_HEIGHT / 10) * 5.2);



 
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

            if(this->_data->input.IsSpriteClicked(_playBtn, event, sf::Mouse::Left, this->_data->window)){
                this->_data->machine.AddState(StateRef(new GameState(_data, _highScore)), true);
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
    _data->window.draw(_playBtn);
    _data->window.draw(_scoreText);
    _data->window.draw(_highScoreText);
    _data->window.display();
}

void GameOverState::Pause() {}

void GameOverState::Resume() {}

} // GameWrapper