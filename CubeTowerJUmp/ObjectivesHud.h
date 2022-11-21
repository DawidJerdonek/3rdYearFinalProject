#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Player.h"
class ObjectivesHud
{
public:
	ObjectivesHud();
	~ObjectivesHud();

	sf::Texture m_phone;
	sf::Sprite m_miniPhoneSprite;

	bool m_viewObjectives = false;
	bool m_objectiveComplete1 = false;
	bool m_objectiveComplete2 = false;
	bool m_objectiveComplete3 = false;
	bool m_objectiveComplete4 = false;

	sf::Texture genObjectivesTexture;
	sf::Sprite genObjectivesSprite1;
	sf::Sprite genObjectivesSprite2;
	
	sf::Font m_font;
	sf::Text m_taskOneText;
	sf::Text m_taskTwoText;
	sf::Text m_taskThreeText;
	sf::Text m_taskFourText;

	bool gen1ObjectiveDone = { false };
	bool gen2ObjectiveDone = { false };

	void draw(sf::RenderWindow& m_window);
	void update(Player t_player);
};

