#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
#include <vector>

#include "RandomWalkGenerator.h"
#include "CellularAutomataGenerator.h"
#include "Grid.h"

class App
{
public:
	App();
	~App();
	void run();


private:
	void update(sf::Int32 dt);
	void render();

	template <typename RETURN_TYPE, typename STRING_TYPE>
	RETURN_TYPE parse_string(const STRING_TYPE& str);
	void generateRW(tgui::EditBox::Ptr ebMaxWalkers,
					tgui::EditBox::Ptr ebFillPercentage,
					tgui::EditBox::Ptr ebChanceToChangeDirection,
					tgui::EditBox::Ptr ebChanceToDestroyWalker,
					tgui::EditBox::Ptr ebChanceToSpawnNewWalker);

	void generateCA(tgui::EditBox::Ptr ebNumSimulationSteps, 
					tgui::EditBox::Ptr ebBirthLimit, 
					tgui::EditBox::Ptr ebDeathLimit, 
					tgui::EditBox::Ptr ebChanceStartAlive);

	sf::RenderWindow* m_window;
	RandomWalkGenerator* m_randomWalkGenerator;
	CellularAutomataGenerator* m_cellularAutomataGenerator;
	Grid* m_grid;

	//TGUI members
	tgui::Gui* m_gui;
	tgui::EditBox::Ptr ebMaxWalkers;
	tgui::EditBox::Ptr ebFillPercentage;
	tgui::EditBox::Ptr ebChanceToChangeDirection;
	tgui::EditBox::Ptr ebChanceToDestroyWalker;
	tgui::EditBox::Ptr ebChanceToSpawnNewWalker;

	//Generation flags
	bool m_RWGenerated;
	bool m_CAGenerated;
	bool m_gridGenerated;

};
#endif // !APP_H
