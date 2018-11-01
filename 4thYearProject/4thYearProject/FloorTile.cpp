#include "FloorTile.h"

FloorTile::FloorTile()
{
	m_texture.loadFromFile("floor.png");
	m_sprite.setTexture(m_texture);
}