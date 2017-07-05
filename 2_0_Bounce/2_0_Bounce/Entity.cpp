#include "Entity.h"

Entity::~Entity()
{
}

bool Entity::collidesWith(const Entity& otherEntity) const
{
	return(this->getCollisionBox().intersects(otherEntity.getCollisionBox()));
}

const sf::Vector2f& Entity::getPosition() const
{
	return mPosition;
}

void Entity::setPosition(sf::Vector2f newPosition)
{
	mPosition = newPosition;
}

Entity::Type Entity::getType() const
{
	return mType;
}

const sf::FloatRect Entity::getCollisionBox() const
{
	// mCollisionBox uses object coordinate space, return box that uses world coordinates
	return sf::FloatRect(mPosition.x + mCollisionBox.left, mPosition.y + mCollisionBox.top, 
	                     mCollisionBox.width, mCollisionBox.height);
}

Entity::Entity(std::shared_ptr<sf::Texture> texture, Entity::Type entityType, sf::Vector2f position, sf::FloatRect collisionBox)
	: Drawable(texture),
	  mPosition(position),   
	  mType(entityType),
	  mCollisionBox(collisionBox)
{
}