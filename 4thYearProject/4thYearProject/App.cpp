#include "App.h"

/// <summary>
/// Default constructor
/// </summary>

App::App()
{
	srand(time(0));

	m_floorTexture = new sf::Texture();
	m_wallTexture = new sf::Texture();
	
	m_floorTexture->loadFromFile("floor.png");
	m_wallTexture->loadFromFile("wall.png");

	m_RWGenerated = false;
	m_CAGenerated = false;
	m_gridGenerated = false;
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "4th Year Project Simon Dowling C00190305");
	m_gui = new tgui::Gui(*m_window);
	createUI();
}


/// <summary>
/// Deconstructor
/// </summary>
App::~App()
{
	
}



/// <summary>
/// Update loop for the application.
/// </summary>
void App::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	timeSinceLastUpdate = clock.restart();

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				m_window->close();
			}

			m_gui->handleEvent(event);
		}

		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			//Update call
			update(timeSinceLastUpdate.asMilliseconds());

			timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
	}
}



/// <summary>
/// Updates application.
/// </summary>
void App::update(sf::Int32 dt)
{


}



/// <summary>
/// Renders game entities.
/// </summary>
void App::render()
{
	m_window->clear(sf::Color(0, 125, 125, 255));

	if (m_RWGenerated == true)
	{
		m_randomWalkGenerator->draw(*m_window);
	}

	if (m_CAGenerated == true)
	{
		m_cellularAutomataGenerator->draw(*m_window);
	}

	m_gui->draw();

	m_window->display();
}

/// <summary>
/// Generates a random walk level based on input
/// </summary>
void App::generateRW(tgui::EditBox::Ptr ebMaxWalkers, tgui::EditBox::Ptr ebFillPercentage, tgui::EditBox::Ptr ebChanceToChangeDirection, tgui::EditBox::Ptr ebChanceToDestroyWalker, tgui::EditBox::Ptr ebChanceToSpawnNewWalker)
{
	m_randomWalkGenerator = std::make_shared<RandomWalkGenerator>(30, 30);
	m_randomWalkGenerator->generate(30, 300, parse_string<int>(ebMaxWalkers->getText().toAnsiString()),
		parse_string<float>(ebFillPercentage->getText().toAnsiString()),
		parse_string<float>(ebChanceToChangeDirection->getText().toAnsiString()),
		parse_string<float>(ebChanceToDestroyWalker->getText().toAnsiString()),
		parse_string<float>(ebChanceToSpawnNewWalker->getText().toAnsiString()));
	m_randomWalkGenerator->createTileArray(m_floorTexture, m_wallTexture);
	m_RWGenerated = true;
}

/// <summary>
/// Generates a cellular automata level based on input
/// </summary>
void App::generateCA(tgui::EditBox::Ptr ebNumSimulationSteps, tgui::EditBox::Ptr ebBirthLimit, tgui::EditBox::Ptr ebDeathLimit, tgui::EditBox::Ptr ebChanceStartAlive)
{
	m_cellularAutomataGenerator = std::make_shared<CellularAutomataGenerator>(30, 30, parse_string<int>(ebNumSimulationSteps->getText().toAnsiString()));
	m_cellularAutomataGenerator->generate(300, 300, parse_string<int>(ebNumSimulationSteps->getText().toAnsiString()),
		parse_string<int>(ebBirthLimit->getText().toAnsiString()),
		parse_string<int>(ebDeathLimit->getText().toAnsiString()),
		parse_string<float>(ebChanceStartAlive->getText().toAnsiString()));
	m_cellularAutomataGenerator->createTileArray(m_floorTexture, m_wallTexture);
	m_CAGenerated = true;
}

