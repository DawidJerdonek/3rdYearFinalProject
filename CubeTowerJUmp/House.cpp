#include "House.h"

House::House()
{
	if (!m_houseTexture1.loadFromFile("./Assets/houses/house1.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_houseTexture12.loadFromFile("./Assets/houses/house1-2.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_houseTexture13.loadFromFile("./Assets/houses/house1-3.png"))
	{
		std::cout << "error with house texture file";
	}
	for (int i = 0; i < 5; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture13);
	}


	if (!m_houseTexture2.loadFromFile("./Assets//houses/house2.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_houseTexture22.loadFromFile("./Assets//houses/house2-2.png"))
	{
		std::cout << "error with house texture file";
	}
	if (!m_houseTexture23.loadFromFile("./Assets//houses/house2-3.png"))
	{
		std::cout << "error with house texture file";
	}
	for (int i = 5; i < 10; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture23);
	}



	for (int i = 0; i < 10; i++)
	{
		m_houseSprites[i].setPosition(m_pos[i]);
	}

}

House::~House()
{

}

void House::draw(sf::RenderWindow& m_window)
{
	//m_window.draw(m_houseSprite1);
	//m_window.draw(m_houseSprite2);
	for (int i = 0; i < 10; i++)
	{
		m_window.draw(m_houseSprites[i]);
	}
}

void House::update()
{
}

void House::secondStageHouses()
{
	for (int i = 0; i < 5; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture12);
	}

	for (int i = 5; i < 10; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture22);
	}
	loadSecondStageHousesOnce = true;
}

void House::thirdStageHouses()
{
	for (int i = 0; i < 5; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture1);
	}

	for (int i = 5; i < 10; i++)
	{
		m_houseSprites[i].setTexture(m_houseTexture2);
	}
	loadThirdStageHousesOnce = true;

}
