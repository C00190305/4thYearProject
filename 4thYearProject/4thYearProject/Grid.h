#pragma once
#ifndef GRID_H
#define GRID_H

#include <vector>
#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"

//Class that controls the collective of all generator object's data structures.
class RandomWalkGenerator;
class CellularAutomataGenerator;

class Grid
{
public:
	Grid();
	Grid(const int &width1, const int &height1, const int &width2, const int &height2, const int &x1, const int &y1, const int &x2, const int &y2);
	Grid(RandomWalkGenerator* randomWalkGenerator, CellularAutomataGenerator* cellularAutomataGenerator);
	int getWidth();
	int getHeight();
	std::vector<std::vector<int>> getData();
	void generate();
private:
	CellularAutomataGenerator* m_pCellularAutomataGenerator;
	RandomWalkGenerator* m_pRandomWalkGenerator;
	int m_width;
	int m_height;
	int m_x1, m_y1, m_x2, m_y2;
	std::vector<std::vector<int>> m_dataVector;
};

#endif // !GRID_H

