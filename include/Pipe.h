#ifndef PIPE_H
#define PIPE_H

#include "Game.h"
#include "Rng.h"
#include "config.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace GameWrapper
{

class Pipe
{
  public:
    Pipe(GameDataRef data);

    void SpawnPipes();

    void MovePipes(float dt);

    void DrawPipes();

    const std::vector<sf::Sprite>& GetSprites() const;
    std::vector<sf::Sprite>& GetScoringSprites();

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
