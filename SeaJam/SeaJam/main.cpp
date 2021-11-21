#include "main.h"



// variables
sf::Text helloWorld("Hello world !", font);
sf::RenderWindow window; // create the window's variable


// ocean variables
sf::Sprite oceanSpriteSecond;
sf::Sprite oceanSprite;
int gap = 1920;
double steps = 0;
int phase = 0;
//////////////////


// years counter
int year = 1950;

// input handler
Input input;

int main(int argc, char* argv[])
{
	// render window + vsync
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "SeaJam");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

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
	fishSprite.setPosition(15, 500);
	///////



	// ocean
	sf::Texture oceanTexture;
	if (!oceanTexture.loadFromFile("res/assets/ocean.png"))
	{
		cout << "could not load \"res/assets/ocean.png\"" << endl;
	}
	oceanSprite.setTexture(oceanTexture);
	oceanSprite.scale(1.5, 1);
	oceanSprite.setPosition(-10, 150);
	////////
	
	// ocean second
	oceanSpriteSecond.setTexture(oceanTexture);
	oceanSpriteSecond.scale(1.5, 1);
	oceanSpriteSecond.setPosition(gap, 150);
	///////////////


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
		checkConstBtn();

		// ocean
		if (oceanSprite.getPosition().x <= 0)
		{
			oceanSpriteSecond.setPosition(oceanSprite.getPosition().x + gap, 150);
		}
		if (oceanSpriteSecond.getPosition().x <= 0)
		{
			oceanSprite.setPosition(oceanSpriteSecond.getPosition().x + gap, 150);
		}

		oceanSprite.move(oceanSpeed, 0);
		oceanSpriteSecond.move(oceanSpeed, 0);
	
		

		if (oceanSpeed < -5 && phase == 0)
		{
			steps += 0.002;
			if (steps > 0.5)
			{
				steps = 0;
				phase = 1;
			}
		}
		else if (oceanSpeed < -10 && phase == 1)
		{
			steps += 0.002;
			if (steps > 1.5)
			{
				steps = 0;
				phase = 2;
			}
		}
		else if (oceanSpeed < -15 && phase == 2)
		{
			steps += 0.002;
			if (steps > 3)
			{
				steps = 0;
				phase = 3;
			}
		}
		else if (oceanSpeed < -20 && phase == 3)
		{}
		else
		{
			oceanSpeed -= 0.005;
		}

		

		cout << to_string(oceanSpeed) << endl;
		////////

		////////////////////


		// draw stuff here	
		window.clear(sf::Color(255, 255, 255, 255)); // clear the window
		window.draw(helloWorld);
		window.draw(fishSprite);
		window.draw(oceanSprite);
		window.draw(oceanSpriteSecond);

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


void checkConstBtn()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		fishDown(fishSprite, -oceanSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		fishUp(fishSprite, -oceanSpeed);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		oceanSprite.move(10, 0);
		oceanSpriteSecond.move(10, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
	{
		oceanSprite.move(-10, 0);
		oceanSpriteSecond.move(-10, 0);
	}
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

	// released
	if (input.getButtonReleased().up || input.getButtonReleased().down)
	{
		fishSprite.setRotation(0);
	}

}

