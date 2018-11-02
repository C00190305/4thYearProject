#include "FloorTile.h"

FloorTile::FloorTile()
{
	m_texture.loadFromFile("floor.png");
	m_sprite.setTexture(m_texture);
}

void FloorTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}