#pragma once
#include "Player.h"

Player::Player()
{

	if (!m_playerTexture.loadFromFile("./Assets/player/Player.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!m_playerTexture2.loadFromFile("./Assets/player/Player-2.png"))
	{
		std::cout << "error with player texture file";
	}
	if (!m_playerTexture3.loadFromFile("./Assets/player/Player-3.png"))
	{
		std::cout << "error with player texture file";
	}

	if (!armsTexture.loadFromFile("./Assets/vacummer_arms.png"))
	{
		std::cout << "error with player hands texture file";
	}

	if (!m_crosshairTexture.loadFromFile("./Assets/crosshair.png"))
	{
		std::cout << "error with crosshair texture file";
	}

	if (!m_healthBorder.loadFromFile("./Assets/HUD/healthBorder.png"))
	{
		std::cout << "error with crosshair texture file";
	}



	armsSprite.setTexture(armsTexture);
	armsSprite.setOrigin(128, 128);
	armsSprite.setScale(0.7f, 0.7f);

	m_playerSprite.setTexture(m_playerTexture3);	
	m_playerSprite.setOrigin(128, 128);
	m_playerSprite.setPosition(500, 320);
	m_playerSprite.scale(0.7f, 0.7f);
	totalElapsed = 0;
	animationframe = 0;
	rectSourceSprite.height = 256;
	rectSourceSprite.width = 256;
	m_playerSprite.setTextureRect(rectSourceSprite);

	m_crosshairSprite.setTexture(m_crosshairTexture);
	m_crosshairSprite.setOrigin(258, 250);
	m_crosshairSprite.setPosition(m_playerSprite.getPosition().x , m_playerSprite.getPosition().y + 100);
	m_crosshairSprite.scale(0.3f, 0.3f);
	
	m_healthShape.setSize(sf::Vector2f(m_health, 50));
	m_healthShape.setOutlineColor(sf::Color::Black);
	m_healthShape.setFillColor(sf::Color::Green);
	m_healthShape.setOutlineThickness(2);

	m_healthBorderSprite.setTexture(m_healthBorder);

	allowWalkRight = false;
	allowWalkLeft = false;
	//velocity = 5;

}


Player::~Player()
{
}

void Player::draw(sf::RenderWindow& m_window)
{
	m_window.draw(m_playerSprite);
	m_window.draw(m_crosshairSprite, m_crosshairTransform);
	m_window.draw(armsSprite);
	m_window.draw(m_healthShape);
	m_window.draw(m_healthBorderSprite);
	
}

void Player::update(sf::RenderWindow& t_window, float delta)
{
	m_healthShape.setPosition(armsSprite.getPosition().x - 700, armsSprite.getPosition().y + 450);
	m_healthShape.setSize(sf::Vector2f(m_health, 50));
	m_healthBorderSprite.setPosition(m_healthShape.getPosition().x - 5, m_healthShape.getPosition().y -5);

	sf::Vector2f playerOrigin = m_playerSprite.getOrigin();
	sf::Vector2i mousePosition;
	mousePosition = sf::Mouse::getPosition(t_window);
	armsSprite.setPosition(m_playerSprite.getPosition());
	sf::Vector2f currentArmPos = armsSprite.getPosition();

	float dx = currentArmPos.x - m_crosshairSprite.getPosition().x;
	float dy = currentArmPos.y - m_crosshairSprite.getPosition().y;

	float rotationForArms = (atan2(dy, dx)) * 180 / PI ;

	armsSprite.setRotation(rotationForArms + 160);
	boundry();
	if (sf::Joystick::isConnected(0))
	{

		//Left Stick

		//Move Left
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20)
		{
			
			m_playerSprite.setScale(-0.7f, 0.7f);
			m_playerSprite.move(-velocity, 0);
			m_crosshairSprite.move(-velocity, 0);
			//m_crosshairTransform.translate(-velocity, 0);
			allowWalkLeft = true;
			allowWalkRight = false;
		}
		//Move Right
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20)
		{
			
			m_playerSprite.setScale(0.7f, 0.7f);
			m_playerSprite.move(velocity, 0);
			m_crosshairSprite.move(velocity, 0);
			//m_crosshairTransform.translate(velocity, 0);
			allowWalkLeft = false;
			allowWalkRight = true;
		}
		//Move Up
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20)
		{	
			m_playerSprite.move(0, -velocity);
			m_crosshairSprite.move(0, -velocity);
			//m_crosshairTransform.translate(0, -velocity);
		}
		//Move Down
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20)
		{
			m_playerSprite.move(0, velocity);
			m_crosshairSprite.move(0, velocity);
			//m_crosshairTransform.translate(0, velocity);
		}
	 
		//if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -20)
		//{
		//	std::cout <<"Trigger";
		//}
		//Right Stick

		//Rotate Left
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::U) < -20)
		{
			m_crosshairSprite.move(-velocity * 2, 0);
			//m_crosshairTransform.rotate(-2, m_playerSprite.getPosition());

		}
		//Rotate Right
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::U) > 20)
		{
			//Temp Move
			m_crosshairSprite.move(velocity * 2, 0);
			//m_crosshairTransform.rotate(2, m_playerSprite.getPosition());
		}
		//Move Up
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::V) < -20)
		{
			m_crosshairSprite.move(0, -velocity * 2);
		}
		//Move Down
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::V) > 20)
		{
			m_crosshairSprite.move(0, velocity * 2);
		}
	}
	else
	{
		//sf::Vector2f mouseFloat = { static_cast<float>(mousePosition.x),static_cast<float>(mousePosition.y) };
		sf::Vector2f mouseFloat = t_window.mapPixelToCoords(mousePosition);
		m_crosshairSprite.setPosition(mouseFloat);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			
			m_playerSprite.move(0, -velocity);
			allowWalkLeft = true;
			allowWalkRight = false;
			//m_miniPhoneSprite.move(0, velocity);
		//	m_phoneSprite.move(0, velocity);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			
			m_playerSprite.move(0, velocity);
			allowWalkLeft = false;
			allowWalkRight = true;
			//m_miniPhoneSprite.move(0, velocity);
			//m_phoneSprite.move(0, velocity);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_playerSprite.setScale(0.7f, 0.7f);
			m_playerSprite.move(velocity, 0);
			//m_miniPhoneSprite.move(velocity, 0);
			//m_phoneSprite.move(velocity, 0);
			allowWalkLeft = false;
			allowWalkRight = true;
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_playerSprite.setScale(-0.7f, 0.7f);
			m_playerSprite.move(-velocity, 0);
			//m_miniPhoneSprite.move(velocity, 0);
		//	m_phoneSprite.move(velocity, 0);
			allowWalkLeft = true;
			allowWalkRight = false;
		}
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))		//if key a is not pressed 
		{
			allowWalkRight = false;
			allowWalkLeft = false;
		}

	}

	if (allowWalkLeft == true)
	{
		state = PLAYER_WALKINGLEFT;	
	}
	 if (allowWalkRight == true)
	{
		state = PLAYER_WALKINGRIGHT;
	}
	 if (allowWalkRight == false && allowWalkLeft == false)
	 {
		 animIdle();
	 }

	if (state == PLAYER_WALKINGLEFT) {		//when moving left
		anim();
	}
	if (state == PLAYER_WALKINGRIGHT) {		//when moving right
		anim();
	}

	//if (allowWalkRight == false && allowWalkLeft == false)		//when not moving 
	//{
	//	animIdle();
	//}


	//crosshair.setPosition(m_playerSprite.getPosition().x, m_playerSprite.getPosition().y + 200);
}


