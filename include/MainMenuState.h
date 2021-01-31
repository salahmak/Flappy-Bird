#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"
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

};
}



#endif // MAIN_MENU_STATE_H
