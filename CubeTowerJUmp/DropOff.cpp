#include "DropOff.h"
DropOff::DropOff()
{

	if (!m_brokenGenTexture.loadFromFile("./Assets/tempGeneratorBroken.png"))
	{
		std::cout << "error with player texture file";
	}

	alive = true;
	//dropOff.setSize(sf::Vector2f(100, 100));
	//dropOff.setOutlineColor(sf::Color::White);
	//dropOff.setFillColor(sf::Color::Black);
	//dropOff.setOutlineThickness(1);
	//dropOff.setPosition(950, 720);

	m_brokenGenSprite.setTexture(m_brokenGenTexture);
	m_brokenGenSprite.setPosition(950, 720);
	m_brokenGenSprite.scale(0.5f, 0.5f);
}

DropOff::~DropOff()
{
}

void DropOff::draw(sf::RenderWindow& m_window)
{	
	if (alive == true)
	{
		m_window.draw(m_brokenGenSprite);
	}
}

void DropOff::update()
{
}
