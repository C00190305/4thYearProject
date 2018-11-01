#pragma once
#ifndef RANDOMWALKGENERATOR_H
#define RANDOMWALKGENERATOR_H

#include <vector>

#include "Tile.h"
#include "RandomWalker.h"

class RandomWalkGenerator
{
public:
	RandomWalkGenerator();
	RandomWalkGenerator(int width, int height);
	void draw(sf::RenderWindow &window);
private:
	Tile** m_tileArray;
	int m_width, m_height;
	
	enum GridSpace
	{
		empty,
		floor,
		wall
	};

	GridSpace** m_gridSpace;
	std::vector<RandomWalker*> m_rwAgents;
	const int maxWalkers = 10;
};

#endif // !RANDOMWALKGENERATOR_H