void Player::anim()
{
	totalElapsed++;
	if (totalElapsed > 2)
	{
		totalElapsed = 0;
		animationframe++;
		if (animationframe > 10)
		{
			animationframe = 0;
		}
	}
	int col = animationframe % 10;
	int row = animationframe / 1;

	rectSourceSprite.height = 256;
	rectSourceSprite.width = 256;
	rectSourceSprite.left = col * rectSourceSprite.width;
	//rectSourceSprite.top = row * rectSourceSprite.height;
	m_playerSprite.setScale(m_playerSprite.getScale().x, m_playerSprite.getScale().y);
	m_playerSprite.setTextureRect(rectSourceSprite);

}


void Player::animIdle()
{
	totalElapsed++;
	if (totalElapsed > 1)
	{
		totalElapsed = 0;
		animationframe++;
		if (animationframe > 0)
		{
			animationframe = 0;
		}
	}
	int col = animationframe % 10;
	int row = animationframe / 1;

	rectSourceSprite.height = 256;
	rectSourceSprite.width = 256;
	rectSourceSprite.left = col * rectSourceSprite.width;
	//rectSourceSprite.top = row * rectSourceSprite.height;
	m_playerSprite.setScale(m_playerSprite.getScale().x, m_playerSprite.getScale().y);
	m_playerSprite.setTextureRect(rectSourceSprite);

}


void Player::boundry()
{
	sf::Vector2f playerPos = m_playerSprite.getPosition();
	if (playerPos.x < 5)			//left
	{
		m_playerSprite.setPosition(5.0f, playerPos.y);
	}

	if (playerPos.x > 5115.0f)		//right
	{
		m_playerSprite.setPosition(5115.0f, playerPos.y);
	}

	if (playerPos.y < 5)			//top
	{
		m_playerSprite.setPosition(playerPos.x, 5.0f);
	}
	if (playerPos.y > 5115.0f)			//top
	{
		m_playerSprite.setPosition(playerPos.x, 5115.0f);
	}
}

void Player::secondStagePlayer()
{

	m_playerSprite.setTexture(m_playerTexture2);
	loadSecondStagePlayerOnce = true;
}


void Player::thirdStagePlayer()
{
	m_playerSprite.setTexture(m_playerTexture);
	loadThirdStagePlayerOnce = true;
}
