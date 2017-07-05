#ifndef BOUNCE_ENTITY_INCLUDED
#define BOUNCE_ENTITY_INCLUDED

#include <memory>

#include "SFML\System\Vector2.hpp"
#include "SFML\Graphics\Rect.hpp"

#include "Drawable.h"

namespace sf{ class Time; }

class Entity : public Drawable
{
public:
	enum class Type
	{
		PLAYER,
		PLATFORM,
		DANGER
	};
	virtual ~Entity() = 0;
	virtual bool collidesWith(const Entity& otherEntity) const;
	virtual void manageCollision(const Entity& otherEntity) = 0;
	virtual void update(const sf::Time& delta) = 0;
	virtual const sf::Vector2f& getPosition() const;
	virtual void setPosition(sf::Vector2f newPosition);
	virtual Entity::Type getType() const;
	virtual const sf::FloatRect getCollisionBox() const;

protected:
	Entity(std::shared_ptr<sf::Texture> texture, Entity::Type entityType, sf::Vector2f position, sf::FloatRect collisionBox);
	sf::Vector2f mPosition;

private:
	Entity::Type mType;
	// Internal collision box is in object-space!
	sf::FloatRect mCollisionBox;
};

#endif // BOUNCE_ENTITY_INCLUDED