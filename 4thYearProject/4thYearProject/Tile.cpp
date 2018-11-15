#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(const std::string &tileID) : m_ID(tileID)
{

}

void Tile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

