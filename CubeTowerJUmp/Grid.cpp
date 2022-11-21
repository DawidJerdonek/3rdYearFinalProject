#include "Grid.h"


class AStarComparer
{
public:
	bool operator()(Cell* t_n1, Cell* t_n2) const
	{
		return (t_n1->m_h + t_n1->m_pathCost) > (t_n2->m_h + t_n2->m_pathCost);

	}
};

Cell::Cell()
{

}

Cell::~Cell()
{
}

Cell::Cell(sf::Vector2f t_position, int t_cellID)
{
    m_id = t_cellID;
    m_shape.setSize(sf::Vector2f(5120 / 40, 5120 / 40));
    m_shape.setFillColor(sf::Color::Transparent);
    m_shape.setOutlineColor(sf::Color::Red);
    m_shape.setOutlineThickness(1);
    m_shape.setPosition(t_position);
    m_isPassable = true;
    m_previousCellId = -1;


}

Cell* Cell::previous() const
{
    return m_previous;
}

int Cell::weight() const
{
	return 1;
}

bool Cell::marked() const
{
	return m_marked;
}

void Cell::setMarked(bool t_marked) //bool that is checking if the cell is marked
{
	m_marked = t_marked;
} 

void Cell::render(sf::RenderWindow& t_window)
{
    t_window.draw(m_shape);
}

void Cell::addNeighbour(int t_cellID) // adding a cell id to the neighbours
{
    m_neighbours.push_back(t_cellID);
}


Grid::Grid(enemy& t_enemy, EnemyRanger& t_enemyRanger, Player& t_player) : m_myEnemy(t_enemy), m_rangedEnemy(t_enemyRanger), m_myPlayer(t_player)
{

    initialiseMap();
	Cell* goal = findCellPoint(m_myPlayer.m_playerSprite.getPosition());
	findPath(findCellPoint(m_myEnemy.enemySprite.getPosition()), goal, goal);



	
}

Grid::~Grid()
{
}

//Grid::Grid(int t_rows, int t_cols)
//{
//
//}

Cell& Grid::returnCell(int t_id)
{
    return m_cellsArray.at(t_id);
}

void Grid::neighbours(int t_row, int t_col, std::vector<Cell>& t_cells, int t_current)
{
    // List all neighbors:
    for (int direction = 0; direction < 9; direction++) {
        if (direction == 4) continue; // Skip 4, this is ourself.

        int n_row = t_row + ((direction % 3) - 1); // Neighbor row
        int n_col = t_col + ((direction / 3) - 1); // Neighbor column

        // Check the bounds:
        if (n_row >= 0 && n_row < m_maxRows && n_col >= 0 && n_col < m_maxCols) {

            // A valid neighbor:
            //std::cout << "Neighbor: " << n_row << "," << n_col << " - " << t_current << std::endl;
            t_cells.at(t_current).addNeighbour(n_row + (n_col * 40));
			// add the cell id 
			if (direction == 0 || direction == 2 || direction == 6 || direction == 8)
			{
				int diagId = t_cells.at(n_row + (n_col * 40)).m_id;
				t_cells.at(t_current).m_diagonalList.push_back(t_cells.at(n_row + (n_col * 40)).m_id);
			}
		
        }
    }
}

void Grid::reset()
{
	
	for (int i = 0; i < m_cellsArray.size(); i++)
	{
		m_cellsArray.at(i).setMarked(false);
		m_cellsArray.at(i).setPrevious(nullptr);
	}
	for (int index = 0; index < 300; index++)
	{
		m_starPathShape[index].setSize(sf::Vector2f(128.0f, 128.0f));
		m_starPathShape[index].setFillColor(sf::Color::Green);
	}
}

