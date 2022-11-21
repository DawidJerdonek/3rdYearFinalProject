#include "Factory.h"

Factory::Factory()
{
	//coulours
	if (!m_factoryTexture1.loadFromFile("./Assets/factories/factory1.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!m_factoryTexture12.loadFromFile("./Assets/factories/factory1-2.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!m_factoryTexture13.loadFromFile("./Assets/factories/factory1-3.png"))
	{
		std::cout << "error with player texture file";
	}
	





	for (int i = 0; i < 9; i++)
	{
		m_factorySprites[i].setTexture(m_factoryTexture13);
	}


	//for (int i = 3; i < 6; i++)
	//{
	//	m_factorySprites[i].setTexture(m_factoryTexture2);
	//}

	//if (!m_factoryTexture3.loadFromFile("./Assets/f3.png"))
	//{
	//	std::cout << "error with player texture file";
	//}

	//for (int i = 6; i < 9; i++)
	//{
	//	m_factorySprites[i].setTexture(m_factoryTexture3);
	//}

	for (int i = 0; i < 9; i++)
	{
		m_factorySprites[i].setPosition(m_pos[i]);
	}
}


Factory::~Factory()
{
}



void Factory::draw(sf::RenderWindow& m_window)
{
	

	for (int i = 0; i < 9; i++)
	{
		m_window.draw(m_factorySprites[i]);
	}
}

void Factory::update()
{
}

void Factory::secondStageFactories()
{
	for (int i = 0; i < 9; i++)
	{
		m_factorySprites[i].setTexture(m_factoryTexture12);
	}
	loadSecondStageFactoriesOnce = true;
}
void Factory::thirdStageFactories()
{
	for (int i = 0; i < 9; i++)
	{
		m_factorySprites[i].setTexture(m_factoryTexture1);
	}
	loadThirdStageFactoriesOnce = true ;
}
