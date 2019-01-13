#include "CellularAutomataGenerator.h"



CellularAutomataGenerator::CellularAutomataGenerator()
{
}

CellularAutomataGenerator::CellularAutomataGenerator(int width, int height, int numberOfSimulationSteps) : m_width(width), m_height(height), m_numSimulationSteps(numberOfSimulationSteps)
{
	//Initialize vector

	m_chanceStartAlive = 0.45f;
	grid.reserve(m_width);
	grid.resize(m_width);
	for (int i = 0; i < m_width; i++)
	{
		grid.at(i).reserve(m_height);
		grid.at(i).resize(m_height);
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

CellularAutomataGenerator::~CellularAutomataGenerator()
{
}
