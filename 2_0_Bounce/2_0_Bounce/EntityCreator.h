#ifndef BOUNCE_ENTITY_CREATOR_INCLUDED
#define BOUNCE_ENTITY_CREATOR_INCLUDED

#include <memory>
#include <string>

#include "SFML\System\Vector2.hpp"

class Player;
class InputSource;
class Entity;

class EntityCreator
{
public:
	EntityCreator();
	enum class LevelEntityType
	{
		PLATFORM_LEFT,
		PLATFORM_MIDDLE,
		PLATFORM_RIGHT
	};
	std::unique_ptr<Player> createPlayer(std::unique_ptr<InputSource> input, sf::Vector2f position);
	std::unique_ptr<Entity> createLevelEntity(EntityCreator::LevelEntityType type, sf::Vector2f position);

private:
	static const std::string PLAYER_UP_TEXTURE,
	                         PLAYER_DOWN_TEXTURE,
	                         PLATFORM_LEFT_TEXTURE,
	                         PLATFORM_MIDDLE_TEXTURE,
	                         PLATFORM_RIGHT_TEXTURE;
	static const sf::Vector2f PLAYER_COLLISION_BOX_SCALE, 
	                          PLAYER_COLLISION_BOX_OFFSET;
};

#endif // BOUNCE_ENTITY_CREATOR_INCLUDED