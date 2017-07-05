#ifndef BOUNCE_DRAWABLE_INCLUDED
#define BOUNCE_DRAWABLE_INCLUDED

#include <memory>

#include "SFML\Graphics\Sprite.hpp"

class Drawable
{
public:
	virtual const sf::Sprite& getSprite() const;
	virtual ~Drawable() = 0;

protected:
	Drawable(std::shared_ptr<sf::Texture> texture);
	sf::Sprite mSprite;
	// Hold a copy of the shared pointer so that ResourceManager can know that the texture is in use.
	std::shared_ptr<sf::Texture> mTexture;
};

#endif // BOUNCE_DRAWABLE_INCLUDED