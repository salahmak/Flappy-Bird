#include "SoundManager.h"
#include <SFML/Audio.hpp>

namespace GameWrapper
{

SoundManager::SoundManager() {}

SoundManager::~SoundManager() {}

void SoundManager::Init()
{
	this->_Sounds["hit"].setBuffer(this->GetSoundBuffer("hit"));
	this->_Sounds["wing"].setBuffer(this->GetSoundBuffer("wing"));
	this->_Sounds["point"].setBuffer(this->GetSoundBuffer("point"));
}

void SoundManager::Play(std::string name)
{
    this->_Sounds[name].play();
}

void SoundManager::LoadSound(std::string name, std::string path)
{
    sf::SoundBuffer soundBuffer;
    if(soundBuffer.loadFromFile(path))
        {
            this->_SoundBuffers[name] = soundBuffer;
        }
}

sf::SoundBuffer& SoundManager::GetSoundBuffer(std::string name)
{
    return this->_SoundBuffers[name];
}

}