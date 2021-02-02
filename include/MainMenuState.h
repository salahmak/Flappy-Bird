#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "config.h"
#include "Game.h"
#include "State.h"

namespace GameWrapper
{

class MainMenuState: public State
{
public:
	MainMenuState(GameDataRef data);

		void Init();
	    void Update(float dt);
	    void HandleInput();
	    void Draw(float dt);
	    void Pause();
	    void Resume();

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _playBtn;
		sf::Sprite _title;

		sf::Text _highScoreText;

		int _highScore;

};
}



#endif // MAIN_MENU_STATE_H
