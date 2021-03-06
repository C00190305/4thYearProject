#include "Grid.h"


//Default constructor
Grid::Grid()
{

}

//\param randomWalkGenerator : pointer to RandomWalkGenerator
//\param cellularAutomataGenerator : pointer to CellularAutomataGenerator
Grid::Grid(std::shared_ptr<RandomWalkGenerator> randomWalkGenerator, std::shared_ptr<CellularAutomataGenerator> cellularAutomataGenerator, int overlapX, int overlapY) : m_index_X(overlapX), m_index_Y(overlapY)
{
	//Store pointers to generators
	m_pCellularAutomataGenerator = cellularAutomataGenerator;
	m_pRandomWalkGenerator = randomWalkGenerator;

	//Calculate overall width and height
	m_width = randomWalkGenerator->getWidth() + cellularAutomataGenerator->getWidth();
	m_height = randomWalkGenerator->getHeight() + cellularAutomataGenerator->getHeight();

	//Reserve memory for containers
	m_dataVector.resize(m_height);
	for (int i = 0; i < m_dataVector.size(); i++)
	{
		m_dataVector[i].resize(m_width);
	}

	m_tileVector.resize(m_height);
	m_tileVector.reserve(m_height);
	for (int i = 0; i < m_tileVector.size(); i++)
	{
		m_tileVector[i].resize(m_height);
		m_tileVector[i].reserve(m_height);
	}
}

void Grid::generate(int offsetX, int offsetY)
{
	//Assign variables based on user-defined input
	m_offsetX = offsetX;
	m_offsetY = offsetY;

	//Get information from both generators and put into m_dataVector, which has been allocated space for both.
	for (int i = 0; i < m_pRandomWalkGenerator->getHeight(); i++)
	{
		for (int j = 0; j < m_pRandomWalkGenerator->getWidth(); j++)
		{
			m_dataVector[i].at(j) = m_pRandomWalkGenerator->getData()[i].at(j);
		}
	}

	for (int i = m_index_X; i < m_index_X + m_pCellularAutomataGenerator->getWidth(); i++)
	{
		for (int j = m_index_Y; j < m_index_Y + m_pCellularAutomataGenerator->getHeight(); j++)
		{
			m_dataVector[i].at(j) = m_pCellularAutomataGenerator->getData()[i - m_index_X].at(j - m_index_Y);

			//if (m_pCellularAutomataGenerator->getData()[i - m_index_X].at(j - m_index_Y) == 0 && m_pRandomWalkGenerator->getData()[i].at(j) == 1)
			//{
			//	m_dataVector[i].at(j) = 1;
			//}
		}
	}
}

void Grid::createTiles(sf::Texture* floorTexture, sf::Texture* wallTexture)
{
	m_tileVector.clear();

	m_tileVector.resize(m_height);
	m_tileVector.reserve(m_height);
	for (int i = 0; i < m_tileVector.size(); i++)
	{
		m_tileVector[i].resize(m_height);
		m_tileVector[i].reserve(m_height);
	}

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (m_dataVector[i].at(j) == 1)
			{
				m_tileVector[i].at(j) = new WallTile(wallTexture, m_offsetX, m_offsetY, i, j);
			}

			if (m_dataVector[i].at(j) == 0)
			{
				m_tileVector[i].at(j) = new FloorTile(floorTexture, m_offsetX, m_offsetY, i, j);
			}
		}
	}

}

void Grid::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_tileVector[i].at(j)->draw(window);
		}
	}
}

int Grid::getWidth()
{
	return m_width;
}

int Grid::getHeight()
{
	return m_height;
}

std::vector<std::vector<int>> Grid::getData()
{
	return m_dataVector;
}