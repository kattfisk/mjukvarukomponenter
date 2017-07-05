#ifndef BOUNCE_PLAYER_INCLUDED
#define BOUNCE_PLAYER_INCLUDED

#include <memory>

#include "SFML\System\Vector2.hpp"
#include "SFML\Graphics\Texture.hpp"

#include "Entity.h"

class InputSource;

class Player : public Entity
{
public:
	Player(std::shared_ptr<sf::Texture> upTexture, std::shared_ptr<sf::Texture> downTexture, sf::Vector2f position, sf::FloatRect collisionBox, std::unique_ptr<InputSource> inputSource);
	virtual ~Player();
	virtual void manageCollision(const Entity& otherEntity) override;
	virtual void update(const sf::Time& delta) override;
	void kill();
	bool isAlive() const;

private:
	std::unique_ptr<InputSource> mInputSource;
	sf::Vector2f mVelocity;
	// Hold a copy of the shared pointer so that ResourceManager knows that the texture is in use
	std::shared_ptr<sf::Texture> mDownTexture;
	bool mAlive;
	static const float GRAVITATIONAL_PULL, 
	                   TERMINAL_VELOCITY, 
	                   JUMP_STRENGTH,
	                   MOVE_SPEED,
	                   START_SPEED;
};

#endif // BOUNCE_PLAYER_INCLUDED