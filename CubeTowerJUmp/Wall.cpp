#include "Wall.h"

Wall::Wall()
{
	if (!m_wallTexture.loadFromFile("./Assets/Walls/wooden_fenceScaled.png"))
	{
		std::cout << "error with house texture file";
	}
	for (int i = 0; i < 24; i++)
	{
		m_wallSprites[i].setTexture(m_wallTexture);
		m_wallSprites[i].setPosition(m_pos[i]);
	}
	for (int i = 20; i < 24; i++)
	{
		m_wallSprites[i].setRotation(90);
	}
}

Wall::~Wall()
{
}

void Wall::draw(sf::RenderWindow& m_window)
{
	for (int i = 0; i < 24; i++)
	{
		m_window.draw(m_wallSprites[i]);
	}
}

void Wall::update()
{
}
