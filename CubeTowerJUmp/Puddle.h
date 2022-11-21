#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Puddle
{
public:
	Puddle();
	~Puddle();

	sf::Texture m_puddleTexture;
	sf::Texture m_puddleTexture2;
	sf::Texture m_puddleTexture3;
	sf::Sprite m_puddleSprites[2];

	bool loadSecondStagePuddleOnce = false;
	bool loadThirdStagePuddleOnce = false;
	void secondStagePuddle();
	void thirdStagePuddle();

	sf::Vector2f m_pos[2]{ {1500.0f, 100.0f} , {100.0f, 680.0f } };


	void draw(sf::RenderWindow& m_window);
	void update();
};

