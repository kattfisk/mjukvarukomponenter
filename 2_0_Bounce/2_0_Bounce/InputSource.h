#ifndef BOUNCE_INPUT_SOURCE_INCLUDED
#define BOUNCE_INPUT_SOURCE_INCLUDED

class InputSource
{
public:
	virtual ~InputSource() = 0;
	// Returns direction as a value between -1.0 (full left) and 1.0 (full right)
	virtual float getDirection() = 0;
};

#endif // BOUNCE_INPUT_SOURCE_INCLUDED