#pragma once
#include "Enemy.h"
enemy::enemy()
{

	enemySprite.setPosition(1000, 400);

	if (!enemyTexture.loadFromFile("./Assets/enemy1/EnemyKnife.png"))
	{
		std::cout << "error with enemy1 texture file";
	}
	if (!enemyTexture2.loadFromFile("./Assets/enemy1/EnemyKnife-2.png"))
	{
		std::cout << "error with enemy1 texture file";
	}
	if (!enemyTexture3.loadFromFile("./Assets/enemy1/EnemyKnife-3.png"))
	{
		std::cout << "error with enemy1 texture file";
	}
	enemySprite.setOrigin(140.0f, 150.0f);
	enemySprite.setTexture(enemyTexture3);
	enemySprite.setScale(0.6f, 0.6f);
}



enemy::~enemy()
{
}

void enemy::secondStageEnemy()
{
	enemySprite.setTexture(enemyTexture2);
	loadSecondStageEnemyOnce = true;
}

void enemy::thirdStageEnemy()
{
	enemySprite.setTexture(enemyTexture);
	loadThirdStageEnemyOnce = true;
}

void enemy::anim()
{
	
		totalElapsed++;
		if (totalElapsed > 3)
		{
			totalElapsed = 0;
			animationframe++;
			if (animationframe > 9)
			{
				animationframe = 0;
			}
		}
		int col = animationframe % 9;
		int row = animationframe / 1;

		rectSourceSprite.height = 300;
		rectSourceSprite.width = 280;
		rectSourceSprite.left = col * rectSourceSprite.width;
		//rectSourceSprite.top = row * rectSourceSprite.height;
		enemySprite.setScale(enemySprite.getScale().x, enemySprite.getScale().y);
		enemySprite.setTextureRect(rectSourceSprite);
	
}


void enemy::draw(sf::RenderWindow& m_window)
{
	auto position = enemySprite.getPosition();
	m_window.draw(enemySprite);
}

void enemy::update()
{
	anim();
}


