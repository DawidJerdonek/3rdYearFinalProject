#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include "Player.h"
#include "Rubbish.h"

class Projectile
{
public:

	Projectile();
	~Projectile();

	//dt is delta time to ensure proper projectile movement regardless of fps
	void update(double dt, Player t_player, sf::RenderWindow& t_window)
	{
		if (m_rubbishSucked != true && m_projectileShot != true)
		{
			m_projectileSprite.setPosition(t_player.getPlayerPosition());
		}
		else if (m_rubbishSucked != true)
		{
			m_projectileSprite.setPosition(m_currentProjectileLocation);
		}
		shoot(dt, t_player, t_window);

		m_ammoText.setString(std::to_string(m_ammo));
		m_ammoText.setPosition(t_player.armsSprite.getPosition().x + 700, t_player.armsSprite.getPosition().y + 450);
		m_ammoSquare.setPosition(t_player.armsSprite.getPosition().x + 700, t_player.armsSprite.getPosition().y + 450);
	}
	void shoot(double dt, Player t_player, sf::RenderWindow& t_window);
	void render(sf::RenderWindow& t_window);

	sf::VertexArray m_projectileLine{ sf::Lines };
	sf::VertexArray m_rubbishLine{ sf::Lines };
	sf::Vector2f playerPosition;
	sf::Vector2f crosshairPosition;

	sf::Text m_ammoText;
	sf::RectangleShape m_ammoSquare;
	sf::Font m_font;
	
	bool m_projectileShot = false;
	bool m_rubbishSucked = false;
	int m_ammo = 0;



	//audio for shooting 
	sf::SoundBuffer suckBuffer;
	sf::Sound suckSound;

private:

	sf::Vector2f m_mouseLocation; //Location of mouse when pressed
	sf::Vector2f m_direction; //Direction to mouse from player
	sf::Vector2f m_unitVector;
	sf::Vector2f m_velocityVector;
	sf::Vector2f m_currentProjectileLocation;

	sf::Vector2f m_playerPositionOnShot;
	sf::Vector2f m_crosshairPositionOnShot;

	sf::Texture m_projectileTexture;
	sf::Sprite m_projectileSprite;


	float m_speed = 15.0f; //Speed of shot
	float m_suckSpeed = 15.0f; //Speed of vaccum
	float m_distance; //Distance to travel
	double m_playerRotation;


};