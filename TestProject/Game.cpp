#include "Game.h"

// CONSTRUCTOR AND DESTRUCTOR

// 1. The default constructor must initialize the window with a string (window title) and an sf::Vector2u(800,600) for its size
//    Also the movement vector for the mushroom should be initalized to x=4.0f, y=4.0f.
//    Both the vector and the window must be set with a "member initializers list" (https://en.cppreference.com/w/cpp/language/constructor)
//    The body of the constructor must:
//      * Load the texture file (mushroom50-50.png) into the sf::Texture member variable using the loadFromFile function of the sf::Texture class.
//      * Set the sf::Texture variable as the texture of the sf::Sprite member (using the sf::Sprite::setTexture(sf::Texture) function).

Game::Game()
	: windowApp("Game Window", sf::Vector2u(1280, 720)), mushroomMovement(0.25f, 0.25f)
{
	if (!mushroomTexture.loadFromFile("mushroom50-50.png"))
		throw std::runtime_error("Failed to load texture!!");

	mushroomSprite.setTexture(mushroomTexture);
}


// 2.  Define an empty default destructor.

Game::~Game() { }


// MEMBER FUNCTIONS:

// 3. For handling the input. This logic will not handle any input yet, so define an empty handling function.

void Game::handleInputs() { }

// 4. For updating tha game state:
//	  a) Call the private function of this class that executes the logic (mushroom movement).
//    b) Call the update function of the window (the window does handle input in the update function. This is not really orthodox, 
//       but it will work for now).

void Game::update()
{
	movement();
	windowApp.update();
}

// 5. Function for rendering the game:
//    a) Our window object offers functionality for clearing the screen. Call the method that starts the draw on the window member first.
//    b) Draw the mushroom on screen, by calling the draw function in window that receives a reference to a sf::Drawable& reference.
//    c) Our window also offers functionality for displaying all that has been drawn since the last clear. Call the method that ends the draw on the window now.

void Game::render()
{
	windowApp.beginDraw();
	windowApp.draw(mushroomSprite);
	windowApp.endDraw();
}

// 6. Define the function that returns a pointer to the window member variable of this class.

Window* Game::getWindow()
{
	return &windowApp;
}


// 7. Define the function for updating the movement of the mushroom.
//    The following is pseudocode (as I don't know how you named your member variables):
//
//    # Some initializations:
//    windowSize <- window.getWindowSize 
//    textureSize <- mushroomTexture.getSize
//    xRightLimit <- windowSize.width - textureSize.width
//    yBottomLimit <- windowSize.height - textureSize.height
//
//    # Check if we are bouncing off the right or left edges:
//    bouncesRight <- (mushroom.xPosition > xRightLimit AND mushroom.movement.x > 0)
//    bouncesLeft <- (mushroom.xPosition < 0 AND mushroom.movement.x < 0)
//    if bouncesRight OR bouncesLeft
//       { change sign of mushroom.movement.x }
//    
//    # Same for top or bottom edges:
//    bouncesBottom <- (mushroom.yPosition > yBottomLimit AND mushroom.movement.y > 0)
//    bouncesTop <- (mushroom.yPosition < 0 AND mushroom.movement.y < 0)
//    if bouncesBottom OR bouncesTop
//       { change sign of mushroom.movement.y }
//
//	  mushroom.setPosition(mushroom.xPosition + mushroom.movement.x, mushroom.yPosition + mushroom.movement.y)

void Game::movement()
{
	sf::Vector2f windowSize{ windowApp.getWindowSize() };
	sf::Vector2f textureSize{ mushroomTexture.getSize() };

	float xRightLimit{ windowSize.x - textureSize.x };
	float yBottomLimit{ windowSize.y - textureSize.y };

	bool bouncesRight{ (mushroomSprite.getPosition().x > xRightLimit && mushroomMovement.x > 0) };
	bool bouncesLeft{ (mushroomSprite.getPosition().x < 0 && mushroomMovement.x < 0) };
	bool bouncesBottom{ (mushroomSprite.getPosition().y > yBottomLimit && mushroomMovement.y > 0) };
	bool bouncesTop{ (mushroomSprite.getPosition().y < 0 && mushroomMovement.y < 0) };

	if (bouncesRight || bouncesLeft) {
		mushroomMovement.x = -mushroomMovement.x;
	}

	if (bouncesBottom || bouncesTop) {
		mushroomMovement.y = -mushroomMovement.y;
	}

	mushroomSprite.setPosition(mushroomSprite.getPosition().x + mushroomMovement.x, mushroomSprite.getPosition().y + mushroomMovement.y);

}