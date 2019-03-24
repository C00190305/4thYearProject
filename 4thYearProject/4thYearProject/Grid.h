#pragma once
#ifndef GRID_H
#define GRID_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Tile.h"
#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"

//Class that controls the collective of all generator object's data structures.
class RandomWalkGenerator;
class CellularAutomataGenerator;

class Grid
{
public:
	Grid();
	Grid(RandomWalkGenerator* randomWalkGenerator, CellularAutomataGenerator* cellularAutomataGenerator, int overlapX, int overlapY);
	int getWidth();
	int getHeight();
	std::vector<std::vector<int>> getData();
	void generate(int offsetX, int offsetY);
	void createTiles();
	void draw(sf::RenderWindow &window);
private:
	CellularAutomataGenerator* m_pCellularAutomataGenerator;
	RandomWalkGenerator* m_pRandomWalkGenerator;
	int m_width;
	int m_height;
	int m_index_X, m_index_Y;
	int m_offsetX;
	int m_offsetY;
	std::vector<std::vector<int>> m_dataVector;
	std::vector <std::vector<Tile*>> m_tileVector;
};

#endif // !GRID_H

