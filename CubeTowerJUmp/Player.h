#pragma once
#include <iostream>
#include "Globals.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
	const float PI = 3.14159265;

	void draw(sf::RenderWindow& m_window);
	void update(sf::RenderWindow& t_window, float delta);
	
	sf::Sprite m_playerSprite;
	//sf::CircleShape crosshair;
	sf::Texture m_playerTexture;
	sf::Texture m_playerTexture2;
	sf::Texture m_playerTexture3;
	//Crosshair
	sf::Texture m_crosshairTexture;
	sf::Sprite m_crosshairSprite;
	sf::Transform m_crosshairTransform;

	//sf::Texture m_phone;
	//sf::Sprite m_miniPhoneSprite;

	//sf::Sprite m_phoneSprite;

	sf::Vector2f getPlayerPosition() { return m_playerSprite.getPosition(); };

	sf::RectangleShape m_healthShape;

	int m_health = 400;
	int state = 51;
	bool allowWalkRight = false;
	bool allowWalkLeft = false;

	//arms
	sf::Sprite armsSprite;
	sf::Texture armsTexture;

	sf::Texture m_healthBorder;
	sf::Sprite m_healthBorderSprite;
	float velocity = 0;
	//animation
	sf::IntRect rectSourceSprite;
	float totalElapsed = 0;
	int animationframe = 0;
	bool readyToPress = true;
	//bool m_viewObjectives = false;
	void anim();
	void animIdle();
	void boundry();



	bool loadSecondStagePlayerOnce = false;
	bool loadThirdStagePlayerOnce = false;
	void secondStagePlayer();
	void thirdStagePlayer();
};

//
//void hurt(float t_damage) {
//	m_player.setFillColour(sf::Colour::White);
//	m_player.setScale(0.8f, 0.8f);
//	m_particles.instance();
//	m_player.setFillColour(sf::Colour::Red);
//	health -= t_damage;
//	sound.play();
//	m_player.setScale(reset_to_original);
//	m_player.setFillColour(sf::Colour::Transperant);
//
//}