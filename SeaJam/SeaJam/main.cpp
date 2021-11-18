#include "main.h"

sf::RenderWindow window; // create the window's variable

// prototypes
void handleEvents(sf::Event event, sf::RenderWindow& window);

int main()
{
	// render window + vsync
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SeaJam");
	window.setVerticalSyncEnabled(true);

	// game loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			handleEvents(event, window);
		}

		

	}

	return 0;
}

void handleEvents(sf::Event event, sf::RenderWindow& window)
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
}