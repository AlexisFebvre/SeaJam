#include "main.h"



// variables
sf::Text helloWorld("Hello world !", font);
sf::RenderWindow window; // create the window's variable

// input handler
Input input;

int main()
{
	// render window + vsync
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SeaJam");
	window.setVerticalSyncEnabled(true);

	// text
	loadFont();
	setText(helloWorld, "Hello world !");




	// game loop
	while (window.isOpen())
	{
		// constant inputs
		constantInputs();
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			input.inputHandler(event, window);
		}

		// update stuff here
		
		////////////////////


		// draw stuff here	
		window.clear(); // clear the window
		window.draw(helloWorld);

		// displaying all stuff
		window.display();

	}

	return 0;
}


void loadFont()
{
	if (!font.loadFromFile("res/fonts/poppins.ttf"))
	{
		cout << "cannot load res/fonts/poppins.ttf" << endl;
	}
}


void setText(sf::Text& text, string str)
{
	text.setString(str);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}
