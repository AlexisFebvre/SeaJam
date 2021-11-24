#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include "input.h"
#include "fish.h"

// namespaces
using namespace std;

// prototypes
void loadFont();
void setText(sf::Text& text, string str);
void checkConstBtn();
void checkBtn();
// fish prototype
void fishUp(sf::Sprite& fish);
void fishDown(sf::Sprite& fish);

// variables
sf::Font font;
double oceanSpeed = -1;
int score = 0;

// sprites
sf::Sprite fishSprite;

//const int WIN_WIDTH = sf::VideoMode::getDesktopMode().width;
//const int WIN_HEIGHT = sf::VideoMode::getDesktopMode().height;

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

#endif // !MAIN_H
