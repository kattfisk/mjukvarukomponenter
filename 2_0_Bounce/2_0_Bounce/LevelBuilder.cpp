#include "LevelBuilder.h"

#include <cassert>
#include <cstdlib> // For rand and srand
#include <ctime>

#include "EntityManager.h"
#include "Player.h" // Move of unique_ptr requires complete type
#include "InputSource.h" // Move of unique_ptr requires complete type

const sf::Vector2f LevelBuilder::PLAYER_STARTING_POSITION(250.0, 150.0);
const float LevelBuilder::ENTITY_Y_DIST(200.0); // Height distance between "rows" of entites
const float LevelBuilder::ENTITY_X_DIST(32.0); // Width distance between individual entites
const int LevelBuilder::MIN_PLATFORM_ELEMENTS(3); // Minimum number of elements in a platform
const int LevelBuilder::MAX_PLATFORM_ELEMENTS(6); // Maximum number of elements in a platform

LevelBuilder::LevelBuilder(float levelWidth, float levelStartYPos)
	: mLevelWidth(levelWidth),
	  mHighestRowYPos(levelStartYPos),
	  mEntityCreator()
{
	std::srand(unsigned int(std::time(NULL))); // Seed RNG with current time
}

void LevelBuilder::addPlayer(EntityManager& entityManager, std::unique_ptr<InputSource> input)
{
	std::unique_ptr<Player> player(mEntityCreator.createPlayer(std::move(input), PLAYER_STARTING_POSITION));
	assert(player);
	entityManager.setPlayer(std::move(player));
}

void LevelBuilder::buildUpTo(EntityManager& entityManager, float yPos)
{
	// Used below to create entities
	EntityCreator::LevelEntityType entityType(EntityCreator::LevelEntityType::PLATFORM_MIDDLE);
	sf::Vector2f entityPosition(0.0, 0.0);

	// REMEMBER THAT -Y IS UP AND +Y IS DOWN!
	while(mHighestRowYPos - ENTITY_Y_DIST > yPos)
	{ // Build rows up

		float currentRowYPos = mHighestRowYPos - ENTITY_Y_DIST;
		
		// Randomize number of elements in platform
		int platformEntities = MIN_PLATFORM_ELEMENTS + std::rand() % (MAX_PLATFORM_ELEMENTS - MIN_PLATFORM_ELEMENTS + 1);
		
		// Randomize start position of platform between 0.0 and max position where it'll fit
		float currentEntityXPos = float(std::rand() % int(mLevelWidth - ENTITY_X_DIST * platformEntities));

		for(int i = 1; i <= platformEntities; ++i)
		{ // Build entities on row, left to right
			if(i == 1)
			{ // First platform is of type LEFT
				entityType = EntityCreator::LevelEntityType::PLATFORM_LEFT;
			}
			else if(i == platformEntities)
			{ // Last platform is of type RIGHT
				entityType = EntityCreator::LevelEntityType::PLATFORM_RIGHT;
			}
			else
			{ // Other platforms are of type MIDDLE
				entityType = EntityCreator::LevelEntityType::PLATFORM_MIDDLE;
			}

			entityPosition = sf::Vector2f(currentEntityXPos, currentRowYPos);
			entityManager.addLevelEntity(mEntityCreator.createLevelEntity(entityType, entityPosition));
			
			currentEntityXPos += ENTITY_X_DIST;
		}
		mHighestRowYPos = currentRowYPos;
	}
}