#include "FloorTile.h"
//X and Y positions
FloorTile::FloorTile(int x, int y)
{
	m_texture.loadFromFile("floor.png");
	m_sprite.setTexture(m_texture);
	m_pos = sf::Vector2f(x * 6.4, y * 6.4);
	m_sprite.setPosition(m_pos);
	m_sprite.setScale(0.1f, 0.1f);
}

void FloorTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}