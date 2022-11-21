#include "Settings.h"

Settings::Settings()
{
	soundOn = true;			//SETTING SOUND BOOL TO TRUE
}
Settings::~Settings()
{
}

void Settings::instantiate(sf::Font& m_font)
{
	audioText.setFont(m_font);				//HERE WE SET UP TEXTS FOR SETTINGS TAB 
	audioText.setString("Audio is : ");
	audioText.setPosition(40.0f,100.0f);
	audioText.setCharacterSize(50.0f);
//	audioText.setColor(sf::Color::White);
	onOffText.setFont(m_font);
//	onOffText.setColor(sf::Color::White);
	onOffText.setPosition(240.0f, 100.0f);
	onOffText.setCharacterSize(50.0f);
	onOffText.setString(" ON ");
	
}
void Settings::update()
{

}
void Settings::draw(sf::RenderWindow& m_window)
{									//DRAWING TEXTS FOR SETTINGS
	m_window.draw(audioText);
	m_window.draw(onOffText);

}	
//SOUND ON FUNC
void Settings::turnSoundOn()
{
	soundOn = true;						//BOOL SET TO TRUE
	onOffText.setString(" ON ");		//WHEN SOUND IS ON THE STRING WILL CHANGE TO ON
}
//SOUND OFF FUNC
void Settings::turnSoundOff()
{
	soundOn = false;					//BOOL SET TO FALSE
	onOffText.setString(" OFF ");		//WHEN SOUND IS OFF THE STRING WILL CHANGE TO OFF
}
