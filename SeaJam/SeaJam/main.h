#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "input.h"

// namespaces
using namespace std;

// prototypes
void loadFont();
void setText(sf::Text& text, string str);
void constantInputs();
void checkBtn();

// variables
sf::Font font;

// sprites
sf::Sprite fishSprite;

//const int WIN_WIDTH = sf::VideoMode::getDesktopMode().width;
//const int WIN_HEIGHT = sf::VideoMode::getDesktopMode().height;

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;