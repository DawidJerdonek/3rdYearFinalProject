#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class enemy
{
public:
	enemy();
	~enemy();

	sf::Texture enemyTexture;
	sf::Texture enemyTexture2;
	sf::Texture enemyTexture3;
	sf::Sprite enemySprite;
	bool enemyAlive = true;

	std::vector<int> m_pathFound;
	int targetCell;
	sf::Vector2f targetCellPos;
	bool enemyMoving = false;
	bool enemyNextPosFound = false;
	sf::Vector2f velocity;
	float speed = 5.0f;
	int enemyLives = 3;


	bool loadSecondStageEnemyOnce = false;
	bool loadThirdStageEnemyOnce = false;
	void secondStageEnemy();
	void thirdStageEnemy();


	sf::IntRect rectSourceSprite;
	float totalElapsed = 0;
	int animationframe = 0;
	void anim();
	void draw(sf::RenderWindow& m_window);
	void update();

private:
	enemy(enemy&)
	{};
};