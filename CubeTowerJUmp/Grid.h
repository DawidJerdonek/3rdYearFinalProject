#pragma once
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#include <iostream>
#include <vector>
#include "Enemy.h"
#include "EnemyRanger.h"
#include "Player.h"
#include <queue>
#include <functional>
#include <SFML/Graphics.hpp>
#include "House.h"
#include "Factory.h"
#include "Buildable1.h"
#include "Puddle.h"
#include "Wall.h"
#include <stack>

//Game m_game;

class Cell {
public:
	Cell();
	~Cell();

	
	int m_id = 0;
	int m_previousCellId{ -1 };
	bool m_marked = false;
	bool m_isPassable = true;
	bool m_isPuddle = false;
	bool m_isWall = false;

	int m_centreX = 0;
	int m_centreY = 0;

	float m_h;
	float m_pathCost;

	std::vector<int> m_diagonalList;

	Cell* m_previous;

	Cell(sf::Vector2f t_position, int t_cellID);
	Cell* previous() const;
	int weight() const;
	void setPrevious(Cell* previous)
	{
		m_previous = previous;
	}

	bool marked() const;
	void setMarked(bool t_marked);
	void addNeighbour(int t_cellID);
	int returnID() const {
		return m_id;
	}
	void render(sf::RenderWindow& t_window);
	//std::vector<int>& neighbours();


	sf::RectangleShape m_shape;
	
	std::vector<int> m_neighbours;

};

class Grid {
public:
	//Grid(enemy & t_enemy);
	Grid(enemy& t_enemy , EnemyRanger& t_enemyRanger, Player& t_player);
	~Grid();

//	Grid(int t_rows, int t_cols);

	sf::RectangleShape m_starPathShape[300];
	sf::RectangleShape m_notTraversal[300];

	Cell& returnCell(int t_id);

	void neighbours(int t_row, int t_col, std::vector<Cell>& t_cells, int t_current);
	void reset();
	void initialiseMap();
	void update(Player& t_player);
	void findPath(Cell* start, Cell* end, Cell*& goal);
	void findPathRanger(Cell* start, Cell* end, Cell*& goal);
	void render(sf::RenderWindow& t_window);
	void aStar(Cell* start, Cell* dest);
	Cell* findCellPoint(sf::Vector2f point);

	std::vector<Cell>& returnAllCells();

	sf::Text m_cellId[1601];
	sf::Font m_font;
	std::vector<std::vector<Cell>> m_cellsVectorArray;
	std::vector<Cell> m_cellsArray;

	//Cell* goal = &m_cellsArray.at(883);

	House m_myhouse;
	Factory m_myFactory;
	Puddle m_myPuddles;
	Wall m_myWalls;
	enemy & m_myEnemy;
	EnemyRanger & m_rangedEnemy;
	Player &m_myPlayer;
	Buildable1 m_buildable;
	int m_maxRows = 40;
	int m_maxCols = 40;
	int m_currentRow;
	int m_currentCol;


	//collisions
	bool left= false;
	bool right = false;
	bool up = false;
	bool down = false;


private:

};

