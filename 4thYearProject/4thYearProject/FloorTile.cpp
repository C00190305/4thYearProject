#include "FloorTile.h"
//X and Y positions
FloorTile::FloorTile(int offsetX, int offsetY, int x, int y)
{
	m_texture.loadFromFile("floor.png");
	m_sprite.setTexture(m_texture);
	m_pos = sf::Vector2f(offsetX + (x * 8), offsetY + (y * 8));
	m_sprite.setPosition(m_pos);
	m_sprite.setScale(0.125f, 0.125f);
}

void FloorTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}