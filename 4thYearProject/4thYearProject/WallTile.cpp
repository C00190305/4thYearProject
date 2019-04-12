#include "WallTile.h"
WallTile::~WallTile()
{
}
//X and Y positions
WallTile::WallTile(sf::Texture* texture, int offsetX, int offsetY, int x, int y)
{
	m_texture = texture;
	m_sprite.setTexture(*m_texture);
	m_pos = sf::Vector2f(offsetX + (x * 8), offsetY + (y * 8));
	m_sprite.setPosition(m_pos);
	m_sprite.setScale(0.125, 0.125f);
}

void WallTile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}