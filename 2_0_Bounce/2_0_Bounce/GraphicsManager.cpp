#include "GraphicsManager.h"

#include "SFML\Window\Event.hpp"

#include "Drawable.h"
#include "ResourceManager.h"

const sf::Color GraphicsManager::BACKGROUND_COLOR(70, 150, 255);
const sf::String GraphicsManager::FONT_NAME("Mockup-Regular.otf");
const int GraphicsManager::TEXT_SIZE(36);

GraphicsManager::GraphicsManager(sf::String windowTitle, int windowWidthPx, int windowHeightPx)
	: mWindow(sf::VideoMode(windowWidthPx, windowHeightPx), windowTitle),
	  mFont(ResourceManager::getFont(FONT_NAME)),
	  mText("", *mFont, TEXT_SIZE)
{
	mWindow.setVerticalSyncEnabled(true);
	
}

void GraphicsManager::clear()
{
	mWindow.clear(BACKGROUND_COLOR);
}

void GraphicsManager::drawObject(const Drawable& object)
{
	mWindow.draw(object.getSprite());
}

void GraphicsManager::display()
{
	mWindow.display();
}

bool GraphicsManager::windowIsOpen()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			mWindow.close();
			return false;
		}
	}
	return mWindow.isOpen();
}


void GraphicsManager::moveViewUpTo(float yPosition)
{
	sf::View view = mWindow.getView();
	float viewDelta = (view.getCenter().y - (view.getSize().y/2.0f)) - yPosition;
	
	if(viewDelta > 0.0f)
	{
		view.move(0.0f, -viewDelta);
		mWindow.setView(view);
	}

}

sf::FloatRect GraphicsManager::getViewArea() const
{
	sf::View view = mWindow.getView();
	sf::FloatRect viewArea(view.getCenter().x - view.getSize().x / 2.0f,
	                       view.getCenter().y - view.getSize().y / 2.0f,
	                       view.getSize().x,
	                       view.getSize().y);
	return viewArea;
}

void GraphicsManager::printText(const sf::String &text)
{
	mText.setString(text);
	// Center text
	sf::FloatRect textBounds(mText.getLocalBounds());
	mText.setOrigin(textBounds.left + textBounds.width / 2.0f,
	                textBounds.top + textBounds.height / 2.0f);
	mText.setPosition(mWindow.getView().getCenter());
	
	mWindow.draw(mText);
}