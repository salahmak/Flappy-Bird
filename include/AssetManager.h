#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>	
#include <SFML/Graphics.hpp>

namespace GameWrapper {

class AssetManager
{
public:
	AssetManager(){}
	~AssetManager(){}

	void LoadTexture(std::string name, std::string path );
	sf::Texture &GetTexture(std::string name);

	void LoadFont(std::string name, std::string path);
	sf::Font &GetFont(std::string name);

private:
	std::map<std::string, sf::Texture> _Textures;
	std::map<std::string, sf::Font> _Fonts;


	
};



} // GameWrapper



#endif // ASSET_MANAGER_H
	