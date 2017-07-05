#include "Player.h"

#include "SFML\System\Time.hpp"
#include "SFML\Graphics\Rect.hpp"

#include "InputSource.h"

const float Player::GRAVITATIONAL_PULL = 400.0f, 
            Player::TERMINAL_VELOCITY = 800.0f,
            Player::JUMP_STRENGTH = 500.0f,
            Player::MOVE_SPEED = 150.0f,
			Player::START_SPEED = 500.0f;

Player::Player(std::shared_ptr<sf::Texture> upTexture, std::shared_ptr<sf::Texture> downTexture, sf::Vector2f position, sf::FloatRect collisionBox, std::unique_ptr<InputSource> inputSource)
	: Entity(upTexture, Entity::Type::PLAYER, position, collisionBox),
	  mInputSource(std::move(inputSource)),
	  mVelocity(0.0, -START_SPEED),
	  mDownTexture(downTexture),
	  mAlive(true)
{
}

Player::~Player()
{
}

void Player::manageCollision(const Entity& otherEntity)
{
	if(otherEntity.getType() == Entity::Type::PLATFORM && mVelocity.y > 0.0f)
	{ // If falling into platform
		mVelocity.y = -JUMP_STRENGTH;
	}
}

void Player::update(const sf::Time& delta)
{
	// Move player
	mVelocity.x = mInputSource->getDirection() * MOVE_SPEED;

	mVelocity.y += GRAVITATIONAL_PULL * delta.asSeconds();
	if(mVelocity.y > TERMINAL_VELOCITY)
	{
		mVelocity.y = TERMINAL_VELOCITY;
	}

	mPosition += mVelocity * delta.asSeconds();
	mSprite.setPosition(mPosition);

	// Change texture depending on heading up or down
	if(mVelocity.y <= 0.0)
	{ // Up
		mSprite.setTexture(*mTexture);
	}
	else
	{ // Down
		mSprite.setTexture(*mDownTexture);
	}

	// Flip texture depending on heading left or right
	sf::Vector2i textureSize(mSprite.getTexture()->getSize());
	if(mVelocity.x > 0.0)
	{ // Right, unflip
		mSprite.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	}
	else if(mVelocity.x < 0.0)
	{ // Left, flip along Y-axis
		mSprite.setTextureRect(sf::IntRect(textureSize.x, 0, -textureSize.x, textureSize.y));
	}
}

void Player::kill()
{
	mAlive = false;
}

bool Player::isAlive() const
{
	return mAlive;
}