#pragma once
#include "Game.h"
using namespace std;

static const float VIEW_HEIGHT = 900.0f;		//size of window
static const float VIEW_WIDTH = 1200.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view, float &t_trueHeight, float &t_trueWidth, sf::View & extraGameView)
{
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
	t_trueHeight = (VIEW_HEIGHT);
	t_trueWidth = (VIEW_HEIGHT * aspectRatio);
	
	extraGameView.setSize(t_trueWidth, t_trueHeight);
	extraGameView.setCenter(t_trueWidth /2, t_trueHeight /2);
};

Game::Game() : 
	m_Window(sf::VideoMode(static_cast<int>(VIEW_WIDTH), static_cast<int>(VIEW_HEIGHT)), "Vacuume", sf::Style::Fullscreen)
	, m_grid(m_enemy, m_enemyRanger, myPlayer)
{
	srand(time(NULL));
	gameMode = 1;		//setting gamemode to the menu 			<---------
	m_Window.setKeyRepeatEnabled(false);
	m_Window.setVerticalSyncEnabled(true);



	if (!sideGameTexture.loadFromFile("Assets/sideGame.png"))
	{
		std::cout << "error with side game file";
	}
	sideGameSprite.setTexture(sideGameTexture);
	sideGameSprite.setPosition(4100.0f, 200.0f);
	if (!m_PixellariFont.loadFromFile("Assets/Fonts/Pixellari.ttf"))
	{
		std::cout << "error with font file file";
	}
	m_mainMenu.initialise(m_PixellariFont);		//passing custom font for the menu buttons			<---------
	m_settings.instantiate(m_PixellariFont);	//passing custom font for the settings text			<---------
	if (sf::Joystick::isConnected(0))
	{
		if (!m_controlsTexture.loadFromFile("Assets/MenuAssets/Controls.png"))
		{
			std::cout << "error with font file file";
		}
		m_controlsSprite.setTexture(m_controlsTexture);
		m_controlsSprite.setOrigin(600, 0);
		m_controlsSprite.setScale(1.5, 1.1);
		m_controlsSprite.setPosition(1980.0f / 2.0f, 0);
	}
	else
	{
		if (!m_controlsTexture.loadFromFile("Assets/MenuAssets/ControlsKey.png"))
		{
			std::cout << "error with font file file";
		}
		m_controlsSprite.setTexture(m_controlsTexture);
		m_controlsSprite.setOrigin(600, 0);
		m_controlsSprite.setScale(1.5, 1.5);
		m_controlsSprite.setPosition(1980.0f / 2.0f, 200);
	}




	returnText.setFont(m_PixellariFont);
	if (sf::Joystick::isConnected(0))
	{
		returnText.setString("Press B on the Conroller to Return");
	}
	else
	{
		returnText.setString("Press ESCAPE on the Keyboard to Return");
	}
	returnText.setCharacterSize(50);
	returnText.setFillColor(sf::Color::Magenta);
	//Centre Text
	sf::FloatRect textRect = returnText.getLocalBounds();
	returnText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	returnText.setPosition(sf::Vector2f(1980.0f / 2.0f, 1000.0f));

	settingsText.setFont(m_PixellariFont);
	settingsText.setCharacterSize(50.0f);
	settingsText.setFillColor(sf::Color::White);
	settingsText.setString("Press P to Turn Music Off \nPress O to Turn Music On");
	if (sf::Joystick::isConnected(0))
	{
		settingsText.setString("Press X to Turn Music Off \nPress Y to Turn Music On");
	}

	sf::FloatRect setTextRect = settingsText.getLocalBounds();
	settingsText.setOrigin(setTextRect.left + setTextRect.width / 2.0f, setTextRect.top + setTextRect.height / 2.0f);
	settingsText.setPosition(sf::Vector2f(1980 / 2.0f, 550));


	pauseText.setFont(m_PixellariFont);
	pauseText.setCharacterSize(50.0f);
	pauseText.setFillColor(sf::Color::White);
	
	pauseScreen.setFillColor(sf::Color::Color(0, 0, 0, 180.0f));
	pauseScreen.setSize(sf::Vector2f(10000.0f, 10000.0f));
	pauseScreen.setOrigin(1024.0f, 1024.0f);

	lossText.setFont(m_PixellariFont);
	lossText.setCharacterSize(50.0f);
	lossText.setFillColor(sf::Color::White);

	
	tutorialText.setFont(m_PixellariFont);
	tutorialText.setCharacterSize(50.0f);
	tutorialText.setFillColor(sf::Color::White);
	
	physicsText.setFont(m_PixellariFont);
	physicsText.setCharacterSize(50.0f);
	physicsText.setFillColor(sf::Color::White);


	m_buildParts1[0].partSprite.setPosition(4600.0f, 230.0f);
	m_buildParts1[1].partSprite.setPosition(2700.0f, 1500.0f);
	m_buildParts1[2].partSprite.setPosition(220.0f, 4950.0f);

	m_buildParts2[0].partSprite.setPosition(1500.0f,4500.0f);
	m_buildParts2[1].partSprite.setPosition(2600.0f, 2700.0f);
	m_buildParts2[2].partSprite.setPosition(4980.0f, 4550.0f);


	m_rubbish[0].randomRubbish = rand() % 13 + 1;
	m_rubbish[0].m_rubbishSprite.setPosition(3000, 100);

	m_rubbish[1].randomRubbish = rand() % 13 + 1;
	m_rubbish[1].m_rubbishSprite.setPosition(80, 900);

	m_rubbish[2].randomRubbish = rand() % 13 + 1;
	m_rubbish[2].m_rubbishSprite.setPosition(300, 1700);

	m_rubbish[3].randomRubbish = rand() % 13 + 1;
	m_rubbish[3].m_rubbishSprite.setPosition(120, 2400);

	m_rubbish[4].randomRubbish = rand() % 13 + 1;
	m_rubbish[4].m_rubbishSprite.setPosition(400, 3200);



	m_rubbish[5].randomRubbish = rand() % 13 + 1;
	m_rubbish[5].m_rubbishSprite.setPosition(120, 4000);

	m_rubbish[6].randomRubbish = rand() % 13 + 1;
	m_rubbish[6].m_rubbishSprite.setPosition(600, 200);

	m_rubbish[7].randomRubbish = rand() % 13 + 1;
	m_rubbish[7].m_rubbishSprite.setPosition(1200, 450);

	m_rubbish[8].randomRubbish = rand() % 13 + 1;
	m_rubbish[8].m_rubbishSprite.setPosition(1600, 50);

	m_rubbish[9].randomRubbish = rand() % 13 + 1;
	m_rubbish[9].m_rubbishSprite.setPosition(2300, 200);



	m_rubbish[10].randomRubbish = rand() % 13 + 1;
	m_rubbish[10].m_rubbishSprite.setPosition(3600, 500);

	m_rubbish[11].randomRubbish = rand() % 13 + 1;
	m_rubbish[11].m_rubbishSprite.setPosition(3500, 1200);

	m_rubbish[12].randomRubbish = rand() % 13 + 1;
	m_rubbish[12].m_rubbishSprite.setPosition(3250, 2200);

	m_rubbish[13].randomRubbish = rand() % 13 + 1;
	m_rubbish[13].m_rubbishSprite.setPosition(3000, 3000);

	m_rubbish[14].randomRubbish = rand() % 13 + 1;
	m_rubbish[14].m_rubbishSprite.setPosition(2600, 3500);

	m_rubbish[15].randomRubbish = rand() % 13 + 1;
	m_rubbish[15].m_rubbishSprite.setPosition(980, 2900);

	m_rubbish[16].randomRubbish = rand() % 13 + 1;
	m_rubbish[16].m_rubbishSprite.setPosition(1180, 2780);

	m_rubbish[17].randomRubbish = rand() % 13 + 1;
	m_rubbish[17].m_rubbishSprite.setPosition(1580, 2900);

	m_rubbish[18].randomRubbish = rand() % 13 + 1;
	m_rubbish[18].m_rubbishSprite.setPosition(1680, 2780);

	m_rubbish[19].randomRubbish = rand() % 13 + 1;
	m_rubbish[19].m_rubbishSprite.setPosition(1880, 2900);

	m_rubbish[20].randomRubbish = rand() % 13 + 1;
	m_rubbish[20].m_rubbishSprite.setPosition(3300, 3000);

	m_rubbish[21].randomRubbish = rand() % 13 + 1;
	m_rubbish[21].m_rubbishSprite.setPosition(3100, 3300);

	m_rubbish[22].randomRubbish = rand() % 13 + 1;
	m_rubbish[22].m_rubbishSprite.setPosition(2800, 3600);

	m_rubbish[23].randomRubbish = rand() % 13 + 1;
	m_rubbish[23].m_rubbishSprite.setPosition(3300, 3800);

	m_rubbish[24].randomRubbish = rand() % 13 + 1;
	m_rubbish[24].m_rubbishSprite.setPosition(3200, 4100);

	m_rubbish[25].randomRubbish = rand() % 13 + 1;
	m_rubbish[25].m_rubbishSprite.setPosition(2800, 4500);

	m_rubbish[26].randomRubbish = rand() % 13 + 1;
	m_rubbish[26].m_rubbishSprite.setPosition(2400, 4600);

	m_rubbish[27].randomRubbish = rand() % 13 + 1;
	m_rubbish[27].m_rubbishSprite.setPosition(2300, 4800);

	m_rubbish[28].randomRubbish = rand() % 13 + 1;
	m_rubbish[28].m_rubbishSprite.setPosition(3700, 4100);

	m_rubbish[29].randomRubbish = rand() % 13 + 1;
	m_rubbish[29].m_rubbishSprite.setPosition(4300, 4300);

	m_rubbish[30].randomRubbish = rand() % 13 + 1;
	m_rubbish[30].m_rubbishSprite.setPosition(4500, 4300);


	rubbish.setRadius(10);
	rubbish.setPosition(160, 500);
	rubbish.setOrigin(sf::Vector2f(20, 20));
	rubbish.setFillColor(sf::Color::Magenta);
	sf::Vector2f normalised = thor::unitVector(rubbish.getPosition());
	float length = thor::length(gravity);
	float radians = thor::toDegree(10.0);
	thor::setLength(normalised, 100.0f);
	thor::rotate(normalised, 10.0f);
	
	bin.setSize(sf::Vector2f(100.0f, 50.0f));
	bin.setOutlineColor(sf::Color::Yellow);
	bin.setFillColor(sf::Color::Color(117,117,117));
	bin.setOutlineThickness(3);
	bin.setPosition(1300,400);


	checkCell();
}



