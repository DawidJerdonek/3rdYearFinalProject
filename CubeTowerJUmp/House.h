#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class House
{
public:

	House();
	~House();

	sf::Texture m_houseTexture1;
	sf::Texture m_houseTexture12;
	sf::Texture m_houseTexture13;
	sf::Texture m_houseTexture2;
	sf::Texture m_houseTexture22;
	sf::Texture m_houseTexture23;


	sf::Sprite m_houseSprites[10];

	sf::Vector2f m_pos[10]{ {910.0f, 660.0f} , { 1310.0f, 1580.0f } , { 1710.0f, 660.0f } , { 2110.0f, 1580.0f } , { 2510.0f, 660.0f }
	,{ 910.0f, 1580.0f }  , { 1310.0f, 660.0f } , { 1710.0f, 1580.0f } , { 2110.0f, 660.0f } , { 2510.0f, 1580.0f } };

	bool loadSecondStageHousesOnce = false;
	bool loadThirdStageHousesOnce = false;
	void draw(sf::RenderWindow& m_window);
	void update();
	void secondStageHouses();
	void thirdStageHouses();
};

