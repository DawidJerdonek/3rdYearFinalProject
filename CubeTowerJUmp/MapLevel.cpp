#include "MapLevel.h"

MapLevel::MapLevel()		//LOADING THINGS IN CONSTRUCTOR
{
	if (!mapTexture.loadFromFile("./Assets/TileSets/Map1.png"))
	{
		std::cout << "error with map texture file";
	}
	if (!mapTexture2.loadFromFile("./Assets/TileSets/Map3.png"))
	{
		std::cout << "error with map texture file";
	}
	if (!mapTexture3.loadFromFile("./Assets/TileSets/Map2.png"))
	{
		std::cout << "error with map texture file";
	}
	mapSprite.setTexture(mapTexture3);		//SETTING TEXTURE
	mapSprite.setOrigin(1024.0f, 1024.0f);	//SETTING THE ORIGIN TO 1024,1024 SO OUTSIDE THE MAP WILL BE COVERED IN GRASS AND THAT MAP IS ON POINT
}

MapLevel::~MapLevel()
{
}

void MapLevel::draw(sf::RenderWindow& m_window)
{
	m_window.draw(mapSprite);		//DRAWING THE MAP
}

void MapLevel::update()
{

}