void Game::run()
{
	srand(time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	float deltaTime;
	// the clock object keeps the time.
	sf::Clock clock;
	

	 
	deltaTime = clock.restart().asSeconds();
	

	while (m_Window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
			else
				(event.type == sf::Event::Resized);
			{
				ResizeView(m_Window, view, trueHeight, trueWidth, extraGameView);
			}

			
	
		}
		//get the time since last update and restart the clock 
		timeSinceLastUpdate += clock.restart();
		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			if (sf::Joystick::isConnected(0))
			{

				if (sf::Joystick::isButtonPressed(0, 7)) //Start
				{
					if (gameMode == PLAY)
					{
						paused = true;
					}
				}
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
				{
					if (gameMode == PLAY)
					{
						paused = true;
					}


				}
			}
			if (paused == true)
			{
				//std::cout << "game paused" << std::endl;
				pauseText.setString("Game Paused \n     Press Escape to Unpause");
				if (sf::Joystick::isConnected(0))
				{
					pauseText.setString("Game Paused \n     Press A to Unpause");
				}
				//pauseText.setString("Game Paused \n     Press Escape to Unpause \n     Press M to go to menu ");			<---------
				pauseText.setPosition(myPlayer.m_playerSprite.getPosition().x - 250.0f, myPlayer.m_playerSprite.getPosition().y);
			
				checkForUnpause();
			
			}
			else if (gameLost == true)
			{
				if (sf::Joystick::isConnected(0))
				{
					lossText.setString("YOU LOST :( \n Press Back to Quit");
					lossText.setPosition(myPlayer.m_playerSprite.getPosition().x - 250.0f, myPlayer.m_playerSprite.getPosition().y);
				}
				else
				{
					lossText.setString("YOU LOST :( \n Press Backspace to Quit");
					lossText.setPosition(myPlayer.m_playerSprite.getPosition().x - 250.0f, myPlayer.m_playerSprite.getPosition().y);
				}

				
			}
			else if (gamewon == true)
			{
				if (sf::Joystick::isConnected(0))
				{
					lossText.setString("YOU WON :) \n Press Back to Quit");
					lossText.setPosition(myPlayer.m_playerSprite.getPosition().x - 250.0f, myPlayer.m_playerSprite.getPosition().y);
				}
				else 
				{
					lossText.setString("YOU WON :) \n Press Backspace to Quit");
					lossText.setPosition(myPlayer.m_playerSprite.getPosition().x - 250.0f, myPlayer.m_playerSprite.getPosition().y);
				}
			}
			else {
				update(deltaTime);
				pauseText.setString("");
				myPlayer.update(m_Window, deltaTime);}
			draw();
			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;

			if (sf::Joystick::isConnected(0))
			{
				if (sf::Joystick::isButtonPressed(0, 6)) //Back
				{
					m_Window.close();
				}
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					m_Window.close();
				}
			}
		}
		
	}  // end while loop
}

