#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"
#include "Player.h"

class MainMenu
{
	/// Number of buttons on our menu
	static const int m_optionCount = 4;
	/// green button background
	sf::Texture m_buttonTexture;
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[m_optionCount];
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// array of text objects for text on buttons
	sf::Text m_buttonTexts[m_optionCount];

	sf::Text m_title;
	/// top left of area used for menu
	float m_topOffset;
	/// top left of area used for menu
	float m_leftOffset;
	/// gap in pixels between tops of buttons
	float m_verticalSpacing;
	/// width in pixels of all buttons
	float m_buttonWidth;
	/// height of button in pixels must be less than vertical spacing
	float m_buttonHeight;


	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;

public:
	Player playerSprite;
	sf::Vector2f getPosPlayer() { return playerSprite.m_playerSprite.getPosition(); };
	void initialise(sf::Font&);
	void draw(sf::RenderWindow&);
	void update(sf::Window&, int& t_gameMode);
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;

};
