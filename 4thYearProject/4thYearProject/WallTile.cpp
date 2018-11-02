#include "WallTile.h"
//X and Y positions
WallTile::WallTile(int x, int y)
{
	m_texture.loadFromFile("wall.png");
	m_sprite.setTexture(m_texture);
	m_pos = sf::Vector2f(x * 64, y * 64);
	m_sprite.setPosition(m_pos);
}

void WallTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}