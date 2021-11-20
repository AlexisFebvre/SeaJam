#include "input.h"

// cotructor
Input::Input()
{
	button.down = button.escape = button.space = button.up = false;
}

// get struct
Input::Button Input::getButton(void) const
{
	return button;
}


// input handler function
void Input::inputHandler(sf::Event event, sf::RenderWindow& window)
{
	switch (event.type)
	{
		// window events
	case sf::Event::Closed:
		window.close();
		break;
	default:
		break;
	}

	// single pressed/released
	// pressed
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			button.escape = true;
			break;
		case sf::Keyboard::Down:
			button.down = true;
			break;
		case sf::Keyboard::Up:
			button.up = true;
			break;
		case sf::Keyboard::Space:
			button.space = true;
		default:
			break;
		}
	}

	// released
	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			button.escape = true;
			break;
		case sf::Keyboard::Down:
			button.down = true;
			break;
		case sf::Keyboard::Up:
			button.up = true;
			break;
		case sf::Keyboard::Space:
			button.space = true;
		default:
			break;
		}
	}

}