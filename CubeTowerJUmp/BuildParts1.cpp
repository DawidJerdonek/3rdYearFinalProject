#pragma once
#include "BuildParts1.h"
BuildParts1::BuildParts1()
{
	//srand(time(NULL));
	alive = true;
	randomX = rand() % 500 + 50.0f;
	randomY = rand() % 500 + 50.0f;

	if (!partTexture.loadFromFile("./Assets/genPart1.png"))
	{
		std::cout << "error with player texture file";
	}
	partSprite.setTexture(partTexture);
	partSprite.setScale(0.2, 0.2);
	partSprite.setPosition(randomX, randomY);

}

BuildParts1::~BuildParts1()
{
}

void BuildParts1::draw(sf::RenderWindow& m_window)
{
	if (alive == true)
	{
		m_window.draw(partSprite);
	}
}

void BuildParts1::update(Player t_player)
{
	if (alive == true)
	{
		if (PartPicked == true)
		{
			partSprite.setPosition(t_player.getPlayerPosition());
		}
	}
}

void BuildParts1::itemUp()
{
	if (alive == true)
	{
		PartPicked = true;
	}
}

void BuildParts1::itemDown()
{
	PartPicked = false;
}
