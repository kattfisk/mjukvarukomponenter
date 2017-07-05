#ifndef BOUNCE_ENTITY_MANAGER_INCLUDED
#define BOUNCE_ENTITY_MANAGER_INCLUDED

#include <memory>
#include <vector>

#include "SFML\Graphics\Rect.hpp"

namespace sf
{
	class Time;
}

class Player;
class Entity;
class GraphicsManager;

class EntityManager
{
public:
	EntityManager();
	~EntityManager(); // Non-inline dtor needed for incomplete type in unique_ptr
	void setPlayer(std::unique_ptr<Player> player);
	const Player& getPlayer() const;
	void addLevelEntity(std::unique_ptr<Entity> entity);
	void drawEntities(GraphicsManager& graphics);
	void update(const sf::Time& delta);
	void manageCollisions();
	// Wraps the players X-coordinates inside the specified span
	void wrapPlayerXCoords(float xMin, float xMax);
	void cullEntitiesBelow(float yPos);

private:
	std::unique_ptr<Player> mPlayer;
	std::vector<std::unique_ptr<Entity>> mLevelEntities;
};

#endif // BOUNCE_ENTITY_MANAGER_INCLUDED