#include "GameState.h"
#include "GameOverState.h"

namespace GameWrapper
{

GameState::GameState(GameDataRef data, int highScore) : _data(data), _highScore(highScore) {}

void GameState::Init()
{
    // loading the main menu background
    _data->assets.LoadTexture("game background", MAIN_MENU_BACKGROUND_PATH);

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

    pipe = new Pipe(this->_data);

    land = new Land(this->_data);

    bird = new Bird(this->_data);

    hud = new Hud(this->_data, _highScore);

    flash = new Flash(this->_data);

    // setting the texture of the background
    _background.setTexture(_data->assets.GetTexture("game background"));

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

            if(this->_data->input.IsSpriteClicked(
                   _background, event, sf::Mouse::Left, this->_data->window)
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
                            _score++;
                            hud->UpdateScore(_score);
                            scoringSprites.erase(scoringSprites.begin() + i);
                        }
                }
        }

        if(_gameState == GameStates::gameOver)
        {
            this->flash->Update(dt);
            if(_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
            {
                this->_data->machine.AddState(StateRef(new GameOverState(_data, _score)));
            }
        }
}

void GameState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
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