#pragma once
#ifndef CELLULARAUTOMATAGENERATOR_H
#define CELLULARAUTOMATAGENERATOR_H

#include <vector>
#include <Thor/Math.hpp>
#include <iostream>

#include "Tile.h"
#include "WallTile.h"
#include "FloorTile.h"
class CellularAutomataGenerator
{
public:
	CellularAutomataGenerator();
	CellularAutomataGenerator(int width, int height, int numberOfSimulationSteps);
	~CellularAutomataGenerator();
	void generate(const int offsetX, const int offsetY, int numberOfSimulationSteps, int birthLimit, int deathLimit, float chanceStartAlive);
	void draw(sf::RenderWindow &window);

	int getWidth();
	int getHeight();
	std::vector<std::vector<int>> getData();
	void createTileArray();
private:
	//Cells can be either alive or dead
	enum GridSpace
	{
		alive,
		dead
	};

	int m_width;
	int m_height;
	int m_birthLimit;
	int m_deathLimit;
	int m_numSimulationSteps;
	float m_chanceStartAlive;

	int m_offsetX;
	int m_offsetY;
	std::vector<std::vector<GridSpace*>> grid;
	std::vector<std::vector<Tile*>> m_tileVector;

	auto doSimulationStep();
	int countAliveNeighbours(std::vector<std::vector<GridSpace*>> grid, int x,  int y);
	
};

#endif

