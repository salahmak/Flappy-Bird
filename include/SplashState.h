#ifndef SPLASH_STATE_H
#define SPLASH_STATE_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "config.h"
#include "Game.h"
#include "State.h"


namespace GameWrapper
{

class SplashState: public State
{
	public:
		SplashState(GameDataRef data);
		~SplashState();

		void Init();
	    void Update(float dt);
	    void HandleInput();
	    void Draw(float dt);
	    void Pause();
	    void Resume();

	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _background;
};
	
}

#endif // SPLASH_STATE_H