void Grid::initialiseMap()
{
	if (!m_font.loadFromFile("Assets/Fonts/Pixellari.ttf"))
	{
		std::cout << "error with font file file";
	}

    sf::Vector2f cellPositions{ 0,0 };
    int count = 0;
    for (int row = 0; row < m_maxRows; row++)
    {

        for (int i = 0; i < m_maxCols; i++)
        {
            Cell cell(cellPositions, count);

            cellPositions.x += 5120 / 40; // adjusting cell position on screen - x axis
            if (cellPositions.x >= 5120)
            {
                cellPositions.x = 0;
                cellPositions.y += 5120 / 40; // adjusting cell position on screen - y axis
            }

            count++;
			m_cellId[count].setFont(m_font);
			m_cellId[count].setCharacterSize(26);
			m_cellId[count].setFillColor(sf::Color::White);
			m_cellId[count].setString(std::to_string(count));
			m_cellId[count].setPosition(cellPositions);

			//m_starPathShape[count].setPosition(100, 100);
            m_cellsArray.push_back(cell);// pushing back the cell
        }
    }
    int p = 0;


	for (int index = 0; index < 300; index++)
	{
		m_starPathShape[index].setSize(sf::Vector2f(128.0f, 128.0f));
		m_starPathShape[index].setFillColor(sf::Color::Green);
		m_notTraversal[index].setSize(sf::Vector2f(128.0f, 128.0f));
		m_notTraversal[index].setFillColor(sf::Color::Red);

	}
	//for (int index = 0; index < 300; index++)
	//{
	//
	//}



    for (int i = 0; i < 1600; i++) // 40 * 40 = 1600
    {
        int posY = i / 40;
        int posX = i % 40;
        neighbours(posX, posY, m_cellsArray, i);
    }
    m_cellsArray.size();
    int i = 0;

	/// <summary>
	/// Check for impassables, walls and puddles
	/// </summary>
	int h = 0;
	//Houses
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < m_cellsArray.size(); j++)
		{
			if (m_myhouse.m_houseSprites[i].getGlobalBounds().intersects(m_cellsArray.at(j).m_shape.getGlobalBounds()))
			{
				m_notTraversal[h].setPosition((m_cellsArray.at(j).m_shape.getPosition()));
				m_cellsArray.at(j).m_isPassable = false;
				h++;
			}
		}
	}

	//Factories
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < m_cellsArray.size(); j++)
		{
			if (m_myFactory.m_factorySprites[i].getGlobalBounds().intersects(m_cellsArray.at(j).m_shape.getGlobalBounds()))
			{
				m_notTraversal[h].setPosition((m_cellsArray.at(j).m_shape.getPosition()));
				m_cellsArray.at(j).m_isPassable = false;
				h++;
			}
		}
	}

	//Puddles
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < m_cellsArray.size(); j++)
		{
			if (m_myPuddles.m_puddleSprites[i].getGlobalBounds().intersects(m_cellsArray.at(j).m_shape.getGlobalBounds()))
			{
				//m_notTraversal[h].setPosition((m_cellsArray.at(j).m_shape.getPosition()));
				//m_notTraversal[h].setFillColor(sf::Color::Yellow);
				m_cellsArray.at(j).m_isPuddle = true;
				h++;
			}
		}
	}

	//Walls
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < m_cellsArray.size(); j++)
		{
			if (m_myWalls.m_wallSprites[i].getGlobalBounds().intersects(m_cellsArray.at(j).m_shape.getGlobalBounds()))
			{
				//m_notTraversal[h].setPosition((m_cellsArray.at(j).m_shape.getPosition()));
				//m_notTraversal[h].setFillColor(sf::Color::Yellow);
				m_cellsArray.at(j).m_isWall = true;
				h++;
			}
		}
	}
	
	//Generators
	for (int j = 0; j < m_cellsArray.size(); j++)
	{
		if (m_buildable.m_drop_zone.getGlobalBounds().intersects(m_cellsArray.at(j).m_shape.getGlobalBounds()))
		{
			m_notTraversal[h].setPosition((m_cellsArray.at(j).m_shape.getPosition()));
			m_cellsArray.at(j).m_isPassable = false;
			h++;
		}
	}

}

