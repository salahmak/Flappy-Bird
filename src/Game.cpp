#include "Game.h"
#include "SplashState.h"
#include "GameState.h"


namespace GameWrapper {


Game::Game(int width, int height, std::string title)
{
	this->_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	this->_data->window.setFramerateLimit(60);
	this->_data->window.setKeyRepeatEnabled(false);
	// this->_data->machine.AddState(StateRef(new GameState(_data)));
	this->_data->machine.AddState(StateRef(new SplashState(_data)));

	this->run();

}



void Game::run()
{

	while(this->_data->window.isOpen())
	{
		this->_data->machine.ProcessStateChanges();
		this->_data->machine.GetActiveState()->HandleInput();
		this->_data->machine.GetActiveState()->Update(dt);
		this->_data->machine.GetActiveState()->Draw(0.1f);
	}




}


} // GameWrapper





