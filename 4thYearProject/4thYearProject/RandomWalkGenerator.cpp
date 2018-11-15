#include "RandomWalkGenerator.h"


RandomWalkGenerator::RandomWalkGenerator()
{

}
//Overloaded constructor
//Width: width of the level in number of tiles.
//Height: height of the level in number of tiles.

RandomWalkGenerator::RandomWalkGenerator(int width, int height) : m_width(width), m_height(height)
{
	//Add the original walker to the vector
	m_walkers.push_back(new RandomWalker(sf::Vector2i(thor::random(0, m_width), thor::random(0, m_height))));
	
	//Dynamically allocate 2d array of gridspaces.
	m_gridSpace = new GridSpace*[m_width];
	for (int i = 0; i < m_width; i++)
	{
		m_gridSpace[i] = new GridSpace[m_height];
	}

	//Dynamically allocate 2d array of Tile objects.
	m_tileArray = new Tile**[m_width];
	for (int i = 0; i < m_width; i++)
	{
		m_tileArray[i] = new Tile*[m_height];
	}



	//Initialize gridspace as entirely empty cells.
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			m_gridSpace[i][j] = GridSpace::empty;
		}
	}
}

void RandomWalkGenerator::generate()
{
	int iterations = 0;
	

	//main loop
	do
	{
		//Create floor at the position of each walker.
		for (auto walker : m_walkers)
		{
			m_gridSpace[std::clamp(walker->getPosition().x, 1, m_width - 2)][std::clamp(walker->getPosition().y, 1, m_height - 2)] = GridSpace::floor;
		}

		calculateNewDirection();
		destroyWalker();
		spawnNewWalker();

		//Move each walker
		for (auto walker : m_walkers)
		{
			//Clamp the position value so it cannot go outside of the bounds of the level
			std::clamp(walker->getPosition().x, 1, m_width - 2);
			std::clamp(walker->getPosition().y, 1, m_height - 2);

			//move each walker
			walker->move();
		}

		if ((float)(numberOfFloorsInGrid() / (float)(m_width * m_height)) > FILL_PERCENTAGE)
		{
			break;
		}

		iterations++;

		

	} while (iterations < 10000);

	//Lastly, create the tile array as a visual representation of m_gridSpace.
	createTileArray();
}

void RandomWalkGenerator::destroyWalker()
{
	std::list<RandomWalker*>::iterator iter;
	for (iter = m_walkers.begin(); iter != m_walkers.end(); ++iter)
	{
		//if number generated is less than our constant chance to destroy and there is more than 1 walker
		if (thor::random(0.0f, 1.0f) < CHANCE_TO_DESTROY && m_walkers.size() > 1)
		{
			m_walkers.remove(*iter);
			break;
		}
	}
}

void RandomWalkGenerator::spawnNewWalker()
{
	//If the random value is less than the chance to spawn a new one and there isnt already the maximum number of walkers
	std::list<RandomWalker*>::iterator iter;
	for (iter = m_walkers.begin(); iter != m_walkers.end(); ++iter)
	{
		if (thor::random(0.0f, 1.0f) < CHANCE_TO_SPAWN_NEW_WALKER && m_walkers.size() < MAX_WALKERS)
		{
			//add a new walker to the list, starting in the middle of the grid.
			//m_walkers.push_back(new RandomWalker(sf::Vector2i(m_width / 2, m_height / 2)));
			m_walkers.push_back(new RandomWalker((*iter)->getPosition()));
			break;
		}
	}
}

void RandomWalkGenerator::calculateNewDirection()
{
	std::list<RandomWalker*>::iterator iter;
	for (iter = m_walkers.begin(); iter != m_walkers.end(); ++iter)
	{
		if (thor::random(0.0f, 1.0f) < CHANCE_TO_CHANGE_DIRECTION)
		{
			(*iter)->getNewDirection();
			std::cout << "Direction changed" << std::endl;
		}

		if ((*iter)->getPosition().x == 1 ||
			(*iter)->getPosition().x == m_width - 2 ||
			(*iter)->getPosition().y == 1 ||
			(*iter)->getPosition().y == m_width - 2)
		{
			(*iter)->getNewDirection();
		}
	}
}

int RandomWalkGenerator::numberOfFloorsInGrid()
{
	int count = 0;
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (m_gridSpace[i][j] == GridSpace::floor)
			{
				count++;
			}
		}
	}
	std::cout << "Number of floors: " << count << std::endl;
	return count;
}

void RandomWalkGenerator::createTileArray()
{
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (m_gridSpace[i][j] == GridSpace::empty)
			{
				m_tileArray[i][j] = new WallTile(i, j);
			}

			if (m_gridSpace[i][j] == GridSpace::wall)
			{
				m_tileArray[i][j] = new WallTile(i, j);
			}

			if (m_gridSpace[i][j] == GridSpace::floor)
			{
				m_tileArray[i][j] = new FloorTile(i, j);
			}
		}
	}
}

void RandomWalkGenerator::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			m_tileArray[i][j]->draw(window);
		}
	}
}