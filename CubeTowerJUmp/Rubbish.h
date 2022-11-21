#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
class Rubbish
{
public:
	Rubbish();
	~Rubbish();
	//sf::RectangleShape rubbishRec;
	sf::Sprite m_rubbishSprite;
	sf::Texture m_rubbishTexture;
	sf::Texture m_rubbishTexture2;
	sf::Texture m_rubbishTexture3;
	sf::Texture m_rubbishTexture4;
	sf::Texture m_rubbishTexture5;
	sf::Texture m_rubbishTexture6;
	sf::Texture m_rubbishTexture7;
	sf::Texture m_rubbishTexture8;
	sf::Texture m_rubbishTexture9;
	sf::Texture m_rubbishTexture10;
	sf::Texture m_rubbishTexture11;
	sf::Texture m_rubbishTexture12;
	sf::Texture m_rubbishTexture13;
	sf::Texture m_rubbishTexture14;

	int randomRubbish;
	bool rubbishExisting = true;

	void draw(sf::RenderWindow& m_window);
	void update();
};