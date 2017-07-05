#ifndef BOUNCE_LEVEL_BUILDER_INCLUDED
#define BOUNCE_LEVEL_BUILDER_INCLUDED

#include <memory>

#include "SFML\System\Vector2.hpp"

#include "EntityCreator.h"

class EntityManager;
class InputSource;

class LevelBuilder
{
public:
	LevelBuilder(float levelWidth, float levelStartYPos);
	void addPlayer(EntityManager& entityManager, std::unique_ptr<InputSource> input);
	void buildUpTo(EntityManager& entityManager, float yPos);

private:
	static const sf::Vector2f PLAYER_STARTING_POSITION;
	static const float ENTITY_Y_DIST, ENTITY_X_DIST;
	static const int MIN_PLATFORM_ELEMENTS, MAX_PLATFORM_ELEMENTS;
	float mLevelWidth, mHighestRowYPos;
	EntityCreator mEntityCreator;
};

#endif // BOUNCE_LEVEL_BUILDER_INCLUDED