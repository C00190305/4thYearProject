#include "Grid.h"


//Default constructor
Grid::Grid()
{

}

//Overloaded constructor taking width and height of the Grid in number of cells.
//Height: Number of tiles in Y plane.
//Width: Number of tiles in X plane.
Grid::Grid(const int &width1, const int &height1, const int &width2, const int &height2, const int &x1, const int &y1, const int &x2, const int &y2) :
		   m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
{
	m_width = width1 + width2;
	m_height = height1 + height2;

	m_dataVector.reserve(m_height);
	for (int i = 0; i < m_dataVector.size(); i++)
	{
		m_dataVector[i].reserve(m_width);
	}
}

//\param randomWalkGenerator : pointer to RandomWalkGenerator
//\param cellularAutomataGenerator : pointer to CellularAutomataGenerator
Grid::Grid(RandomWalkGenerator* randomWalkGenerator, CellularAutomataGenerator* cellularAutomataGenerator)
{
	m_pCellularAutomataGenerator = cellularAutomataGenerator;
	m_pRandomWalkGenerator = randomWalkGenerator;

	m_width = randomWalkGenerator->getWidth() + cellularAutomataGenerator->getWidth();
	m_height = randomWalkGenerator->getHeight() + cellularAutomataGenerator->getHeight();

	m_dataVector.reserve(m_height);
	for (int i = 0; i < m_dataVector.size(); i++)
	{
		m_dataVector[i].reserve(m_width);
	}
}

void Grid::generate()
{
	
}

int Grid::getWidth()
{
	return m_width;
}

int Grid::getHeight()
{
	return m_height;
}

std::vector<std::vector<int>> Grid::getData()
{
	return m_dataVector;
}