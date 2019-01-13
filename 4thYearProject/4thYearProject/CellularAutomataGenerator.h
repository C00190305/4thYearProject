#pragma once
#ifndef CELLULARAUTOMATAGENERATOR_H
#define CELLULARAUTOMATAGENERATOR_H

#include <vector>
#include <Thor/Math.hpp>
class CellularAutomataGenerator
{
public:
	CellularAutomataGenerator();
	CellularAutomataGenerator(int width, int height, int numberOfSimulationSteps);
	~CellularAutomataGenerator();
	void generate();
private:
	//Cells can be either alive or dead
	enum GridSpace
	{
		alive,
		dead
	};
	int m_width;
	int m_height;
	int m_numSimulationSteps;
	float m_chanceStartAlive;
	std::vector<std::vector<GridSpace*>> grid;
};

#endif

