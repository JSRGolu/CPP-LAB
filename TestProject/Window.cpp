#include "Window.h"

Window::Window() // : <FILL THIS INITIALIZATION LIST with default values for isDone and isFullScreen>
	: isDone(false), isFullscreen(false)
{ 
	// Initialize the window calling the setup() method with a title and a size.
	// Pick a title of your choice. A recommended size is a sf::Vector2u(640, 480)
	Window::setup( "TestProject!!", sf::Vector2u(640, 480) );
}

Window::Window(const std::string& title, const sf::Vector2u& size) // : <FILL THIS INITIALIZATION LIST with default values for isDone and isFullScreen>	
	: isDone(false), isFullscreen(false), windowTitle(title), windowSize(size)
{
	// Redirect the call to the setup() function with the title and the size.
	Window::setup(title, size);
}


Window::~Window() 
{
	//This destructor needs to liberate the resources of the window when it's being destroyed. 
	// Simply call the destroy() method so it's delegated there.
	Window::destroy();
}


void Window::setup(const std::string& title, const sf::Vector2u& size)
{
	// Give a value to the variables windowTitle, windowSize (from parameters), isFullscreen and isDone (default values).
	// Then, call the create() function that it will give a value to the window member.
	Window::setTitle(title);
	Window::setSize(size);
	Window::create();
}

void Window::create()
{
	// Create a variable "style" of a type deduced by "auto". Set its value to sf::Style::Fullscreen
	// if this object's isFullscreen is true, and to sf::Style::Default if isFullscreen is false.
	int style = isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;
	
	// Create an sf::VideoMode object passing two parameters to its constructor: windowSize.x and windowSize.y.
    //   -> bonus: do this using "direct brace initialization"
	sf::VideoMode videoMode{ windowSize.x, windowSize.y };

	//Call the function create() in sf::RenderWindow window, passing as parameters in this order: video mode, window title and style.
	window.create(videoMode, getTitle(), style);

}

void Window::destroy()
{
	// Call the function close() on the window object. This will liberate the resources used by the sf::RenderWindow.
	window.close();

}

void Window::redraw()
{
	//Simple: two consecutive calls. First to destroy(), then to create().
	Window::destroy();
	Window::create();

}

void Window::toggleFullscreen()
{
	// For toggling the fullscreen status, you do two things:
	//  1. Change the value of the isFullscreen from false to true, and viceversa.
	//  2. Call redraw() in this class so a new window can be created after the current one is destroyed.
	isFullscreen = !isFullscreen;
	Window::redraw();

}



void Window::update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			//This marks that the window has been closed. Set isDone to true.
			isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			//This marks that the key F5 has been pressed. We're binding this to the toggle fullscreen function, so call that function here.
			Window::toggleFullscreen();
		}

	}
}


void Window::beginDraw() 
{ 
	//sf::RenderWindow window has a function clear(), which clears the screen with a color. Call this function passing a black colour
	// (sf::Color::Black) as a parameter.
	window.clear(sf::Color::Black);

}

void Window::draw(sf::Drawable& drawable)
{
	// sf::RenderWindow window has a function "draw" that receives as parameter a sf::Drawable&. 
	// Simply redirect the flow to call the method "draw" in the window object, passing the parameter "drawable" to such function.
	window.draw(drawable);

}

void Window::endDraw() 
{
	// It's time to display all that we've drawn since the last time we cleared the screen.
	// Simply call the display() function in the sf::RenderWindow window object.
	window.display();

}



