#include "Tile.h"

Tile::Tile()
{

}

Tile::Tile(const std::string &tileID) : m_ID(tileID)
{
	m_texture.loadFromFile("dungeon_sheet.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(10, 10, 16, 16));
}

void Tile::draw(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}

