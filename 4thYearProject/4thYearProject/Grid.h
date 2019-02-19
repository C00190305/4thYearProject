#pragma once
#ifndef GRID_H
#define GRID_H

#include <vector>

#include "Tile.h"

//Class that controls the collective of all generator object's data structures.
class Grid
{
public:
	Grid();
	//Width and height in number of tiles.
	Grid(const int &width1, const int &height1, const int &width2, const int &height2);
	void draw(sf::RenderWindow &window);
	int getWidth();
	int getHeight();

private:
	int m_width;
	int m_height;
	std::vector<std::vector<int>> m_dataVector;
	std::vector<std::vector<Tile*>> m_tileVector;
};

#endif // !GRID_H

