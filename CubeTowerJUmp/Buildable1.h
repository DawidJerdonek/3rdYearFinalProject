#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Buildable1
{
public:
	Buildable1();
	~Buildable1();

	sf::Sprite m_buildable1Sprite;				//BUILDABLE 1 SPRITE
	sf::Texture m_buildable1Texture;			//BUILDABLE 2 TEXTURE
	sf::Texture m_buildable1Texture2;			//BUILDABLE 2 TEXTURE
	sf::Texture m_buildable1Texture3;			//BUILDABLE 2 TEXTURE


	sf::Sprite m_drop_zone;				//BUILDABLE 1 SPRITE
	sf::Texture m_drop_zoneT;			//BUILDABLE 1 TEXTURE
	sf::Texture m_drop_zoneT2;			//BUILDABLE 1 TEXTURE
	sf::Texture m_drop_zoneT3;			//BUILDABLE 1 TEXTURE
	//sf::RectangleShape m_drop_zone;				//DROPZONE FOR THE PARTS


	bool loadSecondStageOnce = false;
	bool loadThirdStageOnce = false;
	void secondStage();
	void thirdStage();

	bool alive{ false };						//ALIVE BOOL FOR THE BUILDABLE
	bool dropZone_alive{ false };				//ALIVE BOOL FOR THE DROPZONE
	void draw(sf::RenderWindow& m_window);		//DRAW FUNCTION
	void update();

};