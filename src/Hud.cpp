#include "Hud.h"

namespace GameWrapper
{

Hud::Hud(GameDataRef data, int highScore) : _data(data)
{
    _scoreText.setFont(this->_data->assets.GetFont("score font"));

    _scoreText.setString("0");

    _scoreText.setCharacterSize(85);

    _scoreText.setOutlineColor(sf::Color::Black);

    _scoreText.setOutlineThickness(1.0f);

    _scoreText.setFillColor(sf::Color::White);

    _scoreText.setPosition(10, 0);



    _highScoreText.setFont(this->_data->assets.GetFont("score font"));

    _highScoreText.setString("HI=" + std::to_string(highScore));

    _highScoreText.setCharacterSize(30);

    _highScoreText.setOutlineColor(sf::Color::Black);

    _highScoreText.setOutlineThickness(1.0f);

    _highScoreText.setFillColor(sf::Color::White);

    _highScoreText.setPosition(10, _scoreText.getGlobalBounds().height + _highScoreText.getGlobalBounds().height);
}

void Hud::Draw(){
	this->_data->window.draw(_scoreText);
	this->_data->window.draw(_highScoreText);
}

void Hud::UpdateScore(int score)
{
    _scoreText.setString(std::to_string(score));
}

}