void Grid::update(Player& t_player) // update method
{ 

	if (m_myEnemy.m_pathFound.empty() == false)
	{
		if (m_myEnemy.enemyMoving == true)
		{
			if (m_myEnemy.enemyNextPosFound == false)
			{

				m_myEnemy.targetCellPos = m_cellsArray.at(m_myEnemy.m_pathFound.back()).m_shape.getPosition();
				sf::Vector2f direction = m_myEnemy.targetCellPos - m_myEnemy.enemySprite.getPosition();
				float distance = sqrtf(direction.x * direction.x + direction.y * direction.y); //Calculate the length between two points 
				m_myEnemy.velocity = sf::Vector2f{ direction.x / distance , direction.y / distance } * m_myEnemy.speed; //Calculate unit vector
				m_myEnemy.enemyNextPosFound = true;
			}

			m_myEnemy.enemySprite.setPosition(m_myEnemy.enemySprite.getPosition() + m_myEnemy.velocity);
			auto position = m_myEnemy.enemySprite.getPosition();
			
			if (m_myEnemy.velocity.x < 0)
			{
				m_myEnemy.enemySprite.setScale(-0.6f, 0.6f);
			}
			else { m_myEnemy.enemySprite.setScale(0.6f, 0.6f); }

			sf::Vector2f length = m_myEnemy.targetCellPos - m_myEnemy.enemySprite.getPosition();
			if (sqrtf(length.x * length.x + length.y * length.y) <= 4)
			{
				m_myEnemy.enemyNextPosFound = false;
				m_myEnemy.m_pathFound.pop_back();
			}

			if (m_myEnemy.enemyAlive == false)
			{
				m_myEnemy.enemyNextPosFound = false;
				m_myEnemy.m_pathFound.pop_back();
				m_myEnemy.m_pathFound.clear();
				reset();
				m_myEnemy.enemyAlive = true;
			}
		}
		
	}
	else
	{

		m_myEnemy.enemyMoving = false;
		m_myEnemy.enemyNextPosFound = false;
		//auto temp = m_myPlayer.m_playerSprite.getPosition();
		Cell* goal = findCellPoint(m_myPlayer.m_playerSprite.getPosition());
		findPath(findCellPoint(m_myEnemy.enemySprite.getPosition()), goal, goal);


	}


	if (m_rangedEnemy.m_pathFound.empty() == false)
	{
		if (m_rangedEnemy.enemyMoving == true)
		{
			if (m_rangedEnemy.enemyNextPosFound == false)
			{
				//m_myEnemy.targetCell = m_cellsArray.at(m_myEnemy.m_pathFound.back()).m_id;
				m_rangedEnemy.targetCellPos = m_cellsArray.at(m_rangedEnemy.m_pathFound.back()).m_shape.getPosition();
				sf::Vector2f direction = m_rangedEnemy.targetCellPos - m_rangedEnemy.enemyRangerSprite.getPosition();
				float distance = sqrtf(direction.x * direction.x + direction.y * direction.y); //Calculate the length between two points 
				m_rangedEnemy.velocity = sf::Vector2f{ direction.x / distance , direction.y / distance } *m_rangedEnemy.speed; //Calculate unit vector
				m_rangedEnemy.enemyNextPosFound = true;
			}

			m_rangedEnemy.enemyRangerSprite.setPosition(m_rangedEnemy.enemyRangerSprite.getPosition() + m_rangedEnemy.velocity);
			auto position = m_rangedEnemy.enemyRangerSprite.getPosition();
			if (m_rangedEnemy.velocity.x < 0)
			{
				m_rangedEnemy.enemyRangerSprite.setScale(-0.6f, 0.6f);
			}
			else { m_rangedEnemy.enemyRangerSprite.setScale(0.6f, 0.6f); }

			sf::Vector2f length = m_rangedEnemy.targetCellPos - m_rangedEnemy.enemyRangerSprite.getPosition();
			if (sqrtf(length.x * length.x + length.y * length.y) <= 4)
			{
				m_rangedEnemy.enemyNextPosFound = false;
				m_rangedEnemy.m_pathFound.pop_back();
			}

			if (m_rangedEnemy.enemyAlive == false)
			{
				m_rangedEnemy.enemyNextPosFound = false;
				m_rangedEnemy.m_pathFound.pop_back();
				m_rangedEnemy.m_pathFound.clear();
				reset();
				m_rangedEnemy.enemyAlive = true;
			}
		}

	}
	else
	{

		m_rangedEnemy.enemyMoving = false;
		m_rangedEnemy.enemyNextPosFound = false;
		
		for (int index = 0; index < 300; index++)
		{
			m_starPathShape[index].setPosition(-528.0f, -528.0f);
		}

		Cell* goal = findCellPoint(m_myPlayer.m_playerSprite.getPosition());
		findPathRanger(findCellPoint(m_rangedEnemy.enemyRangerSprite.getPosition()), goal, goal);
	}

}

void Grid::findPathRanger(Cell* start, Cell* end, Cell*& goal)
{

	reset();
	aStar(start, end);
	int i = 0;
	int index = goal->m_id;

	//	std::cout << m_cellsArray.at(index).m_previous->m_id << std::endl;
	//m_starPathShape[i].setPosition(m_cellsArray.at(index).m_shape.getPosition());

	if (m_rangedEnemy.m_pathFound.empty() == true)
	{
		m_rangedEnemy.m_pathFound.push_back(index);
		while (m_cellsArray.at(index).m_previous != nullptr)
		{
			//std::cout << m_cellsArray.at(index).m_previous->m_id << std::endl;

			m_rangedEnemy.m_pathFound.push_back(m_cellsArray.at(index).m_previous->m_id);
			m_starPathShape[i].setPosition(m_cellsArray.at(index).m_shape.getPosition());
			index = m_cellsArray.at(index).m_previous->m_id;
			i++;
		}
	}
	m_rangedEnemy.enemyMoving = true;
}
void Grid::findPath(Cell* start, Cell* end, Cell*& goal)
{
	
	reset();
	aStar(start, end);
	int i = 0;
	int index = goal->m_id;

//	std::cout << m_cellsArray.at(index).m_previous->m_id << std::endl;
	m_starPathShape[i].setPosition(m_cellsArray.at(index).m_shape.getPosition());

	if (m_myEnemy.m_pathFound.empty() == true)
	{
		m_myEnemy.m_pathFound.push_back(index);
		while (m_cellsArray.at(index).m_previous != nullptr)
		{
			//std::cout << m_cellsArray.at(index).m_previous->m_id << std::endl;

			m_myEnemy.m_pathFound.push_back(m_cellsArray.at(index).m_previous->m_id);
			m_starPathShape[i].setPosition(m_cellsArray.at(index).m_shape.getPosition());
			index = m_cellsArray.at(index).m_previous->m_id;
			i++;
		}
	}
	m_myEnemy.enemyMoving = true;
}

