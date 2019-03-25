#pragma once
#ifndef TILE_H
#define TILE_H
#include "SFML/Graphics.hpp"


class Tile
{
public:
	Tile();
	~Tile();
	Tile(const std::string &tileID);
	virtual void draw(sf::RenderWindow &window);
protected:
	sf::Sprite m_sprite;
	sf::Texture* m_texture;
	sf::Vector2f m_pos;
	std::string m_ID;
	int m_width;
	int m_height;
};


#endif
