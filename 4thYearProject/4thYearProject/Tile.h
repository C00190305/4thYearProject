#pragma once
#ifndef TILE_H
#define TILE_H
#include "SFML/Graphics.hpp"


class Tile
{
public:
	Tile();
	Tile(const std::string &tileID);
	void draw(sf::RenderWindow &window);
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_pos;
	std::string m_ID;
};


#endif
