#include "Buildable2.h"

Buildable2::Buildable2()
{
	if (!m_buildable2Texture.loadFromFile("./Assets/genon.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_buildable2Texture2.loadFromFile("./Assets/genon1-2.png"))
	{
		std::cout << "error with gen texture file";
	}
	if (!m_buildable2Texture3.loadFromFile("./Assets/genon1-3.png"))
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

	m_buildable2Sprite.setTexture(m_buildable2Texture3);
	m_buildable2Sprite.setPosition(4400.0f, 1200.0f);
	m_buildable2Sprite.setColor(sf::Color::Yellow);

	m_drop_zone.setTexture(m_drop_zoneT3);
	m_drop_zone.setPosition(4400.0f, 1200.0f);
	dropZone_alive = true;
	alive = false;

}

Buildable2::~Buildable2()
{
}

void Buildable2::draw(sf::RenderWindow& m_window)
{
	if (alive == true)
	{
		m_window.draw(m_buildable2Sprite);
	}
	if (dropZone_alive == true)
	{
		m_window.draw(m_drop_zone);
	}
}

void Buildable2::update()
{
}

void Buildable2::secondStage()
{
	m_buildable2Sprite.setTexture(m_buildable2Texture2);
	m_buildable2Sprite.setColor(sf::Color::Yellow);
	m_drop_zone.setTexture(m_drop_zoneT2);
	loadSecondStageOnce = true;
}

void Buildable2::thirdStage()
{
	m_buildable2Sprite.setTexture(m_buildable2Texture);
	m_buildable2Sprite.setColor(sf::Color::Yellow);
	m_drop_zone.setTexture(m_drop_zoneT);
	loadThirdStageOnce = true;

}