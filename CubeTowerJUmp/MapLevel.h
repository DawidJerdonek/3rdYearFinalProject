#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class MapLevel
{
public:

	MapLevel();		//CONSTRUCTOR
	~MapLevel();	//DECONSTRUCTOR
	sf::Texture mapTexture;		//MAP TEXTURE
	sf::Texture mapTexture2;		//MAP TEXTURE
	sf::Texture mapTexture3;		//MAP TEXTURE
	sf::Sprite mapSprite;		//MAP SPRITE

	//game stages 
	int gameStage = 0;

	void draw(sf::RenderWindow& m_window);	//MAP DRAW FUNC
	void update();							//MAP UPDATE FUNC
private:
};

