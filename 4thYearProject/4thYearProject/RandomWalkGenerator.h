#pragma once
#ifndef RANDOMWALKGENERATOR_H
#define RANDOMWALKGENERATOR_H

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

#include "Tile.h"
#include "FloorTile.h"
#include "WallTile.h"
#include "RandomWalker.h"
#include <Thor/Math.hpp>

class RandomWalker;

class RandomWalkGenerator
{
public:
	RandomWalkGenerator();
	RandomWalkGenerator(int width, int height);
	void generate();
	void draw(sf::RenderWindow &window);
	int getWidth();
	int getHeight();
private:

	
	enum GridSpace
	{
		empty,
		floor,
		wall
	};

	Tile*** m_tileArray;
	std::vector<std::vector<Tile*>> m_tileVector;
	std::vector<std::vector<GridSpace>> m_gridSpaceVector;
	int m_width, m_height;
	GridSpace** m_gridSpace;
	std::list<RandomWalker*> m_walkers;
	const int MAX_WALKERS = 10;
	const float FILL_PERCENTAGE = 0.3f;
	const float CHANCE_TO_CHANGE_DIRECTION = 0.2f;
	const float CHANCE_TO_DESTROY = 0.1f;
	const float CHANCE_TO_SPAWN_NEW_WALKER = 0.2f;
	sf::Vector2i m_roomSizeWorldUnits;

	void spawnNewWalker();
	void destroyWalker();
	void calculateNewDirection();
	int numberOfFloorsInGrid();
	void createTileArray();
};

#endif // !RANDOMWALKGENERATOR_H