/// <summary>
/// Creates and allocates tgui UI objects.
/// </summary>
void App::createUI()
{
	//Random walk
	m_labelRW = tgui::Label::create("Random Walk Settings");
	m_labelRW->setPosition(0, 50);
	m_labelRW->setSize(200, 20);
	m_gui->add(m_labelRW);

	m_labelMaxWalkers = tgui::Label::create("Maximum Walkers:");
	m_labelMaxWalkers->setPosition(0, 100);
	m_gui->add(m_labelMaxWalkers);

	m_ebMaxWalkers = tgui::EditBox::create();
	m_ebMaxWalkers->setSize(60, 15);
	m_ebMaxWalkers->setPosition(185, 100);
	m_ebMaxWalkers->setText("10");
	m_gui->add(m_ebMaxWalkers);

	m_labelFillPercentage = tgui::Label::create("Fill Percentage:");
	m_labelFillPercentage->setPosition(0, 120);
	m_gui->add(m_labelFillPercentage);

	m_ebFillPercentage = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebFillPercentage->setPosition(185, 120);
	m_ebFillPercentage->setText("0.3f");
	m_gui->add(m_ebFillPercentage);

	m_labelChanceToChangeDirection = tgui::Label::create("Chance to change direction:");
	m_labelChanceToChangeDirection->setPosition(0, 140);
	m_gui->add(m_labelChanceToChangeDirection);

	m_ebChanceToChangeDirection = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebChanceToChangeDirection->setPosition(185, 140);
	m_ebChanceToChangeDirection->setText("0.2f");
	m_gui->add(m_ebChanceToChangeDirection);

	m_labelChanceToDestroyWalker = tgui::Label::create("Chance to destroy walker:");
	m_labelChanceToDestroyWalker->setPosition(0, 160);
	m_gui->add(m_labelChanceToDestroyWalker);

	m_ebChanceToDestroyWalker = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebChanceToDestroyWalker->setPosition(185, 160);
	m_ebChanceToDestroyWalker->setText("0.1f");
	m_gui->add(m_ebChanceToDestroyWalker);

	m_labelChanceToSpawnNewWalker = tgui::Label::create("Chance to spawn walker:");
	m_labelChanceToSpawnNewWalker->setPosition(0, 180);
	m_gui->add(m_labelChanceToSpawnNewWalker);

	m_ebChanceToSpawnNewWalker = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebChanceToSpawnNewWalker->setPosition(185, 180);
	m_ebChanceToSpawnNewWalker->setText("0.2f");
	m_gui->add(m_ebChanceToSpawnNewWalker);

	m_buttonGenerateRW = tgui::Button::create("Generate");
	m_buttonGenerateRW->setSize(100, 20);
	m_buttonGenerateRW->setPosition(100, 220);
	m_gui->add(m_buttonGenerateRW);

	m_buttonGenerateRW->connect("pressed", &App::generateRW,
	this,
	m_ebMaxWalkers,
	m_ebFillPercentage,
	m_ebChanceToChangeDirection,
	m_ebChanceToDestroyWalker,
	m_ebChanceToSpawnNewWalker);

	//Cellular Automata
	m_labelCA = tgui::Label::create("Cellular Automata Settings");
	m_labelCA->setPosition(320, 50);
	m_labelCA->setSize(200, 20);
	m_gui->add(m_labelCA);

	m_labelNumSimulationSteps = tgui::Label::create("Simulation steps:");
	m_labelNumSimulationSteps->setPosition(320, 120);
	m_gui->add(m_labelNumSimulationSteps);

	m_ebNumSimulationSteps = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebNumSimulationSteps->setPosition(505, 120);
	m_ebNumSimulationSteps->setText("3");
	m_gui->add(m_ebNumSimulationSteps);

	m_labelBirthLimit = tgui::Label::create("Birth limit:");
	m_labelBirthLimit->setPosition(320, 140);
	m_gui->add(m_labelBirthLimit);

	m_ebBirthLimit = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebBirthLimit->setPosition(505, 140);
	m_ebBirthLimit->setText("4");
	m_gui->add(m_ebBirthLimit);

	m_labelDeathLimit = tgui::Label::create("Death limit:");
	m_labelDeathLimit->setPosition(320, 160);
	m_gui->add(m_labelDeathLimit);

	m_ebDeathLimit = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebDeathLimit->setPosition(505, 160);
	m_ebDeathLimit->setText("3");
	m_gui->add(m_ebDeathLimit);

	m_labelChanceStartAlive = tgui::Label::create("Chance to start alive:");
	m_labelChanceStartAlive->setPosition(320, 180);
	m_gui->add(m_labelChanceStartAlive);

	m_ebChanceStartAlive = tgui::EditBox::copy(m_ebMaxWalkers);
	m_ebChanceStartAlive->setPosition(505, 180);
	m_ebChanceStartAlive->setText("0.4f");
	m_gui->add(m_ebChanceStartAlive);

	m_buttonGenerateCA = tgui::Button::create("Generate");
	m_buttonGenerateCA->setSize(100, 20);
	m_buttonGenerateCA->setPosition(320, 220);
	m_gui->add(m_buttonGenerateCA);

	m_buttonGenerateCA->connect("pressed", &App::generateCA, 
	this, 
	m_ebNumSimulationSteps, 
	m_ebBirthLimit, 
	m_ebDeathLimit, 
	m_ebChanceStartAlive);

}


/// <summary>
/// Gets numbers and their data types from strings
/// </summary>
template <typename RETURN_TYPE, typename STRING_TYPE>
RETURN_TYPE App::parse_string(const STRING_TYPE& str)
{
	std::stringstream buf;
	buf << str;
	RETURN_TYPE val;
	buf >> val;
	return val;
}