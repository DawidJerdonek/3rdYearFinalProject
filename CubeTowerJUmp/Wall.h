#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Wall
{
public:
	Wall();
	~Wall();

	sf::Texture m_wallTexture;
	sf::Sprite m_wallSprites[24];

	sf::Vector2f m_pos[24]{ {0.0f, 2561.0f}, {384.0f, 2561.0f}, {512.0f, 2561.0f}, {640.0f, 2561.0f}, {768.0f, 2561.0f},
	{896.0f, 2561.0f}, {1024.0f, 2561.0f}, {1152.0f, 2561.0f}, {1280.0f, 2561.0f}, {1408.0f, 2561.0f}, {1536.0f, 2561.0f}, {1664.0f, 2561.0f},
	{1792.0f, 2561.0f}, {1920.0f, 2561.0f}, {2048.0f, 2561.0f}, {2176.0f, 2561.0f}, {2304.0f, 2561.0f}, {2432.0f, 2561.0f}, {2560.0f, 2561.0f},
	{2688.0f, 2561.0f}, {2816.0f, 2561.0f}, {2815.0f, 2688.0f}, {2815.0f, 2816.0f}, {2815.0f, 2944.0f} };

	bool loadSecondStagePuddleOnce = false;
	bool loadThirdStagePuddleOnce = false;
	void draw(sf::RenderWindow& m_window);
	void update();
};

