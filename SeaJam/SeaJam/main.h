#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include "input.h"
#include "fish.h"
#include "trash.h"

// namespaces
using namespace std;

// prototypes
void loadFont();
void setText(sf::Text& text, string str);
void checkConstBtn();
void checkBtn();
// fish prototype

// trash prototypes
void initTrashTexture();
void createTrash(int count, std::vector<sf::Sprite>& spriteArray);


// variables
sf::Font font;
double oceanSpeed = -1;
int score = 0;

// sprites
sf::Sprite fishSprite;

// trash
vector<sf::Sprite> trashArray;
vector<sf::Sprite> trashOnScreenArray;
long int trashCount = 0;

//const int WIN_WIDTH = sf::VideoMode::getDesktopMode().width;
//const int WIN_HEIGHT = sf::VideoMode::getDesktopMode().height;

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

#endif // !MAIN_H
