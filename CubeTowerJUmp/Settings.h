#pragma once
#include <SFML/Graphics.hpp>
class Settings
{
public:
	Settings();		//CONSTRUCTOR
	~Settings();	//DECONSTRUCTOR
	sf::Text audioText;		//TEXT
	sf::Text onOffText;		//TEXT
	bool soundOn = true;	//BOOL
	void draw(sf::RenderWindow& m_window);	//DRAW FUNC
	void instantiate(sf::Font &m_font);		//INIT FUNC WITH PASSED FONT FROM THE GAME
	void update();							//UPDATE FUNC
	void turnSoundOn();						//SOUND ON FUNC
	void turnSoundOff();					//SOUND OFF FUNC
};

