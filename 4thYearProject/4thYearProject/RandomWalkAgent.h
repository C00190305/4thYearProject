#pragma once
#ifndef RANDOMWALKAGENT_H
#define RANDOMWALKAGENT_H

#include "SFML/Graphics.hpp"
#include <Thor/Math.hpp>
#include "Grid.h"


//A RandomWalkAgent object used for randomly walking through a grid of tiles and carving out a level.
//Has no graphical representation.
class RandomWalkAgent
{
public:
	RandomWalkAgent();
	RandomWalkAgent(Grid* g);
	void update();
private:
	sf::Vector2f m_pos;
	Grid* m_grid;
	float chanceToChangeDirection;
	float chanceToDestroy;
	float chanceToSpawnNewAgent;
};

#endif