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
	RandomWalker(sf::Vector2i initialPos);
	void update();
	sf::Vector2i getDirection();
	void setDirection(sf::Vector2i dir);
	sf::Vector2i getPosition();
	void move();
private:
	sf::Vector2i m_pos;
	sf::Vector2i m_direction;
};

#endif