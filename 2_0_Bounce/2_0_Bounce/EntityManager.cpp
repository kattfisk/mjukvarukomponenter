#include "EntityManager.h"

#include <cassert>

#include "SFML\System\Clock.hpp"

#include "GraphicsManager.h"
#include "Entity.h"
#include "Player.h"

EntityManager::EntityManager()
	: mPlayer(nullptr),
	  mLevelEntities()
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::setPlayer(std::unique_ptr<Player> player)
{
	assert(player); // Input not nullptr
	assert(!mPlayer); // Player not already set
	mPlayer = std::move(player);
}

const Player& EntityManager::getPlayer() const
{
	assert(mPlayer);
	return *mPlayer;
}

void EntityManager::addLevelEntity(std::unique_ptr<Entity> entity)
{
	mLevelEntities.push_back(std::move(entity));
}

void EntityManager::drawEntities(GraphicsManager& graphics)
{
	if(!mLevelEntities.empty())
	{
		for(auto &i : mLevelEntities)
		{
			graphics.drawObject(*i);
		}
	}
	if(mPlayer)
	{
		graphics.drawObject(*mPlayer);
	}
}

void EntityManager::update(const sf::Time& delta)
{
	if(mPlayer)
	{
		mPlayer->update(delta);
	}
	if(!mLevelEntities.empty())
	{
		for(auto &i : mLevelEntities)
		{
			i->update(delta);
		}
	}
}

void EntityManager::manageCollisions()
{
	if(!mPlayer)
	{
		return;
	}
	if(mLevelEntities.empty())
	{
		return;
	}

	for(auto &i : mLevelEntities)
	{
		if(mPlayer->collidesWith(*i))
		{
			mPlayer->manageCollision(*i);
			i->manageCollision(*mPlayer);
		}
	}
}

void EntityManager::wrapPlayerXCoords(float xMin, float xMax)
{
	// This is not the most pretty way of doing it
	// the sprite will wrap oddly
	// TODO: look into rewriting
	sf::Vector2f position = mPlayer->getPosition();
	if(position.x < xMin)
	{
		position.x += xMax - xMin;
	}
	else if(position.x > xMax)
	{
		position.x -= xMax - xMin;
	}
	mPlayer->setPosition(position);
}

void EntityManager::cullEntitiesBelow(float yPos)
{
	if(mPlayer->getPosition().y > yPos)
	{
		mPlayer->kill();
	}
	
	for(std::vector<std::unique_ptr<Entity>>::iterator i = mLevelEntities.begin(); i != mLevelEntities.end(); )
	{
		if((*i)->getPosition().y > yPos)
		{
			i = mLevelEntities.erase(i);
		}
		else
		{
			++i;
		}
	}
}