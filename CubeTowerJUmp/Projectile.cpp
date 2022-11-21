#pragma once
#include "Projectile.h"

Projectile::Projectile()
{
	if (!m_font.loadFromFile("Assets/Fonts/Pixellari.ttf"))
	{
		std::cout << "error with font file file";
	}
	m_ammoText.setFont(m_font);
	m_ammoText.setCharacterSize(50);
	m_ammoText.setFillColor(sf::Color::Black);
	m_ammoText.setString(std::to_string(m_ammo));  //passing custom font for the menu buttons
	m_ammoText.setPosition(600,600);

	m_ammoSquare.setSize(sf::Vector2f(50, 50));
	m_ammoSquare.setOutlineColor(sf::Color::Green);
	m_ammoSquare.setFillColor(sf::Color::Cyan);
	m_ammoSquare.setOutlineThickness(1);
	m_ammoSquare.setPosition(400, 400);
	if (!suckBuffer.loadFromFile("Assets/Audio/suckSound.OGG"))
	{
		std::cout << "error with suck sound file";
	}
	suckSound.setBuffer(suckBuffer);

	if (!m_projectileTexture.loadFromFile("Assets/bullet.png"))
	{
		std::cout << "error with suck sound file";
	}
	m_projectileSprite.setTexture(m_projectileTexture);
}

Projectile::~Projectile()
{
}
int timer = 100;
void Projectile::shoot(double dt, Player t_player, sf::RenderWindow& t_window)
{
	sf::Vector2i mousePosition;
	mousePosition = sf::Mouse::getPosition(t_window); //Get mouse position

	playerPosition = t_player.armsSprite.getPosition();
	crosshairPosition = t_player.m_crosshairSprite.getPosition();

	

	if (sf::Joystick::isConnected(0))
	{

		//Shoot
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -20 && m_projectileShot == false && m_rubbishSucked == false && m_ammo > 0)
		{

			m_direction = crosshairPosition - playerPosition; // setup a direction variable in which the projectile will travel

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_velocityVector = m_direction * m_speed;
			m_currentProjectileLocation = playerPosition;

			m_crosshairPositionOnShot = crosshairPosition;
			m_projectileShot = true;
			m_ammo--;
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -20 && m_ammo <= 0)
		{
			std::cout << "No ammo!";
		}

		//Suck Rubbish
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > 20 && m_rubbishSucked == false && m_projectileShot == false)
		{

			m_direction = playerPosition - crosshairPosition; // setup a direction variable in which the projectile will travel

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_velocityVector = m_direction * m_suckSpeed;
			m_currentProjectileLocation = crosshairPosition;

			m_playerPositionOnShot = playerPosition;
			m_rubbishSucked = true;

		}

		if (m_projectileShot == true)
		{
			sf::Vector2f checkLength = m_currentProjectileLocation - m_crosshairPositionOnShot; //check length

			m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
			m_projectileLine.clear(); //Ensure the previous shot is cleared

			//Draw the line
			sf::Vertex begin{ playerPosition,sf::Color::Transparent };
			m_projectileLine.append(begin);
			sf::Vertex end{ m_currentProjectileLocation, sf::Color::Red };
			m_projectileLine.append(end);

			if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
			{
				m_projectileLine.clear();
				m_projectileShot = false;
			}
		}
		else if (m_rubbishSucked == true)
		{

			sf::Vector2f checkLength = m_currentProjectileLocation - m_playerPositionOnShot; //check length

			m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
			m_rubbishLine.clear(); //Ensure the previous shot is cleared

			//Draw the line
			sf::Vertex begin{ crosshairPosition,sf::Color::Transparent };
			m_rubbishLine.append(begin);
			sf::Vertex end{ m_currentProjectileLocation, sf::Color::Green };
			m_rubbishLine.append(end);


			if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
			{
				m_rubbishLine.clear();
				m_rubbishSucked = false;
			}
		}
	}
	else
	{
		//Shoot Projectile
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_projectileShot == false && m_rubbishSucked == false && m_ammo > 0)
		{	
			timer = 100;
			m_mouseLocation = t_window.mapPixelToCoords(mousePosition);
			//std::cout << m_mouseLocation.x << m_mouseLocation.y << std::endl;
			m_direction = m_mouseLocation - playerPosition; // setup a direction variable in which the projectile will travel

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_velocityVector = m_direction * m_speed;
			m_currentProjectileLocation = playerPosition;
			m_projectileSprite.setPosition(playerPosition);
			m_crosshairPositionOnShot = crosshairPosition;
			m_projectileShot = true;
			m_ammo--;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_ammo <= 0)
		{
			std::cout << "No ammo!";
		}

		//Suck Rubbish
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && m_rubbishSucked == false && m_projectileShot == false)
		{
			m_mouseLocation = t_window.mapPixelToCoords(mousePosition);
			//std::cout << m_mouseLocation.x << m_mouseLocation.y << std::endl;
			m_direction = playerPosition - m_mouseLocation; // setup a direction variable in which the projectile will travel
			m_projectileSprite.setPosition(playerPosition);
			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
			m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
			m_direction = m_unitVector; //Set the direction properly

			m_velocityVector = m_direction * m_suckSpeed;
			m_currentProjectileLocation = m_mouseLocation;
			m_playerPositionOnShot = playerPosition;

			m_rubbishSucked = true;
			suckSound.play();
		}

		if (m_projectileShot == true)
		{
			sf::Vector2f checkLength = m_currentProjectileLocation - m_crosshairPositionOnShot; //check length
			//std::cout << timer << std::endl;
			m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
			m_projectileLine.clear(); //Ensure the previous shot is cleared
			m_projectileSprite.setPosition(m_currentProjectileLocation);
			//Draw the line
			sf::Vertex begin{ playerPosition,sf::Color::Transparent };
			m_projectileLine.append(begin);
			sf::Vertex end{ m_currentProjectileLocation, sf::Color::Cyan };
			m_projectileLine.append(end);
			timer--;

			if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
			{
				m_projectileLine.clear();
				m_projectileShot = false;
			}

		}
		else if (m_rubbishSucked == true)
		{

			sf::Vector2f checkLength = m_currentProjectileLocation - m_playerPositionOnShot; //check length

			m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
			m_rubbishLine.clear(); //Ensure the previous shot is cleared

			//Draw the line
			sf::Vertex begin{ m_mouseLocation,sf::Color::Transparent };
			m_rubbishLine.append(begin);
			sf::Vertex end{ m_currentProjectileLocation, sf::Color::Green };
			m_rubbishLine.append(end);

			if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
			{
				m_rubbishLine.clear();
				m_rubbishSucked = false;
			}

		}
	}

	if (timer <= 0)
	{
		m_projectileLine.clear();
		m_rubbishLine.clear();
		m_projectileShot = false;
		m_rubbishSucked = false;
	}
}

void Projectile::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_projectileLine);
	t_window.draw(m_rubbishLine);
	t_window.draw(m_ammoSquare);
	t_window.draw(m_ammoText);
	if (m_projectileShot == true)
	{
		t_window.draw(m_projectileSprite);
	}
	//if (m_projectileShot == true)
	//{
	//	t_window.draw(m_projectileSprite);
	//}


}