void Game::update(float delta)
{
	if (gameMode == MENU)
	{
		
		m_mainMenu.update(m_Window, gameMode);
		
	}
	else if (gameMode == CONTROLS)
	{
		if (sf::Joystick::isConnected(0))
		{
			if (sf::Joystick::isButtonPressed(0, 1)) //B
			{
				gameMode = MENU;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameMode = MENU;
		}

	}
	else if (gameMode == SETTINGS)
	{
		if (sf::Joystick::isConnected(0))
		{
			if (sf::Joystick::isButtonPressed(0, 2)) //X
			{
				m_settings.turnSoundOff();
				m_mainMenu.m_sound.stop();
			}
			if (sf::Joystick::isButtonPressed(0, 3)) //Y
			{
				m_settings.turnSoundOn();
				m_mainMenu.m_sound.play();
			}
			if (sf::Joystick::isButtonPressed(0, 1)) //B
			{
				gameMode = MENU;
			}
		}
		else 
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))			//pause audio			<---------
			{
				m_settings.turnSoundOff();
				m_mainMenu.m_sound.stop();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))			//unpause the audio			<---------
			{	
				m_settings.turnSoundOn();
				m_mainMenu.m_sound.play();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameMode = MENU;
			
			}

		}
	}
	else if (gameMode == PLAY)
	{

		if (sidegameon == false)
		{
			//
			if (displayTut == true)
			{
				if (allowReset == true)
				{
					delta = tutClock.restart().asSeconds();
					allowReset = false;
				}
				tutorialText.setPosition(myPlayer.m_playerSprite.getPosition().x - 450.0f, myPlayer.m_playerSprite.getPosition().y-200.0f);
				tutElapsed = tutClock.getElapsedTime();

				tutorialText.setString("Use right click or left trigger to suck in rubbish and gain ammo");
				if (tutElapsed.asSeconds() >= 10.0f)
				{
					tutorialText.setString("Use left click or right trigger to shoot rubbish at thugs");
				}
				if (tutElapsed.asSeconds() >= 20.0f)
				{
					tutorialText.setString("Follow rubbish to find Generator parts \n Place them at Generators in top right of map ");
				}
				if (tutElapsed.asSeconds() >= 30.0f)
				{
					tutorialText.setString(" ");
					displayTut = false;
				}
			
			}

			if (myPlayer.m_playerSprite.getGlobalBounds().intersects(sideGameSprite.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				sidegameon = true;
			}
			//gameStage from gray to colour					<---------
			if (map.gameStage == 0)
			{
				map.mapSprite.setTexture(map.mapTexture3);
			}
			else if (map.gameStage == 1)
			{
				map.mapSprite.setTexture(map.mapTexture2);
			}
			else if (map.gameStage == 2)
			{
				map.mapSprite.setTexture(map.mapTexture);
			}

			//setting the allowence of the gamestage to change once 2 gens are complete			<---------
			if (m_buildable1.alive == true && m_buildable2.alive == true)
			{
				firstStageComplete = true;
				map.gameStage = 1;
				if (m_houses.loadSecondStageHousesOnce == false)			//setting second stage houses			<---------
				{
					m_houses.secondStageHouses();
				}
				if (m_factories.loadSecondStageFactoriesOnce == false)		//setting second stage factories			<---------
				{
					m_factories.secondStageFactories();
				}
				if (myPlayer.loadSecondStagePlayerOnce == false)			//setting second stage player			<---------
				{
					myPlayer.secondStagePlayer();
				}
				if (m_puddles.loadSecondStagePuddleOnce == false)			//setting second stage puddle			<---------
				{
					m_puddles.secondStagePuddle();
				}
				if (m_enemy.loadSecondStageEnemyOnce == false)				//setting second stage enemy			<---------
				{
					m_enemy.secondStageEnemy();
				}
				if (m_enemyRanger.loadSecondStageEnemyOnce == false)		//setting second stage enemy2			<---------
				{
					m_enemyRanger.secondStageEnemy();
				}
				if (m_buildable1.loadSecondStageOnce == false)				//setting second stage gen1			<---------
				{
					m_buildable1.secondStage();
				}
				if (m_buildable2.loadSecondStageOnce == false)				//setting second stage gen2			<---------
				{
					m_buildable2.secondStage();
				}
			}

			if (m_objHud.m_objectiveComplete1 == true && m_objHud.m_objectiveComplete2 == true)
			{

				map.gameStage = 2;
				if (m_houses.loadThirdStageHousesOnce == false)			//setting second stage houses			<---------
				{
					m_houses.thirdStageHouses();
				}
				if (m_factories.loadThirdStageFactoriesOnce == false)		//setting second stage factories			<---------
				{
					m_factories.thirdStageFactories();
				}
				if (myPlayer.loadThirdStagePlayerOnce == false)			//setting second stage player			<---------
				{
					myPlayer.thirdStagePlayer();
				}
				if (m_puddles.loadThirdStagePuddleOnce == false)			//setting second stage puddle			<---------
				{
					m_puddles.thirdStagePuddle();
				}
				if (m_enemy.loadThirdStageEnemyOnce == false)				//setting second stage enemy			<---------
				{
					m_enemy.thirdStageEnemy();
				}
				if (m_enemyRanger.loadThirdStageEnemyOnce == false)		//setting second stage enemy2			<---------
				{
					m_enemyRanger.thirdStageEnemy();
				}
				if (m_buildable1.loadThirdStageOnce == false)				//setting second stage gen1			<---------
				{
					m_buildable1.thirdStage();
				}
				if (m_buildable2.loadThirdStageOnce == false)				//setting second stage gen2			<---------
				{
					m_buildable2.thirdStage();
				}

				gamewon = true;
			}



			m_mainMenu.m_sound.stop();
			pauseText.setFont(m_PixellariFont);
			pauseText.setCharacterSize(50.0f);
			pauseText.setFillColor(sf::Color::White);
			pauseText.setPosition(m_Window.getPosition().x / 2, 200.0f);

			if (sf::Joystick::isConnected(0))
			{
				//ALL Collisions for houses
				for (int index = 0; index < 10; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_houses.m_houseSprites[index].getPosition().x)
					{
						//std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;


						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) //Right
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_houses.m_houseSprites[index].getPosition().x + 290)
					{
						myPlayer.velocity = 0;
						left = true;

						//std::cout << " right collision" << std::endl;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) //Left
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_houses.m_houseSprites[index].getPosition().y)
					{
						//std::cout << " top collision" << std::endl;
						down = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) // Down
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_houses.m_houseSprites[index].getPosition().y + 300)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) // Up
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}

				//ALL Collisions for factories
				for (int index = 0; index < 9; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_factories.m_factorySprites[index].getPosition().x)
					{
						//std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;

						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) //Right
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}

					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_factories.m_factorySprites[index].getPosition().x + 290)
					{
						myPlayer.velocity = 0;
						left = true;

						//std::cout << " right collision" << std::endl;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) //Left
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_factories.m_factorySprites[index].getPosition().y)
					{
						//std::cout << " top collision" << std::endl;
						down = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) // Down
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom of sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_factories.m_factorySprites[index].getPosition().y + 300)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) // Up
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}

				//ALL Collisions for Walls
				for (int index = 0; index < 20; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_walls.m_wallSprites[index].getPosition().x)
					{
						//std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;


						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) //Right
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_walls.m_wallSprites[index].getPosition().x + 118)
					{
						myPlayer.velocity = 0;
						left = true;

						//std::cout << " right collision" << std::endl;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) //Left
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_walls.m_wallSprites[index].getPosition().y)
					{
						//std::cout << " top collision" << std::endl;
						down = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) // Down
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_walls.m_wallSprites[index].getPosition().y + 128)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20))
						{

							if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) // Up
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}
				for (int index = 20; index < 24; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_walls.m_wallSprites[index].getPosition().x)
					{
						myPlayer.velocity = 0;
						right = true;


						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) //Right
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_walls.m_wallSprites[index].getPosition().x + 64)
					{
						myPlayer.velocity = 0;
						left = true;

						if ((sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -20) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 20))
						{
							if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -20) //Left
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}
				
			}
			else
			{
				//ALL Collisions for houses
				for (int index = 0; index < 10; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_houses.m_houseSprites[index].getPosition().x)
					{
						myPlayer.velocity = 0;
						right = true;


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_houses.m_houseSprites[index].getPosition().x + 290)
					{
						myPlayer.velocity = 0;
						left = true;

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_houses.m_houseSprites[index].getPosition().y)
					{
						down = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_houses.m_houseSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_houses.m_houseSprites[index].getPosition().y + 300)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}

				//ALL Collisions for factories
				for (int index = 0; index < 9; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_factories.m_factorySprites[index].getPosition().x)
					{
						//std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_factories.m_factorySprites[index].getPosition().x + 290)
					{
						myPlayer.velocity = 0;
						left = true;

						//std::cout << " right collision" << std::endl;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_factories.m_factorySprites[index].getPosition().y)
					{
						//std::cout << " top collision" << std::endl;
						down = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom of sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_factories.m_factorySprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_factories.m_factorySprites[index].getPosition().y + 300)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}

				//ALL Collisions for Walls
				for (int index = 0; index < 20; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_walls.m_wallSprites[index].getPosition().x)
					{
						//std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_walls.m_wallSprites[index].getPosition().x + 118)
					{
						myPlayer.velocity = 0;
						left = true;

						//std::cout << " right collision" << std::endl;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}
					//top of sprite																						
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y < m_walls.m_wallSprites[index].getPosition().y)
					{
						//std::cout << " top collision" << std::endl;
						down = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								down = true;
							}
							else
							{
								myPlayer.velocity = 5;
								down = false;
							}
						}


					}
					//bottom sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().y > m_walls.m_wallSprites[index].getPosition().y + 64)
					{
						//std::cout << " bottom collision" << std::endl;
						up = true;
						myPlayer.velocity = 0;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
							{
								up = true;
							}
							else
							{
								myPlayer.velocity = 5;
								up = false;
							}
						}
					}
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}
				for (int index = 20; index < 24; index++)
				{
					//left sprite																				
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x < m_walls.m_wallSprites[index].getPosition().x)
					{
						std::cout << " left collision" << std::endl;
						myPlayer.velocity = 0;
						right = true;


						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
							{
								right = true;
							}
							else
							{
								myPlayer.velocity = 5;
								right = false;
							}
						}

					}
					//right sprite																			
					if (myPlayer.m_playerSprite.getGlobalBounds().intersects(m_walls.m_wallSprites[index].getGlobalBounds())
						&& myPlayer.m_playerSprite.getPosition().x > m_walls.m_wallSprites[index].getPosition().x + 64)
					{
						myPlayer.velocity = 0;
						left = true;

						std::cout << " right collision" << std::endl;
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
							{
								left = true;
							}
							else
							{
								myPlayer.velocity = 5;
								left = false;
							}
						}

					}																				
					else if (up == false && down == false && left == false && right == false) {
						myPlayer.velocity = 5;
					}
				}
			}


			//Enemy shoots player depending on distance from player
			sf::Vector2f checkLength = m_enemyRanger.enemyRangerSprite.getPosition() - myPlayer.m_playerSprite.getPosition(); //check length
			if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 700.0f) //get length between two points
			{
				elapsed = clock.getElapsedTime();
				if (elapsed.asSeconds() >= 1.0f)
				{
					//Shoot Projectile
					m_enemyRanger.shoot(myPlayer);
				}


				if (elapsed.asSeconds() >= 2.0f)
				{
					clock.restart();
					m_enemyRanger.m_projectileLine.clear();
					m_enemyRanger.m_projectileShot = false;
					m_enemyRanger.m_projectileSprite.setPosition(m_enemyRanger.enemyRangerSprite.getPosition());
				}

			}
			else
			{
				m_enemyRanger.m_projectileLine.clear();
				m_enemyRanger.m_projectileShot = false;
				m_enemyRanger.m_projectileSprite.setPosition(m_enemyRanger.enemyRangerSprite.getPosition());
			}

			if (sf::Joystick::isConnected(0))
			{

				if (sf::Joystick::isButtonPressed(0, 3)) //Y
				{
					m_objHud.m_viewObjectives = true;
				}
				else if (gamewon == true)
				{
					m_objHud.m_viewObjectives = true;
				}
				else
				{
					m_objHud.m_viewObjectives = false;
				}
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
				{

					m_objHud.m_viewObjectives = true;


				}
				else if (gamewon == true)
				{
					m_objHud.m_viewObjectives = true;
				}
				else
				{
					m_objHud.m_viewObjectives = false;
				}
			}
			myProjectile.update(1, myPlayer, m_Window);
			m_grid.update(myPlayer);

			/////////view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
			view.setCenter(sf::Vector2f(myPlayer.getPlayerPosition().x + myPlayer.m_playerSprite.getLocalBounds().width
				* myPlayer.m_playerSprite.getScale().x / 100.0f,
				myPlayer.getPlayerPosition().y + myPlayer.m_playerSprite.getLocalBounds().height * myPlayer.m_playerSprite.getScale().y / 2.0f));

			m_enemy.update();
			m_enemyRanger.update();
			m_buildable1.update();
			m_buildable2.update();

			m_objHud.update(myPlayer);
			m_particleSystem.Update();
			for (int i = 0; i < 31; i++)
			{
				m_rubbish[i].update();
			}

			//Player moving through puddles
			if (Collision::PixelPerfectTest(myPlayer.m_playerSprite, m_puddles.m_puddleSprites[0]))
			{
				//std::cout << "collisions" << std::endl;
				myPlayer.velocity = 3;
			}
			else if (Collision::PixelPerfectTest(myPlayer.m_playerSprite, m_puddles.m_puddleSprites[1]))
			{
				//std::cout << "collisions" << std::endl;
				myPlayer.velocity = 3;
			}
			//else{myPlayer.velocity = 5;}

			//Enemy moving through puddles
			if (Collision::PixelPerfectTest(m_enemy.enemySprite, m_puddles.m_puddleSprites[0]))
			{
				//std::cout << "collisions" << std::endl;
				m_enemy.speed = 3;
			}
			else if (Collision::PixelPerfectTest(m_enemy.enemySprite, m_puddles.m_puddleSprites[1]))
			{
				//std::cout << "collisions" << std::endl;
				m_enemy.speed = 3;
			}
			else { m_enemy.speed = 5; }

			//Ranged enemy moving through puddles
			if (Collision::PixelPerfectTest(m_enemyRanger.enemyRangerSprite, m_puddles.m_puddleSprites[0]))
			{
				std::cout << "collisions" << std::endl;
				m_enemyRanger.speed = 3;
			}
			else if (Collision::PixelPerfectTest(m_enemyRanger.enemyRangerSprite, m_puddles.m_puddleSprites[1]))
			{
				std::cout << "collisions" << std::endl;
				m_enemyRanger.speed = 3;
			}
			else { m_enemyRanger.speed = 5; }



			////Ranged enemy or normal enemy climbing over wall
			//for (int i = 0; i < 25; i++)
			//{

			//	//if (Collision::PixelPerfectTest(m_enemy.enemySprite, m_walls.m_wallSprites[i]))
			//	if (m_enemy.enemySprite.getGlobalBounds().intersects(m_walls.m_wallSprites[i].getGlobalBounds()))
			//	{
			//		std::cout << "collisions" << std::endl;
			//		m_enemy.speed = 1;
			//	}
			//	else{ m_enemy.speed = 5; }

			//	if (Collision::PixelPerfectTest(m_enemyRanger.enemyRangerSprite, m_walls.m_wallSprites[i]))
			//	{
			//		std::cout << "collisions" << std::endl;
			//		m_enemyRanger.speed = 1;
			//	}
			//	else { m_enemyRanger.speed = 5; }
			//}


			if (Collision::PixelPerfectTest(myPlayer.m_playerSprite, m_enemy.enemySprite))
			{
				myPlayer.m_health--;
				m_particleSystem.Initialise(myPlayer.getPlayerPosition());
			}
			if (myPlayer.m_health <= 0)
			{
				myPlayer.m_health = 0;
				gameLost = true;
			}



			if (myProjectile.m_projectileLine.getBounds().intersects(m_enemy.enemySprite.getGlobalBounds()))
			{
				m_enemy.enemyAlive = false;
				m_enemy.enemySprite.setPosition(900.0f, 3500.0f);
				enemiesKilled++;
				myProjectile.m_projectileLine.clear();
				myProjectile.m_projectileShot = false;
				//std::cout << enemiesKilled << std::endl;
			}
			if (myProjectile.m_projectileLine.getBounds().intersects(m_enemyRanger.enemyRangerSprite.getGlobalBounds()))
			{
				m_enemyRanger.enemyAlive = false;
				m_enemyRanger.enemyRangerSprite.setPosition(1200.0f, 3500.0f);
				enemiesKilled++;
				myProjectile.m_projectileLine.clear();
				myProjectile.m_projectileShot = false;
				//std::cout << enemiesKilled << std::endl;

			}
			//If enemy shoots player
			if (m_enemyRanger.m_projectileLine.getBounds().intersects(myPlayer.m_playerSprite.getGlobalBounds()))
			{
				myPlayer.m_health -= 30;
				m_particleSystem.Initialise(myPlayer.getPlayerPosition());
				m_enemyRanger.m_projectileLine.clear();
				m_enemyRanger.m_projectileShot = false;

			}

			/// <summary>
			/// Objectives
			/// </summary>

			//Task 1 Generators Built
			if (m_objHud.gen2ObjectiveDone == true && m_objHud.gen1ObjectiveDone == true)
			{
				m_objHud.m_objectiveComplete1 = true;
			}
			else if (m_objHud.gen2ObjectiveDone == true || m_objHud.gen1ObjectiveDone == true)
			{
				m_objHud.m_taskOneText.setString("1/2 Generators built");
				m_objHud.m_taskOneText.setFillColor(sf::Color::Yellow);
			}

			//Task 2 Rubbish Collected
			m_objHud.m_taskTwoText.setString(std::to_string(rubbishCollected) + "/20");
			if (rubbishCollected == 10 && rubbishCollected < 11)
			{
				m_objHud.m_taskTwoText.setFillColor(sf::Color::Yellow);
			}
			if (rubbishCollected >= 20)
			{
				m_objHud.m_objectiveComplete2 = true;
			}

			//Task 3 Enemies killed
			m_objHud.m_taskThreeText.setString(std::to_string(enemiesKilled) + "/10");
			if (enemiesKilled >= 10)
			{
				m_objHud.m_objectiveComplete3 = true;
			}

			//Game Complete
			if (m_objHud.m_objectiveComplete1 == true && m_objHud.m_objectiveComplete2 == true && m_objHud.m_objectiveComplete3 == true)
			{
				m_objHud.m_objectiveComplete4 = true;
			}

			for (int i = 0; i < 31; i++)
			{


				if (myProjectile.m_rubbishLine.getBounds().intersects(m_rubbish[i].m_rubbishSprite.getGlobalBounds()) && m_rubbish[i].rubbishExisting == true)
				{
					m_rubbish[i].rubbishExisting = false;
					//std::cout << "Rubbish Sucked";

					myProjectile.m_ammo++;
					rubbishCollected++;
					m_rubbish[i].m_rubbishSprite.setPosition(-999, -999);

				}
			}
			for (int i = 0; i < 3; i++)
			{
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////parts for buildable 2
				if (m_buildParts2[i].partSprite.getGlobalBounds().intersects(myPlayer.m_playerSprite.getGlobalBounds()) && m_buildParts2[i].PartPicked == true)
				{
					m_buildParts2[i].update(myPlayer);
				}

				if (m_buildParts2[i].partSprite.getGlobalBounds().intersects(m_buildable2.m_drop_zone.getGlobalBounds()) && m_buildParts2[i].PartPicked != true && m_buildable2.dropZone_alive == true)
				{
					//m_reactorPickup[i].allowCountAtDrop = true;
					if (m_buildParts2[i].alive == true)
					{
						count_at_dropZone2++;
						//m_reactorPickup[i].allowCountAtDrop = false;
						m_buildParts2[i].alive = false;

						if (count_at_dropZone2 == 3)
						{
							//std::cout << "Generator 2 is building" << std::endl;
							m_buildable2.alive = true;
							m_buildable2.dropZone_alive = false;
							m_objHud.gen2ObjectiveDone = true;

						}
					}

				}


				if (m_buildParts1[i].partSprite.getGlobalBounds().intersects(myPlayer.m_playerSprite.getGlobalBounds()) && m_buildParts1[i].PartPicked == true)
				{
					m_buildParts1[i].update(myPlayer);
				}

				if (m_buildParts1[i].partSprite.getGlobalBounds().intersects(m_buildable1.m_drop_zone.getGlobalBounds()) && m_buildParts1[i].PartPicked != true && m_buildable1.dropZone_alive == true)
				{
					//m_reactorPickup[i].allowCountAtDrop = true;
					if (m_buildParts1[i].alive == true)
					{
						count_at_dropZone1++;
						//m_reactorPickup[i].allowCountAtDrop = false;
						m_buildParts1[i].alive = false;

						if (count_at_dropZone1 == 3)
						{
							//std::cout << "Generator 1 is building" << std::endl;
							m_buildable1.alive = true;
							m_buildable1.dropZone_alive = false;
							m_objHud.gen1ObjectiveDone = true;
						}
					}

				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if (sf::Joystick::isConnected(0))
				{
					if (sf::Joystick::isButtonPressed(0, 2)) //X
					{
						for (int i = 0; i < 3; i++)
						{
							m_buildParts1[i].itemUp();
							m_buildParts2[i].itemUp();
						}
					}
					if (sf::Joystick::isButtonPressed(0, 1)) //B
					{
						for (int i = 0; i < 3; i++)
						{
							m_buildParts1[i].itemDown();
							m_buildParts2[i].itemDown();
						}
					}
				}
				else
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
					{
						for (int i = 0; i < 3; i++)
						{
							m_buildParts1[i].itemUp();
							m_buildParts2[i].itemUp();

						}
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
					{
						for (int i = 0; i < 3; i++)
						{
							m_buildParts1[i].itemDown();
							m_buildParts2[i].itemDown();

						}
					}
				}
				//}
			}


		}
		else if (sidegameon == true)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{	
				sidegameon = false;	
			}

			//if (ballinBin == true)
			//{

			//	sidegameon = false;	
			//}
			//update the side game
			if (ballinBin == false)
			{
				physicsText.setString("hold + drag left click");
				physicsText.setPosition(200, 200);
			}
			if (rubbish.getPosition().y + rubbish.getRadius() > trueHeight)
			{
				velocity.y *= -0.7;
				rubbish.setPosition(rubbish.getPosition().x, trueHeight - rubbish.getRadius());
				//rubbish.move(velocity.x * timeSinceLastUpdate.asSeconds(), velocity.y * timeSinceLastUpdate.asSeconds());
			}
			else if (rubbish.getPosition().y - rubbish.getRadius() < 0)
			{
				velocity.y *= -0.7;
				rubbish.setPosition(rubbish.getPosition().x, 0 + rubbish.getRadius());
			}

			if (rubbish.getPosition().x + rubbish.getRadius() > trueWidth)
			{
				velocity.x *= -0.7;
				rubbish.setPosition(trueWidth - rubbish.getRadius(), rubbish.getPosition().y);
				//rubbish.move(velocity.x * timeSinceLastUpdate.asSeconds(), velocity.y * timeSinceLastUpdate.asSeconds());
			}
			else if (rubbish.getPosition().x - rubbish.getRadius() < 0)
			{
				velocity.x *= -0.7;
				rubbish.setPosition(0 + rubbish.getRadius(), rubbish.getPosition().y);
				//rubbish.move(velocity.x * timeSinceLastUpdate.asSeconds(), velocity.y * timeSinceLastUpdate.asSeconds());
			}
			if(rubbish.getGlobalBounds().intersects(bin.getGlobalBounds()))
			{
				ballinBin = true;
				rubbish.setFillColor(sf::Color::White);
				rubbish.setPosition(-100000, -100000);
				physicsText.setString("Rubbish is binned\n Press 'z' ");
				physicsText.setPosition(200,200);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				playingStateofExtragame = drawingLine;
			}

			if (playingStateofExtragame == drawingLine)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2f localPosition = (sf::Vector2f)sf::Mouse::getPosition(m_Window);
					moveForce = localPosition - rubbish.getPosition();

					if (thor::length(moveForce + velocity) < rubbishMaxSpeed)
					{
						velocity += moveForce;
					}
					else {
						thor::setLength(moveForce, rubbishMaxSpeed);
						velocity += moveForce;
					}
					if (thor::length(velocity) < rubbishMaxSpeed)
					{
						thor::setLength(velocity, rubbishMaxSpeed);
					}
					playingStateofExtragame = Jump;
					gravity.y = 9.8 * gravityScale;
				}
			}
			if (playingStateofExtragame == Jump)
			{
				playingStateofExtragame = drawingLine;
			}
			velocity = velocity + (gravity * timeSinceLastUpdate.asSeconds());
			rubbish.move(velocity.x * timeSinceLastUpdate.asSeconds(), velocity.y * timeSinceLastUpdate.asSeconds());

			if (rubbish.getPosition().y > 600 - rubbish.getRadius())
			{
				gravity.y -= 1.0;
				velocity.y -= 1.0;
			}

			sf::Vector2i localPosition = sf::Mouse::getPosition(m_Window);
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(localPosition.x, localPosition.y),sf::Color::Magenta),
				sf::Vertex(sf::Vector2f(rubbish.getPosition().x, rubbish.getPosition().y),sf::Color::Transparent)

			};
			m_Window.setView(extraGameView);
			m_Window.clear();
			m_Window.draw(physicsText);
			m_Window.draw(bin);
			if (ballinBin == false)
			{
				m_Window.draw(line, 2, sf::Lines);
				m_Window.draw(rubbish);
			}
			
		}
		//////////////////////////////////////////////////////////
	}
}

