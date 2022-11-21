#include "Buildable1.h"

Buildable1::Buildable1()
{
	if (!m_buildable1Texture.loadFromFile("./Assets/genon.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_buildable1Texture2.loadFromFile("./Assets/genon1-2.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_buildable1Texture3.loadFromFile("./Assets/genon1-3.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_drop_zoneT.loadFromFile("./Assets/genoff.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_drop_zoneT2.loadFromFile("./Assets/genoff1-2.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_drop_zoneT3.loadFromFile("./Assets/genoff1-3.png"))
	{
		std::cout << "error with gen texture file";
	}

	m_buildable1Sprite.setTexture(m_buildable1Texture3);
	m_buildable1Sprite.setPosition(4100.0f, 400.0f);

	m_drop_zone.setTexture(m_drop_zoneT3);
	m_drop_zone.setPosition(4100.0f, 400.0f);
	dropZone_alive = true;
	alive = false;

}

Buildable1::~Buildable1()
{
}

void Buildable1::draw(sf::RenderWindow& m_window)
{
	if (alive == true)
	{
		m_window.draw(m_buildable1Sprite);
	}
	if (dropZone_alive == true)
	{
		m_window.draw(m_drop_zone);
	}
}

void Buildable1::update()
{
}

void Buildable1::secondStage()
{
	m_buildable1Sprite.setTexture(m_buildable1Texture2);
	m_drop_zone.setTexture(m_drop_zoneT2);
	loadSecondStageOnce = true;
}

void Buildable1::thirdStage()
{
	m_buildable1Sprite.setTexture(m_buildable1Texture);
	m_drop_zone.setTexture(m_drop_zoneT);
	loadThirdStageOnce = true;
	
}
