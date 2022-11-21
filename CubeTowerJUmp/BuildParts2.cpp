#pragma once
#include "BuildParts2.h"
BuildParts2::BuildParts2()
{
	//srand(time(NULL));
	alive = true;
	randomX = rand() % 500 + 50.0f;
	randomY = rand() % 700 + 4000.0f;

	if (!partTexture.loadFromFile("./Assets/genPart1.png"))
	{
		std::cout << "error with player texture file";
	}
	partSprite.setTexture(partTexture);
	partSprite.setScale(0.2, 0.2);
	partSprite.setPosition(randomX, randomY);
	partSprite.setColor(sf::Color::Yellow);

}

BuildParts2::~BuildParts2()
{
}

void BuildParts2::draw(sf::RenderWindow& m_window)
{
	if (alive == true)
	{
		m_window.draw(partSprite);
	}
}

void BuildParts2::update(Player t_player)
{
	if (alive == true)
	{
		if (PartPicked == true)
		{
			partSprite.setPosition(t_player.getPlayerPosition());
		}
	}
}

void BuildParts2::itemUp()
{
	if (alive == true)
	{
		PartPicked = true;
	}
}

void BuildParts2::itemDown()
{
	PartPicked = false;
}
