#include "AssetManager.h"

namespace GameWrapper
{

void AssetManager::LoadTexture(std::string name, std::string path)
{
    sf::Texture tex;

    if(tex.loadFromFile(path))
        {
            this->_Textures[name] = tex;
        }
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
    return this->_Textures[name];
}

void AssetManager::LoadFont(std::string name, std::string path)
{
    sf::Font font;

    if(font.loadFromFile(path))
        {
            this->_Fonts[name] = font;
        }
}

sf::Font& AssetManager::GetFont(std::string name)
{
    return this->_Fonts[name];
}

} // Game