#include "main.h"



// variables
sf::RenderWindow window; // create the window's variable


// ocean variables
sf::Sprite oceanSpriteSecond;
sf::Sprite oceanSprite;
int gap = 1920;
double steps = 0;
int phase = 0;
//////////////////


// years counter
int yearsCounter = 1950;
sf::Text yearsCounterText("years : " + to_string(yearsCounter), font);
int tmpYearsCounter = yearsCounter;
double yearSteps = 0;
////////////////

// trash counter
int trashCounter = trashCount;
long previousTrashCount = trashCount;
int trashToDisplay = trashCount - previousTrashCount;
sf::Text trashCounterText("trash count : " + to_string(trashCounter) + " MT", font);
char trashPhase = 'A';
////////////////


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
	// years counter
	yearsCounterText.setFillColor(sf::Color::Black);
	yearsCounterText.setCharacterSize(60);
	yearsCounterText.move(25, 0);
	// trash counter
	trashCounterText.setFillColor(sf::Color::Black);
	trashCounterText.setCharacterSize(60);
	trashCounterText.move(650, 0);

	// fish
	sf::Texture fishTexture;
	if (!fishTexture.loadFromFile("res/assets/fish.png"))
	{
		cout << "could not load \"res/assets/fish.png\"" << endl;
		return -1;
	}
	fishSprite.setTexture(fishTexture);
	fishSprite.setPosition(25, 500);
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

	// tmp score
	double tmpScore = 0;

	srand(time(NULL));


	// init trash
	initTrashTexture();
	createTrash(trashCount, trashArray);


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

		////////

		// score
		tmpScore += 0.01;
		score = round(tmpScore);
		////////

		// years
		yearSteps += 0.01;

		if (yearSteps >= 1)
		{
			yearsCounter++;
			yearSteps = 0;
		}


		// trash
		if (tmpYearsCounter != yearsCounter)
		{
			tmpYearsCounter = yearsCounter;
			float tmpIncrementation;
			switch (trashPhase)
			{
			case 'A':
				tmpIncrementation = 1.8;
				break;
			case 'B':
				tmpIncrementation = 6;
				break;
			case 'C':
				tmpIncrementation = -4;
				break;
			case 'D':
				tmpIncrementation = 26.5;
				break;

			default:
				break;
			}
			trashCount += round(tmpIncrementation);

			switch (yearsCounter)
			{
			case 1975:
				trashPhase = 'B';
				break;
			case 2005:
				trashPhase = 'C';
				break;
			case 2010:
				trashPhase = 'D';
				break;
			default:
				break;
			}
			createTrash(tmpIncrementation, trashArray);
			trashCounter += tmpIncrementation;
		}

		////////

		// counter
		trashCounterText.setString("trash count : " + to_string(trashCounter) + "MT");
		yearsCounterText.setString("years : " + to_string(yearsCounter));

		////////////////////


		// draw stuff here	
		window.clear(sf::Color(255, 255, 255, 255)); // clear the window
		window.draw(fishSprite);


		for (int i = 0; i < trashArray.size(); i++)
		{
			window.draw(trashArray[i]);
		}

		for (int i = 0; i < trashArray.size(); i++)
		{
			if (trashArray[i].getPosition().x < 0)
			{
				trashArray.erase(trashArray.begin() + i);
			}
			trashArray[i].move(oceanSpeed * 0.5, 0);
		}

		// ocean
		window.draw(oceanSprite);
		window.draw(oceanSpriteSecond);



		window.draw(yearsCounterText);
		window.draw(trashCounterText);

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
	}
	else if (input.getButton().down)
	{
	}
	else if (input.getButton().up)
	{
	}

	// released
	if (input.getButtonReleased().up || input.getButtonReleased().down)
	{
		fishSprite.setRotation(0);
	}

}

