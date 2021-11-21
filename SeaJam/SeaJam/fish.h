#ifndef FISH_H
#define FISH_H

#include "main.h"


void fishUp(sf::Sprite& fish, double speed)
{
	fish.setRotation(-25);
	fish.move(0, -2.5 * speed / 2);

	if (fish.getPosition().y > 700)
		fish.setPosition(15, 700);
	if (fish.getPosition().y < 180)
		fish.setPosition(15, 180);
}

void fishDown(sf::Sprite& fish, double speed)
{
	fish.setRotation(25);
	fish.move(0, 2.5 * speed / 2);
	if (fish.getPosition().y > 700)
		fish.setPosition(15, 700);
	if (fish.getPosition().y < 180)
		fish.setPosition(15, 180);
}

#endif

