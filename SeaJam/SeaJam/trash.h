#ifndef TRASH_H
#define TRASH_H

#include "main.h"


// texture
int p = 0;



sf::Texture cokeCanTexture;

void initTrashTexture()
{
	if (!cokeCanTexture.loadFromFile("res/assets/trash/cokeCan.png"))
	{
		std::cout << "Could not load \"res/assets/trash/cokeCan.png\"" << std::endl;
	}
}

// trash
void createTrash(int count, std::vector<sf::Sprite>& spriteArray)
{
	for (int i = 0; i < count; i++)
	{
		sf::Sprite tmpSprite;
		
		tmpSprite.setTexture(cokeCanTexture);
		float s = (float(rand()) / float((RAND_MAX)) * 1.0);
		tmpSprite.setScale(s, s);

		int xTrash = rand() % 1200 + 1200;
		int yTrash = rand() % 600 + 100;
		tmpSprite.setPosition(xTrash, yTrash);
		spriteArray.push_back(tmpSprite);
	}
}





#endif // !TRASH_H

