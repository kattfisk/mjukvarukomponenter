#include "Drawable.h"

const sf::Sprite& Drawable::getSprite() const
{
	return mSprite;
}

Drawable::~Drawable()
{}

Drawable::Drawable(std::shared_ptr<sf::Texture> texture)
	: mSprite(*texture),
	  mTexture(texture)
{
	
}