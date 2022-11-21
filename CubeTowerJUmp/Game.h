#pragma once
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else #pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif #include "ScreenSize.h"
#include <stdlib.h> 
#include <time.h> 
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Projectile.h"
#include "Globals.h"
#include "MainMenu.h"
#include "Enemy.h"
#include "Rubbish.h"
#include "MapLevel.h"
#include "EnemyRanger.h"
#include "Grid.h"

#include "Buildable1.h"
#include "Buildable2.h"


#include "BuildParts1.h"
#include "BuildParts2.h"

#include "Collision.h"

#include "ObjectivesHud.h"

#include "Factory.h"
#include "House.h"
#include "Puddle.h"
#include "Wall.h"

#include "Settings.h"
#include "Particle.h"
#include "ParticleSystem.h"

#include "VectorAlgebra2D.h"
enum ExtragameStages { drawingLine, Jump };
class Game
{
	sf::RenderWindow m_Window;
public:
	Game();
	Player myPlayer;
	Projectile myProjectile;
	MainMenu m_mainMenu;  // object used to display main menu
	Rubbish m_rubbish[50];	// object for rubbish
	enemy m_enemy;		//object for enemy
	EnemyRanger m_enemyRanger; //Second Enemy

	MapLevel map;


	BuildParts1 m_buildParts1[3];
	BuildParts2 m_buildParts2[3];

	Buildable1 m_buildable1;
	Buildable2 m_buildable2;

	Grid m_grid;

	Factory m_factories;
	House m_houses;
	Puddle m_puddles;
	Wall m_walls;

	ObjectivesHud m_objHud;

	Settings m_settings;

	Particle m_particles;		//particels
	ParticleSystem m_particleSystem;	//particle system

	//Enemyt shoot timer
	sf::Clock clock;
	sf::Time elapsed;


	//Animation myAnimation(&myPlayer.m_playerTexture, sf::Vector2u(6, 0), 0.05f);
	int count_at_dropZone1 = 0;
	int count_at_dropZone2 = 0;
	int gameMode;						// to represent the different modes in the game, for  
										// example game instruction mode and game play mode

	int enemiesKilled = 0;
	int rubbishCollected = 0;
	int generatorsBuilt = 0;


	//collisions
	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;


	//game stage gray to colour bools
	bool firstStageComplete = false;
	bool secondStageComplete = false;

	//Lost screen
	bool gameLost = false;
	bool gamewon = false;
	sf::Text lossText;

	//	pause screen
	bool paused = false;		//bool to allow the pause screen
	sf::Text pauseText;			//text to indicate paused screen
	sf::RectangleShape pauseScreen;

	sf::View view{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1200, 900) };;

	float trueHeight;
	float trueWidth;

	sf::Font m_PixellariFont;
	sf::Text returnText;

	//Tutorial
	sf::Text tutorialText;
	bool displayTut = true;
	bool allowReset = true;
	sf::Clock tutClock;
	sf::Time tutElapsed;

	sf::Sprite sideGameSprite;
	sf::Texture sideGameTexture;
	bool sidegameon = false;

	void checkForUnpause();
	sf::Sprite m_controlsSprite;
	sf::Texture m_controlsTexture;
	sf::Texture m_buttonTexture;		//button texture
	void run();
	void update(float delta);
	void draw();
	void loadContent();
	void checkCell();
	
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//extra game variables
	sf::RectangleShape bin;
	sf::CircleShape rubbish;
	sf::Vector2f moveForce;
	ExtragameStages playingStateofExtragame = drawingLine;
	float gravityScale = 100;
	sf::Vector2f velocity = { 0,0 };
	float rubbishMaxSpeed = 50;
	sf::Vector2f gravity{ 0.0f, 9.8f * gravityScale };
	sf::Vector2f normalised;
	sf::View extraGameView;
	bool ballinBin= false;
	sf::Text physicsText;
	sf::Text settingsText;

private:


};