#pragma once
#ifndef GRID_H
#define GRID_H

#include <vector>

#include "Tile.h"

class Grid
{
public:
	Grid();

	//Width and height in number of tiles.
	Grid(int width, int height);
private:
	int m_width;
	int m_height;	
};

#endif // !GRID_H

