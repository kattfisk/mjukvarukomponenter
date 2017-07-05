#include "Platform.h"

Platform::Platform(std::shared_ptr<sf::Texture> texture, sf::Vector2f position, sf::FloatRect collisionBox)
	: Entity(texture, Entity::Type::PLATFORM, position, collisionBox)
{
	mSprite.setPosition(mPosition);
}

Platform::~Platform()
{
}

void Platform::manageCollision(const Entity&)
{
	// Do nothing
}

void Platform::update(const sf::Time&)
{
	// Do nothing
}