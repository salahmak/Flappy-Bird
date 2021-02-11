#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "config.h"
#include <SFML/Audio.hpp>
#include <map>
#include <string>

namespace GameWrapper
{

class SoundManager
{
  public:
    SoundManager();
    ~SoundManager();

    void Init();

    void Play(std::string name);

    void LoadSound(std::string name, std::string path);
    sf::SoundBuffer& GetSoundBuffer(std::string name);

  private:
    std::map<std::string, sf::Sound> _Sounds;
    std::map<std::string, sf::SoundBuffer> _SoundBuffers;
};

}
#endif