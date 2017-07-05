#include "KeyboardInput.h"

#include "SFML\Window\Keyboard.hpp"

KeyboardInput::KeyboardInput()
{
}

KeyboardInput::~KeyboardInput()
{
}

float KeyboardInput::getDirection()
{
// TODO: only take input if window has focus
	float direction = 0.0f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction -= 1.0f;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction += 1.0f;
	}
	return direction;
}