#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"
#include <vector>


namespace GameWrapper {

	class Bird
	{
	public:
		Bird(GameDataRef data);

		void Draw();
		void Animate(float dt);

		void Update(float dt);
		void Tap();

		const sf::Sprite &GetSprite() const;
		

	private:
		GameDataRef _data;
		sf::Sprite _birdSprite;

		std::vector<sf::Texture> _animationFrames;

		unsigned int _animationIterator;

		sf::Clock _clock;

		sf::Clock _mouvementClock;

		int _birdState;

		float _rotation;
	};

} // GameWrapper


#endif // BIRD_H
