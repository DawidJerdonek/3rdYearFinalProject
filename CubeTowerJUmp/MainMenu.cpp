#pragma once
#include "MainMenu.h"

/// Used to get a reference to the font and  
/// load texture and setup sprite and text
/// for each button and positions on screen
void MainMenu::initialise(sf::Font& font)
{
	m_topOffset = 100;
	m_verticalSpacing = 80;
	m_buttonWidth = 300;
	m_leftOffset = (300 - m_buttonWidth);
	m_buttonHeight = 70;
	int textDropOffset = 25;
	sf::String m_menuTexts[] = { "Play", "Controls", "Settings", "Exit" };

	if (sf::Joystick::isConnected(0))
	{
		m_menuTexts[0] = "Play  ( A )";
		m_menuTexts[1] = "Controls  ( X )";
		m_menuTexts[2] = "Settings  ( Y )";
		m_menuTexts[3] = "Exit  ( Back )";
	}
	m_font = font;
	/// display error if button.png doesnt load properly
	if (!m_buttonTexture.loadFromFile("ASSETS/MenuAssets/button.png"))
	{
		std::cout << "error with button file";
	}
	if (!m_buffer.loadFromFile("./Assets/Music.ogg"))
	{
		std::cout << "error loading music" << std::endl;
	}
	if (!m_backgroundTexture.loadFromFile("ASSETS/MenuAssets/vacBG.png"))
	{
		std::cout << "error with bg file";
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);

	m_sound.setBuffer(m_buffer);
	m_sound.setLoop(true);
	m_sound.play();
	m_sound.setVolume(20.0f);
	/// for loop to setup menu buttons in an array
	/// keeps them in a centre nicely laid out
	/// scales them to texture size so they look to scale
	/// 
	/// 
	/// 
	m_title.setFont(m_font);
	m_title.setString(" Vacuum Master 9000");
	m_title.setCharacterSize(50.0f);
	m_title.setFillColor(sf::Color::White);
	
	playerSprite.m_playerSprite.setPosition(1000.0f, 250.0f);
	playerSprite.m_playerSprite.setScale(1.0f, 1.0f);
	playerSprite.armsSprite.setScale(1.0f, 1.0f);
	playerSprite.m_playerSprite.setTexture(playerSprite.m_playerTexture);
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftOffset, m_verticalSpacing * i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		// sets font up for the array of text shapes that display over the buttons
		m_buttonTexts[i].setFont(m_font);
		m_buttonTexts[i].setString(m_menuTexts[i]);
		m_buttonTexts[i].setFillColor(sf::Color::White);
		m_buttonTexts[i].setCharacterSize(20);
		sf::FloatRect textSize = m_buttonTexts[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonTexts[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing * i + m_topOffset + textDropOffset);
	}
}


/// check current position of the mouse for intersection with
/// location of buttons using locations and offsets rather than rectangles
/// for intersection (create said so 'imaginary' columns and rows, then mouse x/y 
/// values are compared to see if they are intersecting columns' then rows' x/y values

void MainMenu::update(sf::Window& window, int& t_gameMode)
{
	m_title.setPosition(660.0f, 10.0f);
	playerSprite.armsSprite.setPosition(playerSprite.m_playerSprite.getPosition());

	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, 0)) //A
		{
			t_gameMode = PLAY;	//New Game
		}
		if (sf::Joystick::isButtonPressed(0, 2)) //X
		{
			t_gameMode = CONTROLS;	//Controls
		}
		if (sf::Joystick::isButtonPressed(0, 3)) //Y
		{
			t_gameMode = SETTINGS;	//Settings
		}
		if (sf::Joystick::isButtonPressed(0, 6)) //Back
		{
			window.close(); //Exit
		}
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y && mouseLocation.y < m_topOffset + m_buttonHeight)
			{
				t_gameMode = PLAY;	//new game
				
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				t_gameMode = CONTROLS;	//controls
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeight)
			{
				t_gameMode = SETTINGS; //Settings
			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 3 && mouseLocation.y < m_topOffset + m_verticalSpacing * 3 + m_buttonHeight)
			{
				window.close();		//exit
			}
	

		}
	}
}


///  draw menu text over buttons

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite);
	for (int i = 0; i < m_optionCount; i++)
	{		
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonTexts[i]);
	}
	window.draw(m_title);
	window.draw(playerSprite.m_playerSprite);
	window.draw(playerSprite.armsSprite);
}