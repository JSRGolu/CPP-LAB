#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>

class Window
{
public:

	// Default constructor with no parameters
	Window();

	//Constructor that receives a window titl and size.
	Window(const std::string& title, const sf::Vector2u& size);

	//Default destructor.
	~Window();

	// Setups the window with a title and a size for it.
	void setup(const std::string& title, const sf::Vector2u& size);

	// A function for indicating SFML that we are starting a drawing round.
	void beginDraw();

	// A function for telling SFML that we have finished indicated what needs to be drawn and drawing can happen.
	void endDraw();

	// Updates the state of the window.
	void update();

	// Toggles the full screen status of the window on/off.
	void toggleFullscreen();

	// Draws a Drawable object to the screen.
	void draw(sf::Drawable& drawable);

	// Redraws the whole screen
	void redraw();

	// A group of setter and getter functions for the state of this window:
	bool isWindowDone() const { return isDone; }
	bool isWindowFullscreen() const { return isFullscreen; }
	inline void setSize(const sf::Vector2u& size) { windowSize = size; }
	const sf::Vector2u& getWindowSize() const { return windowSize; }
	inline void setTitle(const std::string& t) { windowTitle = t; }
	const std::string& getTitle() const { return windowTitle; }

private:

	//Destroys this window. Private so only this object can manage how to do that.
	void destroy();

	//Creates this window.  Private so only this object can manage how to do that.
	void create();

	// Twe window itself where we draw stuff.
	sf::RenderWindow window;

	// Size of the window.
	sf::Vector2u windowSize;

	// String with the title of the window.
	std::string windowTitle;

	// Flag that indicates if the window is "done". It will be "done" if we are closing up the application (false by default).
	bool isDone;

	// Flag that indicates if the window is currently full screen or not (false by default).
	bool isFullscreen;
};

