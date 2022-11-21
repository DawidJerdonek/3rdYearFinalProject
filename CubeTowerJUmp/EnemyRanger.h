#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"


class EnemyRanger
{
public:
	EnemyRanger();
	~EnemyRanger();
	sf::Texture enemyRangerTexture;
	sf::Texture enemyRangerTexture2;
	sf::Texture enemyRangerTexture3;
	sf::Sprite enemyRangerSprite;
	bool enemyAlive = true;

	std::vector<int> m_pathFound;
	int targetCell;
	sf::Vector2f targetCellPos;
	bool enemyMoving = false;
	bool enemyNextPosFound = false;
	sf::Vector2f velocity;
	float speed = 5.0f;
	int enemyLives = 3;

	//Projectile
	bool m_projectileShot = false;
	int timer = 100;
	float m_projectileSpeed = 15.0f; //Speed of shot
	float m_distance; //Distance to travel

	sf::VertexArray m_projectileLine{ sf::Lines };
	sf::Vector2f enemyPosition;
	sf::Vector2f playerPosition;
	sf::Vector2f m_direction; //Direction to mouse from player
	sf::Vector2f m_unitVector;
	sf::Vector2f m_velocityVector;
	sf::Vector2f m_currentProjectileLocation;

	sf::Vector2f m_playerPositionOnShot;
	sf::Vector2f m_crosshairPositionOnShot;

	sf::Texture m_projectileTexture;
	sf::Sprite m_projectileSprite;


	bool loadSecondStageEnemyOnce = false;
	bool loadThirdStageEnemyOnce = false;
	void secondStageEnemy();
	void thirdStageEnemy();

	sf::IntRect rectSourceSprite;
	float totalElapsed = 0;
	int animationframe = 0;
	void anim();
	void shoot(Player t_player);
	void draw(sf::RenderWindow& m_window);
	void update();
};