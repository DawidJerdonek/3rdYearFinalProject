#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <math.h>
#include "Player.h"

class Projectile
{
public:

	Projectile();
	~Projectile();

	//dt is delta time to ensure proper projectile movement regardless of fps
	void update(double dt, Player t_player, sf::Window& t_window);
	void shoot(double dt, Player t_player, sf::Window& t_window);
	void render(sf::RenderWindow& t_window);

	sf::VertexArray m_projectileLine{ sf::Lines };
	sf::Vector2f playerPosition;

	bool m_projectileShot = false;
private:

	sf::Vector2f m_mouseLocation; //Location of mouse when pressed
	sf::Vector2f m_direction; //Direction to mouse from player
	sf::Vector2f m_unitVector;
	sf::Vector2f m_velocityVector;
	sf::Vector2f m_currentProjectileLocation;

	float m_speed = 10.0f; //Speed of shot
	float m_distance; //Distance to travel
	double m_playerRotation;
};