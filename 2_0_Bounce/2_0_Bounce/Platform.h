#ifndef BOUNCE_PLATFORM_INCLUDED
#define BOUNCE_PLATFORM_INCLUDED

#include <memory>

#include "Entity.h"

namespace sf
{
	class Texture;
}

class InputSource;

class Platform : public Entity
{
public:
	Platform(std::shared_ptr<sf::Texture> texture, sf::Vector2f position, sf::FloatRect collisionBox);
	virtual ~Platform();
	virtual void manageCollision(const Entity& otherEntity) override;
	virtual void update(const sf::Time& delta) override;

private:
};

#endif // BOUNCE_PLATFORM_INCLUDED