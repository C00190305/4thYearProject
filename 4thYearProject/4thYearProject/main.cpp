#include <SFML/Graphics.hpp>

#include "TGUI/TGUI.hpp"


#include <iostream>

#include "Tile.h"
#include "Grid.h"
#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"
#include "Grid.h"


bool RWGenerated = false;
bool CAGenerated = false;
bool CombinationGenerated = false;

void generateRW(RandomWalkGenerator* rwg)
{
	RWGenerated = false;
	rwg->generate();
	rwg->createTileArray();
	RWGenerated = true;
}

void generateCA(CellularAutomataGenerator* cag)
{
	CAGenerated = false;
	cag->generate();
	cag->createTileArray();
	CAGenerated = true;
}

int main()
{
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1280, 720), "4th Year Project Simon Dowling C00190305");
	tgui::Gui gui(*window);

	auto labelMaxWalkers = tgui::Label::create("Maximum Walkers:");
	labelMaxWalkers->setPosition(0, 100);
	gui.add(labelMaxWalkers);
	
	auto ebMaxWalkers = tgui::EditBox::create();
	ebMaxWalkers->setSize(60, 15);
	ebMaxWalkers->setPosition(185, 100);
	ebMaxWalkers->setDefaultText("10");
	gui.add(ebMaxWalkers);

	auto labelFillPercentage = tgui::Label::create("Fill Percentage:");
	labelFillPercentage->setPosition(0, 120);
	gui.add(labelFillPercentage);

	auto ebFillPercentage = tgui::EditBox::copy(ebMaxWalkers);
	ebFillPercentage->setPosition(185, 120);
	ebFillPercentage->setDefaultText("0.3");
	gui.add(ebFillPercentage);

	auto labelChanceToChangeDirection = tgui::Label::create("Chance to change direction:");
	labelChanceToChangeDirection->setPosition(0, 140);
	gui.add(labelChanceToChangeDirection);

	auto ebChanceToChangeDirection = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToChangeDirection->setPosition(185, 140);
	ebChanceToChangeDirection->setDefaultText("0.2");
	gui.add(ebChanceToChangeDirection);

	auto labelChanceToDestroy = tgui::Label::create("Chance to destroy walker:");
	labelChanceToDestroy->setPosition(0, 160);
	gui.add(labelChanceToDestroy);

	auto ebChanceToDestroyWalker = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToDestroyWalker->setPosition(185, 160);
	ebChanceToDestroyWalker->setDefaultText("0.1");
	gui.add(ebChanceToDestroyWalker);

	auto labelChanceToSpawnNewWalker = tgui::Label::create("Chance to spawn walker:");
	labelChanceToSpawnNewWalker->setPosition(0, 180);
	gui.add(labelChanceToSpawnNewWalker);

	auto ebChanceToSpawnNewWalker = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToSpawnNewWalker->setPosition(185, 180);
	ebChanceToSpawnNewWalker->setDefaultText("0.2");
	gui.add(ebChanceToSpawnNewWalker);

	auto buttonGenerateRandomWalk = tgui::Button::create("Generate");
	buttonGenerateRandomWalk->setSize(100, 20);
	buttonGenerateRandomWalk->setPosition(100, 220);
	gui.add(buttonGenerateRandomWalk);
	


	CellularAutomataGenerator cellularAutomataGenerator(30, 30, 3);

	//cellularAutomataGenerator.generate();

	RandomWalkGenerator randomWalkGenerator(30, 30);
	//randomWalkGenerator.generate();

	Grid* grid = new Grid(&randomWalkGenerator, &cellularAutomataGenerator, 15, 15);
	//grid->generate();
	//grid->createTiles();

	buttonGenerateRandomWalk->connect("pressed", generateRW, &randomWalkGenerator);

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

		

		window->clear(sf::Color(0, 125, 125, 255));
		//grid->draw(*window);
		if (RWGenerated == true)
		{
			randomWalkGenerator.draw(*window);
		}
		gui.draw();
		window->display();
	}

	return 0;
}