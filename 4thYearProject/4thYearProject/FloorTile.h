#pragma once
#ifndef FLOORTILE_H
#define FLOORTILE_H


#include "Tile.h"

class FloorTile : public Tile
{
public:
	FloorTile();
	void draw(sf::RenderWindow &window);
private:

};

#endif
