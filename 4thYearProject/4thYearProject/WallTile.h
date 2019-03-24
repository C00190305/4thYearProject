#pragma once
#ifndef WALLTILE_H
#define WALLTILE_H


#include "Tile.h"

class WallTile : public Tile
{
public:
	WallTile();
	WallTile(int offsetX, int offsetY, int x, int y);
	void draw(sf::RenderWindow &window);
private:

};

#endif
