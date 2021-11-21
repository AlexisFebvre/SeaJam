#include "main.h"



// variables
sf::Text helloWorld("Hello world !", font);
sf::RenderWindow window; // create the window's variable

// input handler
Input input;

int main(int argc, char* argv[])
{
	// render window + vsync
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SeaJam");
	window.setVerticalSyncEnabled(true);

	// text
	loadFont();
	setText(helloWorld, "Hello world !");

	// fish
	sf::Texture fishTexture;
	if (!fishTexture.loadFromFile("res/assets/fish.png"))
	{
		cout << "could not load \"res/assets/fish.png\"" << endl;
		return -1;
	}
	fishSprite.setTexture(fishTexture);
	///////

	// ocean
	sf::Texture oceanTexture;
	if (!oceanTexture.loadFromFile("res/assets/ocean.png"))
	{
		cout << "could not load \"res/assets/ocean.png\"" << endl;
	}
	sf::Sprite oceanSprite;
	oceanSprite.setTexture(oceanTexture);
	oceanSprite.move(0, 150);
	////////



	// game loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			input.inputHandler(event, window);
			checkBtn();
		}

		// update stuff here
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			fishSprite.move(0, 1);
		}
		////////////////////


		// draw stuff here	
		window.clear(sf::Color(255, 255, 255, 255)); // clear the window
		window.draw(helloWorld);
		window.draw(fishSprite);
		window.draw(oceanSprite);

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
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}


void checkBtn()
{
	if (input.getButton().escape)
	{
		window.close();
	} 
	else if (input.getButton().space)
	{
		helloWorld.setString("space");
	}
	else if (input.getButton().down)
	{
		helloWorld.setString("Down");
	}
	else if (input.getButton().up)
	{
		helloWorld.setString("Up");
	}
}