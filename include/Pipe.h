#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"
#include "Rng.h"




namespace GameWrapper {

class Pipe
{
public:
	Pipe(GameDataRef data);


	void SpawnPipes();

	void MovePipes(float dt);

	void DrawPipes();


	const std::vector<sf::Sprite> &GetSprites() const;

private:
	GameDataRef _data;
	std::vector<sf::Sprite> _pipeSprites;
	std::vector<sf::Sprite> _scoringSprites;
	
	void SpawnBottomPipe(int Ypos);
	void SpawnTopPipe(int Ypos);
	void SpawnInvisiblePipe(int Ypos);
	void SpawnScoringPipe();
	
};


} // GameWrapper



#endif // PIPE_H
