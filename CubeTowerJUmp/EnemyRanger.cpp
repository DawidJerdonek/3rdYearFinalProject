#include "EnemyRanger.h"

EnemyRanger::EnemyRanger()
{
	enemyRangerSprite.setPosition(1000, 1000);

	if (!enemyRangerTexture.loadFromFile("./Assets/enemy2/EnemyGun.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!enemyRangerTexture2.loadFromFile("./Assets/enemy2/EnemyGun-2.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!enemyRangerTexture3.loadFromFile("./Assets/enemy2/EnemyGun-3.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!m_projectileTexture.loadFromFile("Assets/enemy2/bullet.png"))
	{
		std::cout << "error with suck sound file";
	}
	m_projectileSprite.setTexture(m_projectileTexture);

	enemyRangerSprite.setOrigin(140.0f, 150.0f);
	enemyRangerSprite.setTexture(enemyRangerTexture3);
	enemyRangerSprite.setScale(0.6f, 0.6f);
}

EnemyRanger::~EnemyRanger()
{ 
}

void EnemyRanger::anim()
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
	enemyRangerSprite.setScale(enemyRangerSprite.getScale().x, enemyRangerSprite.getScale().y);
	enemyRangerSprite.setTextureRect(rectSourceSprite);
}

void EnemyRanger::shoot(Player t_player)
{
	//Shoot projectile
	if (m_projectileShot == false)
	{
		timer = 100;
		playerPosition = t_player.m_playerSprite.getPosition();
		enemyPosition = enemyRangerSprite.getPosition();
		//std::cout << m_mouseLocation.x << m_mouseLocation.y << std::endl;
		m_direction = playerPosition - enemyPosition; // setup a direction variable in which the projectile will travel

		m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
		m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
		m_direction = m_unitVector; //Set the direction properly

		m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
		m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
		m_direction = m_unitVector; //Set the direction properly

		m_velocityVector = m_direction * m_projectileSpeed;
		m_currentProjectileLocation = enemyPosition;
		m_projectileSprite.setPosition(enemyPosition);
		m_crosshairPositionOnShot = playerPosition;
		m_projectileShot = true;
	}

	if (m_projectileShot == true)
	{
		sf::Vector2f checkLength = m_currentProjectileLocation - m_crosshairPositionOnShot; //check length
		//std::cout << timer << std::endl;
		m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
		m_projectileLine.clear(); //Ensure the previous shot is cleared
		m_projectileSprite.setPosition(m_currentProjectileLocation);
		//Draw the line
		sf::Vertex begin{ enemyPosition,sf::Color::Transparent };
		m_projectileLine.append(begin);
		sf::Vertex end{ m_currentProjectileLocation, sf::Color::Red };
		m_projectileLine.append(end);
		timer--;

		//if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
		//{
		//	m_projectileLine.clear();
		//	m_projectileShot = false;
		//}

	}

	if (timer <= 0)
	{
		m_projectileLine.clear();
		m_projectileShot = false;
	}
}

void EnemyRanger::draw(sf::RenderWindow& m_window)
{
	m_window.draw(enemyRangerSprite);
	m_window.draw(m_projectileLine);
	if (m_projectileShot == true)
	{
		m_window.draw(m_projectileSprite);
	}
}

void EnemyRanger::update()
{
	anim();
	
}

void EnemyRanger::secondStageEnemy()
{
	enemyRangerSprite.setTexture(enemyRangerTexture2);
	loadSecondStageEnemyOnce = true;
}

void EnemyRanger::thirdStageEnemy()
{
	enemyRangerSprite.setTexture(enemyRangerTexture);
	loadThirdStageEnemyOnce = true;
}