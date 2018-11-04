#include "FloorTile.h"
//X and Y positions
FloorTile::FloorTile(int x, int y)
{
	m_texture.loadFromFile("floor.png");
	m_sprite.setTexture(m_texture);
	m_pos = sf::Vector2f(x * 64, y * 64);
	m_sprite.setPosition(m_pos);
}

void FloorTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}