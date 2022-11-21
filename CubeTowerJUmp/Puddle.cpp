#include "Puddle.h"

Puddle::Puddle()
{
	if (!m_puddleTexture.loadFromFile("./Assets/puddle.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_puddleTexture2.loadFromFile("./Assets/puddle-2.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_puddleTexture3.loadFromFile("./Assets/puddle-3.png"))
	{
		std::cout << "error with house texture file";
	}
	for (int i = 0; i < 2; i++)
	{
		m_puddleSprites[i].setTexture(m_puddleTexture3);
		m_puddleSprites[i].setPosition(m_pos[i]);
	}
}


Puddle::~Puddle()
{

}

void Puddle::draw(sf::RenderWindow& m_window)
{
	for (int i = 0; i < 2; i++)
	{
		m_window.draw(m_puddleSprites[i]);
	}
}

void Puddle::update()
{
}

void Puddle::secondStagePuddle()
{
	for (int i = 0; i < 2; i++)
	{
		m_puddleSprites[i].setTexture(m_puddleTexture2);
		loadSecondStagePuddleOnce = true;
	}
}


void Puddle::thirdStagePuddle()
{
	for (int i = 0; i < 2; i++)
	{
		m_puddleSprites[i].setTexture(m_puddleTexture);
		loadThirdStagePuddleOnce = true;
	}
}
