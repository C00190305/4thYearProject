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
	void draw(sf::RenderWindow &window);
	int getWidth();
	int getHeight();
	//Width and height in number of tiles.
	Grid(const int &width, const int &height, const std::string &tileType);
private:
	int m_width;
	int m_height;
	std::vector<std::vector<int>> m_dataVector;
	std::vector<std::vector<Tile*>> m_tileVector;
};

#endif // !GRID_H

