#include "RandomWalker.h"

RandomWalker::RandomWalker()
{

}

RandomWalker::RandomWalker(sf::Vector2i initialPos) : m_pos(initialPos)
{
	//Initialize direction to be a random direction
	m_direction = getNewDirection();
}

//Return a random cardinal direction in vector2 form.
sf::Vector2i RandomWalker::getNewDirection()
{
	float result = thor::random(0.0f, 3.99f);

	if (result <= 1.0f)
	{
		return sf::Vector2i(1, 0); //East
	}

	else if (result > 1.0f && result <= 2.0f)
	{
		return sf::Vector2i(-1, 0); //West
	}

	else if (result > 2.0f && result <= 3.0f)
	{
		return sf::Vector2i(0, 1); //South
	}

	else
	{
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
	//move integer position
	m_pos.x += (m_direction.x);
	m_pos.y += (m_direction.y);
}