#include "Projectile.h"

Projectile::Projectile()
{

}

Projectile::~Projectile()
{
}

void Projectile::update(double dt, Player t_player, sf::Window& t_window)
{
	shoot(dt, t_player, t_window);
}

void Projectile::shoot(double dt, Player t_player, sf::Window& t_window)
{
	sf::Vector2i mousePosition;
	mousePosition = sf::Mouse::getPosition(t_window); //Get mouse position

	playerPosition = t_player.getPlayerPosition();
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_projectileShot == false)
	{
		m_mouseLocation = { static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y) };
		std::cout << m_mouseLocation.x << m_mouseLocation.x << std::endl;
		m_direction = m_mouseLocation - playerPosition; // setup a direction variable in which the projectile will travel

		m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
		m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
		m_direction = m_unitVector; //Set the direction properly

		m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
		m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
		m_direction = m_unitVector; //Set the direction properly

		m_velocityVector = m_direction * m_speed;
		m_currentProjectileLocation = playerPosition;

		m_projectileShot = true;

	}

	if (m_projectileShot == true)
	{
		m_currentProjectileLocation += m_velocityVector; //Add velocity to the current position of projectile tip
		m_projectileLine.clear(); //Ensure the previous shot is cleared

		//Draw the line
		sf::Vertex begin{ playerPosition,sf::Color::Transparent };
		m_projectileLine.append(begin);
		sf::Vertex end{ m_currentProjectileLocation, sf::Color::Green };
		m_projectileLine.append(end);

		sf::Vector2f checkLength = m_currentProjectileLocation - m_mouseLocation; //check lenght

		if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
		{
			m_projectileLine.clear();
			m_projectileShot = false;
		}
	}
}

void Projectile::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_projectileLine);
}
