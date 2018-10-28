#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

#include <iostream>

#include "Tile.h"
#include "Grid.h"

void buttonPressed()
{
	std::cout << "Button pressed" << std::endl;
}

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "4th Year Project Simon Dowling C00190305");
	tgui::Gui gui(*window);
	Tile t("grass");
	tgui::Button::Ptr button = tgui::Button::create("Start");
	button->setSize(300, 50);
	button->setPosition((window->getSize().x / 2) - 150, (window->getSize().y / 2) - 25);
	gui.add(button);
	button->connect("Pressed", buttonPressed);

	Grid* g = new Grid(32, 32, "wall");
	

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

			gui.handleEvent(event);
		}

		

		window->clear();

		for (int i = 0; i < g->getWidth(); i++)
		{
			for (int j = 0; j < g->getHeight(); j++)
			{
				g->getTileArray()[i][j].draw(*window);
			}
		}

		gui.draw();
		t.draw(*window);
		window->display();
	}

	return 0;
}