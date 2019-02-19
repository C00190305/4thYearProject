#include "Grid.h"


//Default constructor
Grid::Grid()
{

}

//Overloaded constructor taking width and height of the Grid in number of cells.
//Height: Number of tiles in Y plane.
//Width: Number of tiles in X plane.
Grid::Grid(const int &width1, const int &height1, const int &width2, const int &height2)
{
	m_width = width1 + width2;
	m_height = height1 + height2;

	m_dataVector.reserve(m_height);
	for (int i = 0; i < m_dataVector.size(); i++)
	{
		m_dataVector[i].reserve(m_width);
	}
}


void Grid::draw(sf::RenderWindow &window)
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