#include "CellularAutomataGenerator.h"

CellularAutomataGenerator::CellularAutomataGenerator()
{
}

CellularAutomataGenerator::CellularAutomataGenerator(int width, int height, int numberOfSimulationSteps) : m_width(width), m_height(height), m_numSimulationSteps(numberOfSimulationSteps)
{
	//Initialize vector

	m_chanceStartAlive = 0.40f;
	m_birthLimit = 4;
	m_deathLimit = 3;
	grid.reserve(m_width);
	grid.resize(m_width);
	m_tileVector.reserve(m_width);
	m_tileVector.resize(m_width);
	for (int i = 0; i < m_width; i++)
	{
		grid.at(i).reserve(m_height);
		grid.at(i).resize(m_height);
		m_tileVector.at(i).reserve(m_height);
		m_tileVector.at(i).resize(m_height);
	}

	//Initialize the grid with each cell being randomly selected to be dead or alive
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (thor::random(0.0f, 1.0f) <= m_chanceStartAlive)
			{
				grid[i].at(j) = new GridSpace(GridSpace::alive);
			}

			else
			{
				grid[i].at(j) = new GridSpace(GridSpace::dead);
			}

		}
	}

}

auto CellularAutomataGenerator::doSimulationStep()
{
	//Create a new temp grid for storing new information during the simulation step.
	std::vector<std::vector<GridSpace*>> newGrid;
	newGrid = grid;
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			int neighbours = countAliveNeighbours(grid, i, j);

			if (*grid[i].at(j) == GridSpace::alive)
			{
				if (neighbours < m_deathLimit)
				{
					newGrid[i].at(j) = new GridSpace(GridSpace::dead);
				}

				else
				{
					newGrid[i].at(j) = new GridSpace(GridSpace::alive);
				}
			}

			else //The cell is currently dead
			{
				if (neighbours > m_birthLimit)
				{
					newGrid[i].at(j) = new GridSpace(GridSpace::alive);
				}

				else
				{
					newGrid[i].at(j) = new GridSpace(GridSpace::dead);
				}
			}
		}
	}

	return newGrid;

}

void CellularAutomataGenerator::generate()
{
	for (int i = 0; i < m_numSimulationSteps - 1; i++)
	{
		grid = doSimulationStep();
	}
	createTileArray();
}

//Counts the neighbours around the cell at index x, y in the 2d vector
int CellularAutomataGenerator::countAliveNeighbours(std::vector<std::vector<GridSpace*>> grid, int x, int y)
{
	int count = 0;	
	
	if (x - 1 < 0 || y - 1 < 0 || x >= m_width || y >= m_height)
	{
		count++;
	}

	if (*grid[std::clamp((x - 1), 0, m_width - 1)].at(std::clamp((y - 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[x].at(std::clamp((y - 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[std::clamp(x + 1, 0, m_width - 1)].at(std::clamp((y - 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[std::clamp(x + 1, 0, m_width - 1)].at(y) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[std::clamp(x + 1, 0, m_width - 1)].at(std::clamp((y + 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[x].at(std::clamp((y + 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[std::clamp(x - 1, 0, m_width - 1)].at(std::clamp((y + 1), 0, m_height - 1)) == GridSpace::alive)
	{
		count++;
	}

	if (*grid[std::clamp(x - 1, 0, m_width - 1)].at(y) == GridSpace::alive)
	{
		count++;
	}
	std::cout << count << std::endl;
	return count;
}

void CellularAutomataGenerator::createTileArray()
{
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			if (*grid[i].at(j) == GridSpace::alive)
			{
				m_tileVector[i].at(j) = new FloorTile(i, j);
			}

			else if (*grid[i].at(j) == GridSpace::dead)
			{
				m_tileVector[i].at(j) = new WallTile(i, j);
			}


		}
	}
}

void CellularAutomataGenerator::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			m_tileVector[i].at(j)->draw(window);
		}
	}
}

CellularAutomataGenerator::~CellularAutomataGenerator()
{
}
