#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class DropOff
{
public:
	DropOff();
	~DropOff();
	//sf::RectangleShape dropOff;

	sf::Sprite m_brokenGenSprite;
	sf::Texture m_brokenGenTexture;

	bool alive{ false };
	void draw(sf::RenderWindow& m_window);
	void update();
};