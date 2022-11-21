#pragma once
class Player
{
public:
	Player();
	~Player();




	sf::Sprite m_playerSprite;

	sf::Vector2f getPlayerPosition() { return m_playerSprite.getPosition(); };


};

