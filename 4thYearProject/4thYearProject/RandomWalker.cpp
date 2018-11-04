#include "RandomWalker.h"

RandomWalker::RandomWalker()
{

}

RandomWalker::RandomWalker(sf::Vector2i initialPos) : m_pos(initialPos)
{
	m_direction = getDirection();
}

//Return a random cardinal direction in vector2 form.
sf::Vector2i RandomWalker::getDirection()
{
	int result = thor::random(1, 4);

	switch (result)
	{
		case 1:
			return sf::Vector2i(1, 0); //East
		case 2:
			return sf::Vector2i(-1, 0); //West
		case 3:
			return sf::Vector2i(0, 1); //South
		case 4:
			return sf::Vector2i(0, -1); //North
	}
}

void RandomWalker::setDirection(sf::Vector2i dir)
{
	m_direction = dir;
}

sf::Vector2i RandomWalker::getPosition()
{
	return m_pos;
}

void RandomWalker::move()
{
	m_pos.x += (m_direction.x);
	m_pos.y += (m_direction.y);
}