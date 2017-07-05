#include "ResourceManager.h"

#include <cassert>
#include <string>

#include "SFML\Graphics\Texture.hpp"
#include "SFML\Graphics\Font.hpp"

const std::string ResourceManager::RESOURCE_PATH = "./data/";
std::map<std::string, std::shared_ptr<sf::Texture>> ResourceManager::mTextures;
std::map<std::string, std::shared_ptr<sf::Font>> ResourceManager::mFonts;

void ResourceManager::freeUnused()
{
	for(auto resource = mTextures.begin(); resource != mTextures.end(); )
	{
		if(resource->second.use_count() < 2)
		{ // There are no other users
			// Delete last pointer to object, triggering destruction
			resource = mTextures.erase(resource);
		}
		else
		{
			++resource;
		}
	}
}

const std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string filename)
{
	assert(filename != "");
	if(mTextures.count(filename) == 0)
	{
		sf::Texture* newTexture = new sf::Texture();
		newTexture->loadFromFile(RESOURCE_PATH + filename);
		mTextures[filename] = std::shared_ptr<sf::Texture>(newTexture);
	}
	return mTextures[filename];
}

const std::shared_ptr<sf::Font> ResourceManager::getFont(const std::string filename)
{
	assert(filename != "");
	if(mFonts.count(filename) == 0)
	{
		sf::Font* newFont = new sf::Font();
		newFont->loadFromFile(RESOURCE_PATH + filename);
		mFonts[filename] = std::shared_ptr<sf::Font>(newFont);
	}
	return mFonts[filename];
}

ResourceManager::ResourceManager()
{
}