#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

#include "Player.h"

class BuildParts1
{
public:
	BuildParts1();
	~BuildParts1();
	sf::RectangleShape rectanlge;
	sf::Texture partTexture;
	sf::Sprite partSprite;

	bool PartPicked{ false };
	bool alive{ false };
	float randomX;
	float randomY;
	void draw(sf::RenderWindow& m_window);
	void update(Player t_player);
	void itemUp();
	void itemDown();
};