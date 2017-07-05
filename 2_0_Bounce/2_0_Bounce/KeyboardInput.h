#ifndef BOUNCE_KEYBOARD_INPUT_INCLUDED
#define BOUNCE_KEYBOARD_INPUT_INCLUDED

#include "InputSource.h"

class KeyboardInput : public InputSource
{
public:
	KeyboardInput();
	virtual ~KeyboardInput();
	virtual float getDirection() override;

private:
};

#endif // BOUNCE_KEYBOARD_INPUT_INCLUDED