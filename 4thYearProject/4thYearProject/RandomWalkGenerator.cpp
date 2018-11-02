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
	m_walkers.push_back(new RandomWalker(sf::Vector2i(thor::random(m_width, m_height), thor::random(m_width, m_height))));
	
	//Dynamically allocate 2d array of gridspaces.
	m_gridSpace = new GridSpace*[m_width];
	for (int i = 0; i < m_width; i++)
	{
		m_gridSpace[i] = new GridSpace[m_height];
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
			m_gridSpace[walker->getPosition().x][walker->getPosition().y] = GridSpace::floor;
		}

		destroyWalker();
		spawnNewWalker();

	} while (iterations < 50);
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
	if (thor::random(0.0f, 1.0f) < CHANCE_TO_SPAWN_NEW_WALKER && m_walkers.size() < MAX_WALKERS)
	{
		//add a new walker to the list, starting in the middle of the grid.
		m_walkers.push_back(new RandomWalker(sf::Vector2i(m_width / 2, m_height / 2)));
	}
}

void RandomWalkGenerator::calculateNewDirection()
{
	std::list<RandomWalker*>::iterator iter;
	for (iter = m_walkers.begin(); iter != m_walkers.end(); ++iter)
	{
		iter
	}
}