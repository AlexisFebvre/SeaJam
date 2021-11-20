#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Input
{
	struct Button { bool up, down, escape, space; };

public:
	// constuctor's input
	Input();
	// prototypes
	Input::Button getButton(void) const;
	void inputHandler(sf::Event event, sf::RenderWindow& window);

private:
	Button button;

};

#endif