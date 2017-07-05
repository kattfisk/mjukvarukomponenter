#include "EntityCreator.h"

#include <cassert>

#include "SFML\Graphics\Texture.hpp"
#include "SFML\System\Vector2.hpp"

#include "ResourceManager.h"
#include "Platform.h"
#include "Player.h"
#include "InputSource.h" // move of unique_ptr requires complete type

const std::string EntityCreator::PLAYER_UP_TEXTURE = "kit_up_right.png",
                  EntityCreator::PLAYER_DOWN_TEXTURE = "kit_down_right.png",
                  EntityCreator::PLATFORM_LEFT_TEXTURE = "tile_21.png",
                  EntityCreator::PLATFORM_MIDDLE_TEXTURE = "tile_22.png",
                  EntityCreator::PLATFORM_RIGHT_TEXTURE = "tile_62.png";
// Scale and offset as part of sprite size
const sf::Vector2f EntityCreator::PLAYER_COLLISION_BOX_SCALE(0.5f, 0.15f), 
                   EntityCreator::PLAYER_COLLISION_BOX_OFFSET(0.25f, 0.75f);

EntityCreator::EntityCreator()
{
}

std::unique_ptr<Player> EntityCreator::createPlayer(std::unique_ptr<InputSource> input, sf::Vector2f position)
{
	std::shared_ptr<sf::Texture> playerUpTexture(ResourceManager::getTexture(PLAYER_UP_TEXTURE));
	std::shared_ptr<sf::Texture> playerDownTexture(ResourceManager::getTexture(PLAYER_DOWN_TEXTURE));
	
	assert(playerUpTexture->getSize() == playerDownTexture->getSize());
	// Assume that both textures are same size
	sf::Vector2f textureSize(playerUpTexture->getSize());

	sf::Vector2f collisionBoxPosition = textureSize;
	collisionBoxPosition.x *= PLAYER_COLLISION_BOX_OFFSET.x;
	collisionBoxPosition.y *= PLAYER_COLLISION_BOX_OFFSET.y;

	sf::Vector2f collisionBoxSize = textureSize;
	collisionBoxSize.x *= PLAYER_COLLISION_BOX_SCALE.x;
	collisionBoxSize.y *= PLAYER_COLLISION_BOX_SCALE.y;

	sf::FloatRect collisionBox(collisionBoxPosition, collisionBoxSize);

	Player* newPlayer = new Player(playerUpTexture, playerDownTexture, position, collisionBox, std::move(input));
	return std::unique_ptr<Player>(newPlayer);
}

std::unique_ptr<Entity> EntityCreator::createLevelEntity(EntityCreator::LevelEntityType type, sf::Vector2f position)
{
	switch(type)
	{
	case LevelEntityType::PLATFORM_LEFT:
	{
		std::shared_ptr<sf::Texture> platformTexture(ResourceManager::getTexture(PLATFORM_LEFT_TEXTURE));
		sf::FloatRect collisionBox(sf::Vector2f(0.0, 0.0), sf::Vector2f(platformTexture->getSize()));
		Platform* newPlatform = new Platform(platformTexture, position, collisionBox);
		return std::unique_ptr<Entity>(newPlatform);
	}
	break;
	case LevelEntityType::PLATFORM_MIDDLE:
	{
		std::shared_ptr<sf::Texture> platformTexture(ResourceManager::getTexture(PLATFORM_MIDDLE_TEXTURE));
		sf::FloatRect collisionBox(sf::Vector2f(0.0, 0.0), sf::Vector2f(platformTexture->getSize()));
		Platform* newPlatform = new Platform(platformTexture, position, collisionBox);
		return std::unique_ptr<Entity>(newPlatform);
	}
	break;
	case LevelEntityType::PLATFORM_RIGHT:
	{
		std::shared_ptr<sf::Texture> platformTexture(ResourceManager::getTexture(PLATFORM_RIGHT_TEXTURE));
		sf::FloatRect collisionBox(sf::Vector2f(0.0, 0.0), sf::Vector2f(platformTexture->getSize()));
		Platform* newPlatform = new Platform(platformTexture, position, collisionBox);
		return std::unique_ptr<Entity>(newPlatform);
	}
	break;
	default:
	{
		// All cases should be covered above. If we get here something is wrong.
		assert(false);
		// In release version return a platform to avoid further runtime errors.
		std::shared_ptr<sf::Texture> platformTexture(ResourceManager::getTexture(PLATFORM_MIDDLE_TEXTURE));
		sf::FloatRect collisionBox(position, sf::Vector2f(platformTexture->getSize()));
		Platform* newPlatform = new Platform(platformTexture, position, collisionBox);
		return std::unique_ptr<Entity>(newPlatform);
	}
	break;
	}
}