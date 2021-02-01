#include "Pipe.h"

namespace GameWrapper
{

Pipe::Pipe(GameDataRef data) : _data(data) {}

void Pipe::DrawPipes()
{
    for(unsigned short int i = 0; i < _pipeSprites.size(); ++i)
        {
            _data->window.draw(_pipeSprites[i]);
        }
}




// random num between -150 and 90
void Pipe::SpawnPipes()
{
    int randomNum = Rng::generate(-140, 90);

    this->SpawnInvisiblePipe(randomNum);
    this->SpawnBottomPipe(randomNum);
    this->SpawnTopPipe(randomNum);

}




void Pipe::SpawnTopPipe(int Ypos)
{
    sf::Sprite sprite(this->_data->assets.GetTexture("pipe up"));

    sprite.setScale(1.3, 1);

    sprite.setPosition(this->_data->window.getSize().x,
                       this->_data->window.getSize().y - sprite.getGlobalBounds().height - Ypos);


    _pipeSprites.push_back(sprite);
}

void Pipe::SpawnBottomPipe(int Ypos)
{
    sf::Sprite sprite(this->_data->assets.GetTexture("pipe down"));
    sprite.setScale(1.3, 1);

    sprite.setPosition(this->_data->window.getSize().x, - 140 - Ypos);


    _pipeSprites.push_back(sprite);
}

void Pipe::SpawnInvisiblePipe(int Ypos)
{
    sf::Sprite sprite(this->_data->assets.GetTexture("pipe down"));
    sprite.setScale(1.3, 1);

    sprite.setPosition(this->_data->window.getSize().x, - 250 - Ypos);

    sprite.setColor(sf::Color(0, 0, 0, 0));


    _pipeSprites.push_back(sprite);
}

void Pipe::MovePipes(float dt)
{
    for(std::vector<sf::Sprite>::iterator itr = _pipeSprites.begin(); itr != _pipeSprites.end();
           itr++)
        {

            if(((*itr).getPosition().x) < (0 - (*itr).getGlobalBounds().width))
                {
                    _pipeSprites.erase(itr);
                }
            else
                {

                    float mouvement = PIPE_SPEED * dt;
                    (*itr).move(-mouvement, 0);
                }
        }
}





const std::vector<sf::Sprite> &Pipe::GetSprites() const
{
    return _pipeSprites;
}

} // GameWrapper