#include "App.h"

/// <summary>
/// Default constructor
/// </summary>

App::App()
{
	srand(time(0));
	m_RWGenerated = false;
	m_CAGenerated = false;
	m_gridGenerated = false;
	m_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "4th Year Project Simon Dowling C00190305");
	m_gui = new tgui::Gui(*m_window);
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
		}

		m_gui->handleEvent(event);

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
	m_window->clear();


	m_window->display();
}

/// <summary>
/// Generates a random walk level based on input
/// </summary>
void App::generateRW(tgui::EditBox::Ptr ebMaxWalkers, tgui::EditBox::Ptr ebFillPercentage, tgui::EditBox::Ptr ebChanceToChangeDirection, tgui::EditBox::Ptr ebChanceToDestroyWalker, tgui::EditBox::Ptr ebChanceToSpawnNewWalker)
{
	m_randomWalkGenerator = new RandomWalkGenerator(30, 30);
	m_randomWalkGenerator->generate(parse_string<int>(ebMaxWalkers->getText().toAnsiString()),
		parse_string<float>(ebFillPercentage->getText().toAnsiString()),
		parse_string<float>(ebChanceToChangeDirection->getText().toAnsiString()),
		parse_string<float>(ebChanceToDestroyWalker->getText().toAnsiString()),
		parse_string<float>(ebChanceToSpawnNewWalker->getText().toAnsiString()));
	m_RWGenerated = true;
}

/// <summary>
/// Generates a cellular automata level based on input
/// </summary>
void App::generateCA(tgui::EditBox::Ptr ebNumSimulationSteps, tgui::EditBox::Ptr ebBirthLimit, tgui::EditBox::Ptr ebDeathLimit, tgui::EditBox::Ptr ebChanceStartAlive)
{
	m_cellularAutomataGenerator = new CellularAutomataGenerator(30, 30, parse_string<int>(ebNumSimulationSteps->getText().toAnsiString()));
	m_cellularAutomataGenerator->generate(parse_string<int>(ebNumSimulationSteps->getText().toAnsiString()),
		parse_string<int>(ebBirthLimit->getText().toAnsiString()),
		parse_string<int>(ebDeathLimit->getText().toAnsiString()),
		parse_string<float>(ebChanceStartAlive->getText().toAnsiString()));
	m_CAGenerated = true;
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