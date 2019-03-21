#include <SFML/Graphics.hpp>

#include "TGUI/TGUI.hpp"


#include <iostream>

#include <string>

#include "Tile.h"
#include "Grid.h"
#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"
#include "Grid.h"

template <typename RETURN_TYPE, typename STRING_TYPE>
RETURN_TYPE parse_string(const STRING_TYPE& str) {
	std::stringstream buf;
	buf << str;
	RETURN_TYPE val;
	buf >> val;
	return val;
}


bool RWGenerated = false;
bool CAGenerated = false;
bool CombinationGenerated = false;

void generateRW(RandomWalkGenerator* rwg, const int maxWalkers, const float fillPercentage, const float chanceToChangeDirection, const float chanceToDestroyWalker, const float chanceToSpawnWalker)
{
	RWGenerated = false;
	std::cout << maxWalkers << std::endl;
	std::cout << fillPercentage << std::endl;
	std::cout << chanceToChangeDirection << std::endl;
	std::cout << chanceToDestroyWalker << std::endl;
	std::cout << chanceToSpawnWalker << std::endl;

	rwg->generate(maxWalkers, fillPercentage, chanceToChangeDirection, chanceToDestroyWalker, chanceToSpawnWalker);
	rwg->createTileArray();
	RWGenerated = true;
}



void generateCA(CellularAutomataGenerator* cag, int numSimulationSteps, int birthLimit, int deathLimit, float chanceStartAlive)
{
	CAGenerated = false;
	cag->generate(numSimulationSteps, birthLimit, deathLimit, chanceStartAlive);
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
	ebMaxWalkers->setText("10");
	gui.add(ebMaxWalkers);

	auto labelFillPercentage = tgui::Label::create("Fill Percentage:");
	labelFillPercentage->setPosition(0, 120);
	gui.add(labelFillPercentage);

	auto ebFillPercentage = tgui::EditBox::copy(ebMaxWalkers);
	ebFillPercentage->setPosition(185, 120);
	ebFillPercentage->setText("0.3f");
	gui.add(ebFillPercentage);

	auto labelChanceToChangeDirection = tgui::Label::create("Chance to change direction:");
	labelChanceToChangeDirection->setPosition(0, 140);
	gui.add(labelChanceToChangeDirection);

	auto ebChanceToChangeDirection = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToChangeDirection->setPosition(185, 140);
	ebChanceToChangeDirection->setText("0.2f");
	gui.add(ebChanceToChangeDirection);

	auto labelChanceToDestroy = tgui::Label::create("Chance to destroy walker:");
	labelChanceToDestroy->setPosition(0, 160);
	gui.add(labelChanceToDestroy);

	auto ebChanceToDestroyWalker = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToDestroyWalker->setPosition(185, 160);
	ebChanceToDestroyWalker->setText("0.1f");
	gui.add(ebChanceToDestroyWalker);

	auto labelChanceToSpawnNewWalker = tgui::Label::create("Chance to spawn walker:");
	labelChanceToSpawnNewWalker->setPosition(0, 180);
	gui.add(labelChanceToSpawnNewWalker);

	auto ebChanceToSpawnNewWalker = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceToSpawnNewWalker->setPosition(185, 180);
	ebChanceToSpawnNewWalker->setText("0.2f");
	gui.add(ebChanceToSpawnNewWalker);

	//ca

	auto labelSimSteps = tgui::Label::create("Simulation steps:");
	labelSimSteps->setPosition(320, 120);
	gui.add(labelSimSteps);

	auto ebSimSteps = tgui::EditBox::copy(ebMaxWalkers);
	ebSimSteps->setPosition(505, 120);
	ebSimSteps->setText("3");
	gui.add(ebSimSteps);

	auto labelBirthLimit = tgui::Label::create("Birth limit:");
	labelBirthLimit->setPosition(320, 140);
	gui.add(labelBirthLimit);

	auto ebBirthLimit = tgui::EditBox::copy(ebMaxWalkers);
	ebBirthLimit->setPosition(505, 140);
	ebBirthLimit->setText("4");
	gui.add(ebBirthLimit);

	auto labelDeathLimit = tgui::Label::create("Death limit:");
	labelDeathLimit->setPosition(320, 160);
	gui.add(labelDeathLimit);

	auto ebDeathLimit = tgui::EditBox::copy(ebMaxWalkers);
	ebDeathLimit->setPosition(505, 160);
	ebDeathLimit->setText("3");
	gui.add(ebDeathLimit);

	auto labelChanceStartAlive = tgui::Label::create("Chance to start alive:");
	labelChanceStartAlive->setPosition(320, 180);
	gui.add(labelChanceStartAlive);

	auto ebChanceStartAlive = tgui::EditBox::copy(ebMaxWalkers);
	ebChanceStartAlive->setPosition(505, 180);
	ebChanceStartAlive->setText("0.4f");
	gui.add(ebChanceStartAlive);

	auto buttonGenerateRandomWalk = tgui::Button::create("Generate");
	buttonGenerateRandomWalk->setSize(100, 20);
	buttonGenerateRandomWalk->setPosition(100, 220);
	gui.add(buttonGenerateRandomWalk);

	auto buttonGenerateCellularAutomata = tgui::Button::create("Generate");
	buttonGenerateCellularAutomata->setSize(100, 20);
	buttonGenerateCellularAutomata->setPosition(320, 220);
	gui.add(buttonGenerateCellularAutomata);
	

	CellularAutomataGenerator cellularAutomataGenerator(30, 30, 3);

	//cellularAutomataGenerator.generate();

	RandomWalkGenerator randomWalkGenerator(30, 30);
	//randomWalkGenerator.generate(10, 0.3f, 0.2f, 0.1f, 0.2f);
	//randomWalkGenerator.createTileArray();

	Grid* grid = new Grid(&randomWalkGenerator, &cellularAutomataGenerator, 15, 15);
	//grid->generate();
	//grid->createTiles();

	//std::cout << ebMaxWalkers->getText().toUtf8() << std::endl;


	buttonGenerateRandomWalk->connect("pressed", generateRW, &randomWalkGenerator,
		parse_string<int>(ebMaxWalkers->getText().toAnsiString()),
		parse_string<float>(ebFillPercentage->getText().toAnsiString()),
		parse_string<float>(ebChanceToChangeDirection->getText().toAnsiString()),
		parse_string<float>(ebChanceToDestroyWalker->getText().toAnsiString()),
		parse_string<float>(ebChanceToSpawnNewWalker->getText().toAnsiString()));

	buttonGenerateCellularAutomata->connect("pressed", generateCA, &cellularAutomataGenerator,
		parse_string<int>(ebSimSteps->getText().toAnsiString()),
		parse_string<int>(ebBirthLimit->getText().toAnsiString()),
		parse_string<int>(ebDeathLimit->getText().toAnsiString()),
		parse_string<float>(ebChanceStartAlive->getText().toAnsiString()));



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

		if (CAGenerated == true)
		{
			cellularAutomataGenerator.draw(*window);
		}

		gui.draw();
		window->display();
	}

	return 0;
}