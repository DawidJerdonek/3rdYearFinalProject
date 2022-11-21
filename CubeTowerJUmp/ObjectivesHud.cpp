#include "ObjectivesHud.h"

ObjectivesHud::ObjectivesHud()
{
	if (!m_phone.loadFromFile("./Assets/HUD/TaskListUpdate.jpg"))
	{
		std::cout << "error with phone texture file";
	}

	if (!genObjectivesTexture.loadFromFile("./Assets/tempGenerator.png"))
	{
		std::cout << "error with player texture file";
	}

	if (!m_font.loadFromFile("Assets/Fonts/Pixellari.ttf"))
	{
		std::cout << "error with font file file";
	}
	m_taskOneText.setFont(m_font);
	m_taskTwoText.setFont(m_font);
	m_taskThreeText.setFont(m_font);
	m_taskFourText.setFont(m_font);

	m_taskOneText.setString("0/2 Generators built");
	m_taskTwoText.setString("Incomplete");
	m_taskThreeText.setString("Incomplete");
	m_taskFourText.setString("Incomplete");

	m_taskOneText.setCharacterSize(20.0f);
	m_taskTwoText.setCharacterSize(20.0f);
	m_taskThreeText.setCharacterSize(20.0f);
	m_taskFourText.setCharacterSize(20.0f);

	m_taskOneText.setFillColor(sf::Color::Red);
	m_taskTwoText.setFillColor(sf::Color::Red);
	m_taskThreeText.setFillColor(sf::Color::Red);
	m_taskFourText.setFillColor(sf::Color::Red);

	m_taskOneText.setPosition(0,50);


	genObjectivesSprite1.setTexture(genObjectivesTexture);
	genObjectivesSprite1.setColor(sf::Color::Black);

	genObjectivesSprite2.setTexture(genObjectivesTexture);
	genObjectivesSprite2.setColor(sf::Color::Black);

	m_miniPhoneSprite.setTexture(m_phone);
	m_miniPhoneSprite.scale(0.1f, 0.1f);
	m_miniPhoneSprite.setPosition(-250, 10);
}

ObjectivesHud::~ObjectivesHud()
{
}

void ObjectivesHud::draw(sf::RenderWindow& m_window)
{
	if (m_viewObjectives == false){
		m_miniPhoneSprite.setScale(0.1f, 0.1f);
		genObjectivesSprite1.setScale(0.0f, 0.0f);
		genObjectivesSprite2.setScale(0.0f, 0.0f);
	}
	else
	{
		m_miniPhoneSprite.setScale(0.3f, 0.3f);

	}


	if (gen1ObjectiveDone == true) { genObjectivesSprite1.setColor(sf::Color::Cyan); }
	if (gen2ObjectiveDone == true) { genObjectivesSprite2.setColor(sf::Color::Red); }


	m_window.draw(m_miniPhoneSprite);
	m_window.draw(genObjectivesSprite1);
	m_window.draw(genObjectivesSprite2);
	m_window.draw(m_taskOneText);
	m_window.draw(m_taskTwoText);
	m_window.draw(m_taskThreeText);
	m_window.draw(m_taskFourText);

}

void ObjectivesHud::update(Player t_player)
{
	m_miniPhoneSprite.setPosition(t_player.getPlayerPosition().x - 700, t_player.getPlayerPosition().y - 300);

	if (m_viewObjectives == true) 
	{
		m_taskOneText.setPosition(t_player.getPlayerPosition().x - 555, t_player.getPlayerPosition().y - 105);
		m_taskTwoText.setPosition(t_player.getPlayerPosition().x - 555, t_player.getPlayerPosition().y + 15);
		m_taskThreeText.setPosition(t_player.getPlayerPosition().x - 555, t_player.getPlayerPosition().y + 135);
		m_taskFourText.setPosition(t_player.getPlayerPosition().x - 555, t_player.getPlayerPosition().y + 255);
	}
	else
	{
		m_taskOneText.setPosition(-999, -999);
		m_taskTwoText.setPosition(-999, -999);
		m_taskThreeText.setPosition(-999, -999);
		m_taskFourText.setPosition(-999, -999);
	}

	if (m_objectiveComplete1 == true)
	{
		m_taskOneText.setString("2/2 Generators Built");
		m_taskOneText.setFillColor(sf::Color::Green);
	}
	if (m_objectiveComplete2 == true)
	{
		m_taskTwoText.setFillColor(sf::Color::Green);
	}
	if (m_objectiveComplete3 == true)
	{
		m_taskThreeText.setFillColor(sf::Color::Green);
	}
	if (m_objectiveComplete4 == true)
	{
		m_taskFourText.setString("YOU WIN :D");
		m_taskFourText.setFillColor(sf::Color::Green);
	}
	genObjectivesSprite1.setPosition(t_player.getPlayerPosition().x - 700, t_player.getPlayerPosition().y - 300);
	genObjectivesSprite2.setPosition(t_player.getPlayerPosition().x - 600, t_player.getPlayerPosition().y - 300);

}
