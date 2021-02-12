#include "Bird.h"

namespace GameWrapper
{

Bird::Bird(GameDataRef data) : _data(data)
{
    _animationIterator = 0;

    _animationFrames.push_back(_data->assets.GetTexture("bird 1"));
    _animationFrames.push_back(_data->assets.GetTexture("bird 2"));
    _animationFrames.push_back(_data->assets.GetTexture("bird 3"));
    _animationFrames.push_back(_data->assets.GetTexture("bird 4"));
    _deathFrames.push_back(_data->assets.GetTexture("bird 3"));
    _deathFrames.push_back(_data->assets.GetTexture("bird 4"));

    _birdSprite.setScale(0.09f, 0.09f);

    _birdSprite.setTexture(_animationFrames[_animationIterator]);

    _birdSprite.setPosition(
        (SCREEN_WIDTH / 4) - (_birdSprite.getGlobalBounds().width / 2),
        (SCREEN_HEIGHT / 2) - (_birdSprite.getGlobalBounds().height / 2));

    _birdState = BIRD_STATE_STILL;

    sf::Vector2f origin
        = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2,
                       _birdSprite.getGlobalBounds().height / 2);

    _birdSprite.setOrigin(origin);

    _rotation = 0;
}

void Bird::Draw()
{
    _data->window.draw(_birdSprite);
}

void Bird::Animate(float dt)
{

    if(_clock.getElapsedTime().asSeconds() > (dt / _animationFrames.size()))
        {
            if(_birdState != BIRD_STATE_FALLING)
                {

                    if(_animationIterator < _animationFrames.size() - 1)
                        {
                            _animationIterator++;
                        }
                    else
                        {
                            _animationIterator = 0;
                        }

                    _birdSprite.setTexture(
                        _animationFrames[_animationIterator]);
                    _clock.restart();
                }
        }
}

void Bird::AnimateDeath(float dt)
{
    _animationIterator = 0;

    if(_clock.getElapsedTime().asSeconds() > (dt / _deathFrames.size()))
        {
            if(_animationIterator < _deathFrames.size() - 1)
                {
                    _animationIterator++;
                }
            else
                {
                    _animationIterator = 0;
                }

            _birdSprite.setTexture(_deathFrames[_animationIterator]);
            _clock.restart();
        }
}

void Bird::Update(float dt)
{
    if(_birdState == BIRD_STATE_FALLING)
        {
            _birdSprite.move(0, GRAVITY * dt);

            _rotation += ROTATION_SPEED * dt;

            if(_rotation > 25.0f)
                {
                    _rotation = 25.0f;
                }

            _birdSprite.setRotation(_rotation);
        }
    else if(_birdState == BIRD_STATE_FLYING)
        {
            if(_birdSprite.getPosition().y
               < 0 + _birdSprite.getGlobalBounds().height / 2)
                {
                    _birdSprite.setPosition(
                        _birdSprite.getPosition().x,
                        0 + _birdSprite.getGlobalBounds().height / 2);
                }
            _birdSprite.move(0, -FLYING_SPEED * dt);

            _rotation -= ROTATION_SPEED * dt;

            if(_rotation < -25.0f)
                {
                    _rotation = -25.0f;
                }

            _birdSprite.setRotation(_rotation);
        }

    if(_mouvementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
        {
            _mouvementClock.restart();
            _birdState = BIRD_STATE_FALLING;
        }
}

void Bird::Tap()
{
    _mouvementClock.restart();
    this->_data->sound.Play("wing");
    _birdState = BIRD_STATE_FLYING;
}

const sf::Sprite& Bird::GetSprite() const
{
    return _birdSprite;
}

} // GameWrapper