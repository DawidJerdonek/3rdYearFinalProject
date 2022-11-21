#pragma once
#include "Rubbish.h"

Rubbish::Rubbish()
{
	srand(time(NULL));
	randomRubbish = rand() % 13 + 1;

	m_rubbishSprite.setScale(2.5f, 2.5f);

}
Rubbish::~Rubbish()
{
}
void Rubbish::draw(sf::RenderWindow& m_window)
{
	m_window.draw(m_rubbishSprite);
}
void Rubbish::update()
{
	if (randomRubbish == 1)
	{
		if (!m_rubbishTexture.loadFromFile("./Assets/RubbishTextures/1.png"))
		{
			std::cout << "error with randomRubbish1 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture);
	}
	else if (randomRubbish == 2)
	{
		if (!m_rubbishTexture2.loadFromFile("./Assets/RubbishTextures/2.png"))
		{
			std::cout << "error with randomRubbish2 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture2);
	}
	else if (randomRubbish == 3)
	{
		if (!m_rubbishTexture3.loadFromFile("./Assets/RubbishTextures/3.png"))
		{
			std::cout << "error with randomRubbish3 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture3);
	}
	else if (randomRubbish == 4)
	{
		if (!m_rubbishTexture4.loadFromFile("./Assets/RubbishTextures/4.png"))
		{
			std::cout << "error with randomRubbish4 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture4);
	}
	else if (randomRubbish == 5)
	{
		if (!m_rubbishTexture5.loadFromFile("./Assets/RubbishTextures/5.png"))
		{
			std::cout << "error with randomRubbish5 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture5);
	}
	else if (randomRubbish == 6)
	{
		if (!m_rubbishTexture6.loadFromFile("./Assets/RubbishTextures/6.png"))
		{
			std::cout << "error with randomRubbish6 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture6);
	}
	else if (randomRubbish == 7)
	{
		if (!m_rubbishTexture7.loadFromFile("./Assets/RubbishTextures/7.png"))
		{
			std::cout << "error with randomRubbish7 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture7);
	}
	else if (randomRubbish == 8)
	{
		if (!m_rubbishTexture8.loadFromFile("./Assets/RubbishTextures/8.png"))
		{
			std::cout << "error with randomRubbish8 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture8);
	}
	else if (randomRubbish == 9)
	{
		if (!m_rubbishTexture9.loadFromFile("./Assets/RubbishTextures/9.png"))
		{
			std::cout << "error with randomRubbish9 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture9);
	}
	else if (randomRubbish == 10)
	{
		if (!m_rubbishTexture10.loadFromFile("./Assets/RubbishTextures/10.png"))
		{
			std::cout << "error with randomRubbish10 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture10);
	}
	else if (randomRubbish == 11)
	{
		if (!m_rubbishTexture11.loadFromFile("./Assets/RubbishTextures/11.png"))
		{
			std::cout << "error with randomRubbish11 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture11);
	}
	else if (randomRubbish == 12)
	{
		if (!m_rubbishTexture12.loadFromFile("./Assets/RubbishTextures/12.png"))
		{
			std::cout << "error with randomRubbish12 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture12);
	}
	else if (randomRubbish == 13)
	{
		if (!m_rubbishTexture13.loadFromFile("./Assets/RubbishTextures/13.png"))
		{
			std::cout << "error with randomRubbish13 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture13);
	}
	else if (randomRubbish == 14)
	{
		if (!m_rubbishTexture14.loadFromFile("./Assets/RubbishTextures/14.png"))
		{
			std::cout << "error with randomRubbish14 texture file";
		}
		m_rubbishSprite.setTexture(m_rubbishTexture14);
	}
}