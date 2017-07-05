#ifndef BOUNCE_GRAPHICS_MANAGER_INCLUDED
#define BOUNCE_GRAPHICS_MANAGER_INCLUDED

#include <memory>

#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Graphics\Rect.hpp"
#include "SFML\Graphics\Color.hpp"
#include "SFML\Graphics\Text.hpp"
#include "SFML\System\Vector2.hpp"

namespace sf
{
	class String;
}
class Drawable;

class GraphicsManager
{
public:
	GraphicsManager(sf::String windowTitle, int windowWidthPx, int windowHeightPx);
	void clear();
	void drawObject(const Drawable& object);
	void display();
	bool windowIsOpen();
	void moveViewUpTo(float yPosition);
	sf::FloatRect getViewArea() const;
	void printText(const sf::String &text);

private:
	sf::RenderWindow mWindow;
	// Hold copy of shared_ptr so that ResourceManager knows the resource is in use
	std::shared_ptr<sf::Font> mFont;
	sf::Text mText;
	static const sf::Color BACKGROUND_COLOR;
	static const sf::String FONT_NAME;
	static const int TEXT_SIZE;
};

#endif // BOUNCE_GRAPHICS_MANAGER_INCLUDED