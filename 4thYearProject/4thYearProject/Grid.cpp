#include "Grid.h"


//Default constructor
Grid::Grid()
{

}

//Overloaded constructor taking width and height of the Grid in number of cells.
//Height: Number of tiles in Y plane.
//Width: Number of tiles in X plane.
//Constructor initializes the 2D array of Tile objects.
Grid::Grid(const int &width, const int &height, const std::string &tileType) : m_width(width), m_height(height)
{

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