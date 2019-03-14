#include <SFML/Graphics.hpp>


#include <iostream>

#include "Tile.h"
#include "Grid.h"
#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"
#include "Grid.h"

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "4th Year Project Simon Dowling C00190305");



	CellularAutomataGenerator cellularAutomataGenerator(30, 30, 3);

	cellularAutomataGenerator.generate();

	RandomWalkGenerator randomWalkGenerator(30, 30);
	randomWalkGenerator.generate();

	Grid* grid = new Grid(&randomWalkGenerator, &cellularAutomataGenerator);
	grid->generate();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				window->close();
			}

		}

		

		window->clear();
		cellularAutomataGenerator.draw(*window);
		randomWalkGenerator.draw(*window);
		window->display();
	}

	return 0;
}