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
	void generate();
	void draw(sf::RenderWindow &window);

	int getWidth();
	int getHeight();
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
	std::vector<std::vector<GridSpace*>> grid;
	std::vector<std::vector<Tile*>> m_tileVector;

	auto doSimulationStep();
	int countAliveNeighbours(std::vector<std::vector<GridSpace*>> grid, int x,  int y);
	void createTileArray();	
	
};

#endif

