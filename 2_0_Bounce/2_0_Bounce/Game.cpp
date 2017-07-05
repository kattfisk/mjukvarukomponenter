#include "Game.h"

#include <memory>

#include "KeyboardInput.h"
#include "Player.h"

const sf::String Game::WINDOW_TITLE = "Bounce!";
const sf::Time Game::UPDATE_INTERVAL = sf::seconds(1.0f / 120.0f);
const int Game::MAX_UPDATES_PER_FRAME = 10; // Prevent runaway updates on slow systems

Game::Game(int gameAreaWidth, int gameAreaHeight)
	: mTimer(),
	  mGraphics(WINDOW_TITLE, gameAreaWidth, gameAreaHeight),
	  mEntityManager(),
	  mLevelBuilder(float(gameAreaWidth), float(gameAreaHeight))
{
	// Create player and input source
	std::unique_ptr<InputSource> keyboard(new KeyboardInput());
	mLevelBuilder.addPlayer(mEntityManager, std::move(keyboard)); // Create player
}

void Game::run()
{
	sf::Time timeBank;
	mTimer.restart();
	while(mGraphics.windowIsOpen())
	{ // TODO: pause game (and timer) when focus is lost
		timeBank += mTimer.restart();

		float playerYPos = mEntityManager.getPlayer().getPosition().y;

		if(mEntityManager.getPlayer().isAlive())
		{
			// Game logic loop
			// We use a variable number of fixed size timesteps
			int updates = 0;
			while(timeBank >= UPDATE_INTERVAL && updates < MAX_UPDATES_PER_FRAME)
			{
				mLevelBuilder.buildUpTo(mEntityManager, playerYPos);

				mEntityManager.update(UPDATE_INTERVAL);
				mEntityManager.manageCollisions();
			
				playerYPos = mEntityManager.getPlayer().getPosition().y;

				timeBank -= UPDATE_INTERVAL;
				++updates;
			}

			mGraphics.moveViewUpTo(playerYPos);
			sf::FloatRect viewArea(mGraphics.getViewArea());
			mEntityManager.wrapPlayerXCoords(viewArea.left, viewArea.left + viewArea.width);
			mEntityManager.cullEntitiesBelow(viewArea.top + viewArea.height);
		}

		mGraphics.clear();
		if(!mEntityManager.getPlayer().isAlive())
		{
			int score(std::max(-int(playerYPos), 0));
			mGraphics.printText("Game Over\nScore: " + std::to_string(score));
		}
		mEntityManager.drawEntities(mGraphics);
		mGraphics.display();
	}
}
