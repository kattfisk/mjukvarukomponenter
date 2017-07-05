#ifndef BOUNCE_GAME_INCLUDED
#define BOUNCE_GAME_INCLUDED

#include <memory>

#include "SFML\System\String.hpp"
#include "SFML\System\Clock.hpp"
#include "SFML\System\Time.hpp"

#include "GraphicsManager.h"
#include "EntityManager.h"
#include "LevelBuilder.h"

class Player;

class Game
{
public:
	Game(int gameAreaWidth, int gameAreaHeight);
	void run();

private:
	static const sf::String WINDOW_TITLE;
	sf::Clock mTimer;
	GraphicsManager mGraphics;
	EntityManager mEntityManager;
	LevelBuilder mLevelBuilder;
	static const sf::Time UPDATE_INTERVAL;
	static const int MAX_UPDATES_PER_FRAME;
};

#endif // BOUNCE_GAME_INCLUDED