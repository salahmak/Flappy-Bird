#include "Hud.h"

namespace GameWrapper
{

Hud::Hud(GameDataRef data) : _data(data)
{
    _scoreText.setFont(this->_data->assets.GetFont("score font"));

    _scoreText.setString("0");

    _scoreText.setCharacterSize(100);

    _scoreText.setOutlineColor(sf::Color::Black);

    _scoreText.setOutlineThickness(1.0f);

    _scoreText.setFillColor(sf::Color::White);

    _scoreText.setPosition(sf::Vector2f(10, 0));
}

void Hud::Draw(){
	this->_data->window.draw(_scoreText);
}

void Hud::UpdateScore(int score)
{
    _scoreText.setString(std::to_string(score));
}

}