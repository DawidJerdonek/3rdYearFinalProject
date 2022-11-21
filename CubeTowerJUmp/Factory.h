#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Factory
{
public:
	Factory();
	~Factory();

	sf::Texture m_factoryTexture1;
	sf::Texture m_factoryTexture12;
	sf::Texture m_factoryTexture13;


	sf::Texture m_factoryTexture2;
	sf::Texture m_factoryTexture3;



	sf::Sprite m_factorySprites[9];

	sf::Vector2f m_pos[9]{ {900.0f, 3100.0f} , {1300.0f, 3100.0f} , {1700.0f, 3100.0f} , {2100.0f, 3100.0f} ,{2500.0f, 3100.0f}
	, {570.0f, 3590.0f} , {570.0f, 3990.0f}  , {570.0f, 4390.0f} , {570.0f, 4790.0f} };

	bool loadSecondStageFactoriesOnce = false;
	bool loadThirdStageFactoriesOnce = false;
	void secondStageFactories();
	void thirdStageFactories();
	void draw(sf::RenderWindow& m_window);

	void update();
};

