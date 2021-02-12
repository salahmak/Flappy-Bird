#include "GameState.h"
#include "GameOverState.h"

// todo MAKE THE BACKGROUND ANIMATED ---> done
// todo add sounds

namespace GameWrapper
{

GameState::GameState(GameDataRef data, int highScore)
    : _data(data), _highScore(highScore)
{
}

GameState::~GameState()
{
    delete this->pipe;
    delete this->land;
    delete this->hud;
    delete this->bird;
    delete this->flash;
    delete this->background;
}

void GameState::Init()
{

    pipe = new Pipe(this->_data);

    land = new Land(this->_data);

    bird = new Bird(this->_data);

    hud = new Hud(this->_data, _highScore);

    flash = new Flash(this->_data);

    background = new Background(this->_data);

    // // setting the texture of the background
    // _background.setTexture(_data->assets.GetTexture("background"));
    // // setting the scale of the background
    // _background.setScale(SCREEN_WIDTH / _background.getGlobalBounds().width,
    //                      SCREEN_HEIGHT /
    //                      _background.getGlobalBounds().height);

    _gameState = GameStates::ready;

    _score = 0;
}

void GameState::HandleInput()
{
    sf::Event event;

    while(_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                {
                    _data->window.close();
                }

            if(this->_data->input.IsMouseClicked(event, sf::Mouse::Left)
               || this->_data->input.IsKeyPressed(event, sf::Keyboard::Space))
                {
                    if(_gameState != GameStates::gameOver)
                        {
                            if(_gameState == GameStates::ready)
                                {
                                    _gameState = GameStates::playing;
                                }
                            bird->Tap();
                        }
                }
        }
}

void GameState::Update(float dt)
{
    if(_gameState != GameStates::gameOver)
        {
            bird->Animate(BIRD_ANIMATION_TIME);

            background->Move(dt);

            land->MoveLand(dt);
        }

    if(_gameState == GameStates::playing)
        {
            pipe->MovePipes(dt);

            if(_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQ)
                {

                    pipe->SpawnPipes();

                    _clock.restart();
                }
            bird->Update(dt);

            // Detecting collition with the ground
            // Getting the land sprites vector
            std::vector<sf::Sprite> landSprites = land->GetSprites();

            // looping through the sprites to detect collition with the bird
            for(unsigned short int i = 0; i < landSprites.size(); ++i)
                {
                    if(Collision::BoundingBoxTest(bird->GetSprite(),
                                                  landSprites[i]))
                        {
                            this->_data->sound.Play("hit");
                            _gameState = GameStates::gameOver;
                            _clock.restart();
                        }
                }

            // Detecting collision with the pipes
            // Getting the Pipe sprites vector:
            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

            // looping through the sprites to detect collision with the bird
            for(unsigned short int i = 0; i < pipeSprites.size(); ++i)
                {
                    if(Collision::PixelPerfectTest(bird->GetSprite(),
                                                   pipeSprites[i]))
                        {
                            this->_data->sound.Play("hit");
                            _gameState = GameStates::gameOver;
                            _clock.restart();
                        }
                }

            // The scoring system
            // Getting the Scoring sprites vector:
            std::vector<sf::Sprite>& scoringSprites
                = pipe->GetScoringSprites();

            // looping through the sprites to detect collision with the bird
            for(unsigned short int i = 0; i < scoringSprites.size(); ++i)
                {
                    if(Collision::BoundingBoxTest(bird->GetSprite(),
                                                  scoringSprites[i]))
                        {
                            this->_data->sound.Play("point");
                            _score++;
                            hud->UpdateScore(_score);
                            scoringSprites.erase(scoringSprites.begin() + i);
                        }
                }
        }

    if(_gameState == GameStates::gameOver)
        {
            this->bird->AnimateDeath(dt);
            this->flash->Update(dt);
            if(_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
                {
                    this->_data->machine.AddState(
                        StateRef(new GameOverState(_data, _score)));
                }
        }
}

void GameState::Draw(float dt)
{
    _data->window.clear();
    // _data->window.draw(_background);
    background->Draw();
    pipe->DrawPipes();
    land->DrawLand();
    bird->Draw();
    hud->Draw();
    flash->Draw();
    _data->window.display();
}

void GameState::Pause() {}

void GameState::Resume() {}

} // GameWrapper