#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Input
{
	struct Button { bool up, down, escape, space; };
	struct ConstantButton { bool up, down; };

public:
	// constuctor's input
	Input();
	// prototypes
	Input::Button getButton(void) const;
	void inputHandler(sf::Event event, sf::RenderWindow& window);
	Input::Button getButtonReleased(void) const;

private:
	Button button;
	Button buttonReleased;
};

#endif