void Game::draw()
{

	if (gameMode == MENU)
	{
		m_Window.clear(sf::Color(0, 0, 0, 0));
		//view.setViewport(sf::FloatRect(0, 0, 1200.0f, 900.0f));

		//view.reset(sf::FloatRect(0, 0, 1200, 900));
		m_mainMenu.draw(m_Window);
		
	}
	else if (gameMode == CONTROLS)
	{
		m_Window.clear(sf::Color(0, 0, 0, 0));
		m_Window.draw(m_controlsSprite);
		m_Window.draw(returnText);
	}
	else if (gameMode == SETTINGS)
	{
		m_Window.clear(sf::Color(0, 0, 0, 0));
		m_settings.draw(m_Window);
		m_Window.draw(settingsText);
		m_Window.draw(returnText);
	}
	else if (gameMode == PLAY)
	{
		if (sidegameon == false)
		{
			m_Window.clear(sf::Color(0, 0, 0, 0));
			m_Window.setView(view);

			map.draw(m_Window);


			//m_dropZone.draw(m_Window);
			m_buildable1.draw(m_Window);
			m_buildable2.draw(m_Window);
			//m_buildable3.draw(m_Window);

			m_factories.draw(m_Window);
			m_houses.draw(m_Window);
			m_puddles.draw(m_Window);
			m_walls.draw(m_Window);
			m_enemy.draw(m_Window);
			m_enemyRanger.draw(m_Window);

			for (int i = 0; i < 3; i++)
			{
				m_buildParts1[i].draw(m_Window);
				m_buildParts2[i].draw(m_Window);
				//	m_buildParts3[i].draw(m_Window);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))	//PRESS G TO DRAW GRID
			{
				m_grid.render(m_Window);											//ENABLES THE GRID TO BE DRAWN
			}
			myProjectile.render(m_Window);



			for (int i = 0; i < 31; i++)
			{
				if (m_rubbish[i].rubbishExisting == true)
				{
					m_rubbish[i].draw(m_Window);
				}
			}
			m_Window.draw(sideGameSprite);
			myPlayer.draw(m_Window);
			m_particleSystem.Draw(m_Window);
			m_objHud.draw(m_Window);
			if (displayTut == true)
			{
				m_Window.draw(tutorialText);
			}
			if (gameLost == true)
			{
				m_Window.draw(pauseScreen);
				m_Window.draw(lossText);
			}
			if (gamewon == true)
			{
				m_Window.draw(pauseScreen);
				m_Window.draw(lossText);
			}
			if (paused == true)
			{
				m_Window.draw(pauseScreen);
				m_Window.draw(pauseText);
			}
		}
		else if (sidegameon == true)
		{
			

			


		}
	
	}
	

	
	m_Window.display();

}

void Game::checkCell()
{
}

void Game::checkForUnpause()
{
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, 0)) //A
		{
			paused = false;
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			paused = false;
		}
	}

}











