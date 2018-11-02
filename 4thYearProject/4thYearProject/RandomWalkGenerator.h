#pragma once
#ifndef RANDOMWALKGENERATOR_H
#define RANDOMWALKGENERATOR_H

#include <vector>
#include <list>

#include "Tile.h"
#include "RandomWalker.h"
#include <Thor/Math.hpp>

class RandomWalkGenerator
{
public:
	RandomWalkGenerator();
	RandomWalkGenerator(int width, int height);
	void generate();
	void draw(sf::RenderWindow &window);
private:

	
	enum GridSpace
	{
		empty,
		floor,
		wall
	};

	Tile** m_tileArray;
	int m_width, m_height;
	GridSpace** m_gridSpace;
	std::list<RandomWalker*> m_walkers;
	const int MAX_WALKERS = 10;
	const float FILL_PERCENTAGE = 0.2f;
	const float CHANCE_TO_CHANGE_DIRECTION = 0.5f;
	const float CHANCE_TO_DESTROY = 0.05f;
	const float CHANCE_TO_SPAWN_NEW_WALKER = 0.05f;
	sf::Vector2i m_roomSizeWorldUnits;

	void spawnNewWalker();
	void destroyWalker();
	void calculateNewDirection();
};

#endif // !RANDOMWALKGENERATOR_H
