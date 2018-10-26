#pragma once
#ifndef GRID_H
#define GRID_H

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
	Tile tileArray; //2D array of tiles.
};

#endif // !GRID_H

