#ifndef BOUNCE_RESOURCE_MANAGER_INCLUDED
#define BOUNCE_RESOURCE_MANAGER_INCLUDED

#include <map>
#include <memory>
#include <string>

namespace sf
{ 
	class Texture;
	class Font;
}

class ResourceManager
{
public:
	static void freeUnused();
	static const std::shared_ptr<sf::Texture> getTexture(std::string filename);
	static const std::shared_ptr<sf::Font> getFont(std::string filename);

private:
	ResourceManager(); // Disallow instantiation of static class
	static const std::string RESOURCE_PATH;
	static std::map<std::string, std::shared_ptr<sf::Texture>> mTextures;
	static std::map<std::string, std::shared_ptr<sf::Font>> mFonts;
};

#endif // BOUNCE_RESOURCE_MANAGER_INCLUDED