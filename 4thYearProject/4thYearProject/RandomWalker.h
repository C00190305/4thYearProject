#pragma once
#ifndef RANDOMWALKER_H
#define RANDOMWALKER_H

#include "SFML/Graphics.hpp"
#include <Thor/Math.hpp>
#include "Grid.h"


//A RandomWalkAgent object used for randomly walking through a grid of tiles and carving out a level.
//Has no graphical representation.
class RandomWalker
{
public:
	RandomWalker();
	RandomWalker(Grid* g);
	void update();
private:
	sf::Vector2f m_pos;
	Grid* m_grid;
	const float CHANCE_TO_CHANGE_DIRECTION = 0.5f;
	const float CHANCE_TO_DESTROY = 0.05f;
	const float CHANCE_TO_SPAWN_NEW_AGENT = 0.05f;
};

#endif