void Grid::render(sf::RenderWindow& t_window) // rendering the grid
{
    for (int index = 0; index < 1600; index++)
    {
        m_cellsArray.at(index).render(t_window);
		t_window.draw(m_cellId[index]);
	}
	for (int index = 0; index < 300; index++)
	{
		t_window.draw(m_starPathShape[index]);
		//t_window.draw(m_notTraversal[index]);
	
	}
	
}

std::vector<Cell>& Grid::returnAllCells() // returning all the cells
{
    return m_cellsArray;
}


//A Star Algorithm

void Grid::aStar(Cell* start, Cell* dest)
{
	Cell* s = start; // s start node
	Cell* goal = dest; //g goal node
	std::priority_queue<Cell*, std::vector<Cell*>, AStarComparer > pq; //pq = new priority queue

	int dist = std::numeric_limits<int>::max();    // Initialise dist[v] to infinity
		
	//for each node v in graph G
	for (int i = 0; i < m_cellsArray.size(); i++)
	{
		int xOne = m_cellsArray[i].m_centreX;
		int yOne = m_cellsArray[i].m_centreY;

		int xTwo = goal->m_centreX;
		int yTwo = goal->m_centreY;

		m_cellsArray[i].m_h = abs(xTwo - xOne) + abs(yTwo - yOne);  //Calculate h[v]

		m_cellsArray[i].m_pathCost = dist / 10;  //Initialise g[v] to infinity
		m_cellsArray[i].setPrevious(nullptr);
		m_cellsArray[i].setMarked(false);


	}

	if (goal != nullptr && start != nullptr)
	{
		start->m_pathCost = 0; //Initialise g[start] to 0
		start->setMarked(true); //Mark(start)
		pq.push(start); //Add start to pq
		//std::cout << "Visiting: " << pq.top()->m_id << std::endl;

		while (pq.size() != 0 && pq.top() != goal) //While the queue is not empty AND pq.top() != g
		{
			
			auto iter = pq.top()->m_neighbours.begin();
			auto endIter = pq.top()->m_neighbours.end();

			for (; iter != endIter; iter++) //For each child node of pq.top()
			{
				Cell* mychild = &returnAllCells().at(*iter);
				//std::cout << "Visiting: " << mychild->m_id << std::endl;

				if (mychild != pq.top()->previous()) //If (child !=previous(pq.top())
				{
						float weightOfArc = 0;
						float distToChild = 0;

						for (int diagId : mychild->m_diagonalList)
						{
							if (diagId == pq.top()->m_id)
							{
								weightOfArc = 1.44;
							}
						}

						if (weightOfArc == 0)
						{
							weightOfArc = mychild->weight(); //g(child)

						}

						if (mychild->m_isPuddle == true)
						{
							weightOfArc = 1.5f;//Add child to the pq
						}
						if (mychild->m_isWall == true)
						{
							weightOfArc = 10.0f;//Add child to the pq
						}
						distToChild = (weightOfArc + pq.top()->m_pathCost);

						if (distToChild < mychild->m_pathCost) //If ( distToChild < f(child) )
						{
							mychild->m_pathCost = distToChild; //let f[child] = distToChild
							mychild->setPrevious(pq.top()); //Set previous pointer of child to pq.top()
						} //End if
						if (mychild->marked() == false) //If (notMarked(child))
						{
							//pq.push(mychild);//Add child to the pq
							if (mychild->m_isPassable == true)
							{
								pq.push(mychild);//Add child to the pq
							}
							mychild->setMarked(true); //Mark Child

						} //end if
				
					}

			}//end for
			pq.pop();
		} //end while
	}
}

Cell* Grid::findCellPoint(sf::Vector2f point)
{
	for (int i = 0; i < m_cellsArray.size(); i++)
	{

		if (m_cellsArray.at(i).m_shape.getGlobalBounds().contains(point))
		{
			return &m_cellsArray.at(i);
		}
		
		
	}
	return nullptr;
}
