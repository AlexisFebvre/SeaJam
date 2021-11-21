#include "input.h"

// cotructor
Input::Input()
{
	button.down = button.escape = button.space = button.up = false;
	buttonReleased.down = buttonReleased.escape = buttonReleased.space = buttonReleased.up = false;
}


// get struct
Input::Button Input::getButton(void) const
{
	return button;
}

Input::Button Input::getButtonReleased(void) const
{
	return buttonReleased;
}


// input handler function
void Input::inputHandler(sf::Event event, sf::RenderWindow& window)
{
	button.down = button.escape = button.space = button.up = false;
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
	buttonReleased.down = buttonReleased.escape = buttonReleased.space = buttonReleased.up = false;
	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			buttonReleased.escape = true;
			break;
		case sf::Keyboard::Down:
			buttonReleased.down = true;
			break;
		case sf::Keyboard::Up:
			buttonReleased.up = true;
			break;
		case sf::Keyboard::Space:
			buttonReleased.space = true;
		default:
			break;
		}
	}

}


