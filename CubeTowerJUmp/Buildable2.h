#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Buildable2
{
public:
	Buildable2();
	~Buildable2();

	sf::Sprite m_buildable2Sprite;				//BUILDABLE 2 SPRITE
	sf::Texture m_buildable2Texture;			//BUILDABLE 2 TEXTURE
	sf::Texture m_buildable2Texture2;			//BUILDABLE 2 TEXTURE
	sf::Texture m_buildable2Texture3;			//BUILDABLE 2 TEXTURE


	sf::Sprite m_drop_zone;				//BUILDABLE 1 SPRITE
	sf::Texture m_drop_zoneT;			//BUILDABLE 1 TEXTURE
	sf::Texture m_drop_zoneT2;			//BUILDABLE 1 TEXTURE
	sf::Texture m_drop_zoneT3;			//BUILDABLE 1 TEXTURE

//	sf::RectangleShape m_drop_zone;				//DROPZONE FOR THE PARTS

	bool loadSecondStageOnce = false;
	bool loadThirdStageOnce = false;
	void secondStage();
	void thirdStage();
	bool alive{ false };						//ALIVE BOOL FOR THE BUILDABLE
	bool dropZone_alive{ false };				//ALIVE BOOL FOR THE DROPZONE
	void draw(sf::RenderWindow& m_window);		//DRAW FUNCTION
	void update();

};

