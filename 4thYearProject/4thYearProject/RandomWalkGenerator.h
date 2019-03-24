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
	enum GridSpace
	{
		empty,
		floor,
		wall
	};
public:
	RandomWalkGenerator();
	RandomWalkGenerator(int width, int height);
	void generate(const int offsetX, const int offsetY, const int maxWalkers, const float fillPercentage, const float chanceToChangeDirection, const float chanceToDestroyWalker, const float chanceToSpawnWalker);
	void draw(sf::RenderWindow &window);
	int getWidth();
	int getHeight();
	std::vector<std::vector<int>> getData();
	void createTileArray();
private:

	Tile*** m_tileArray;
	std::vector<std::vector<Tile*>> m_tileVector;
	std::vector<std::vector<GridSpace>> m_gridSpaceVector;
	int m_width, m_height;
	GridSpace** m_gridSpace;
	std::list<RandomWalker*> m_walkers;
	int MAX_WALKERS = 10;
	float FILL_PERCENTAGE = 0.3f;
	float CHANCE_TO_CHANGE_DIRECTION = 0.2f;
	float CHANCE_TO_DESTROY = 0.1f;
	float CHANCE_TO_SPAWN_NEW_WALKER = 0.2f;
	sf::Vector2i m_roomSizeWorldUnits;

	int m_offsetX;
	int m_offsetY;

	void spawnNewWalker();
	void destroyWalker();
	void calculateNewDirection();
	int numberOfFloorsInGrid();
};

#endif // !RANDOMWALKGENERATOR_H
