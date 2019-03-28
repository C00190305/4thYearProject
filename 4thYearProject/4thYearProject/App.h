#ifndef APP_H
#define APP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include "Thor/Resources.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>

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

	void generateGrid(tgui::EditBox::Ptr ebOverlapX, tgui::EditBox::Ptr ebOverlapY);

	void exportRW(tgui::EditBox::Ptr ebFileName);
	void exportCA(tgui::EditBox::Ptr ebFileName);
	void exportGrid(tgui::EditBox::Ptr ebFileName);

	void createUI();

	sf::RenderWindow* m_window;
	std::shared_ptr<RandomWalkGenerator> m_randomWalkGenerator;
	std::shared_ptr<CellularAutomataGenerator> m_cellularAutomataGenerator;
	std::shared_ptr<Grid> m_grid;
	sf::Texture* m_floorTexture;
	sf::Texture* m_wallTexture;

	//TGUI members
	tgui::Gui* m_gui;


	//RandomWalk tgui elements
	tgui::Label::Ptr m_labelRW;

	tgui::EditBox::Ptr m_ebMaxWalkers;
	tgui::Label::Ptr m_labelMaxWalkers;
	tgui::EditBox::Ptr m_ebFillPercentage;
	tgui::Label::Ptr m_labelFillPercentage;
	tgui::EditBox::Ptr m_ebChanceToChangeDirection;
	tgui::Label::Ptr m_labelChanceToChangeDirection;
	tgui::EditBox::Ptr m_ebChanceToDestroyWalker;
	tgui::Label::Ptr m_labelChanceToDestroyWalker;
	tgui::EditBox::Ptr m_ebChanceToSpawnNewWalker;
	tgui::Label::Ptr m_labelChanceToSpawnNewWalker;
	tgui::Button::Ptr m_buttonGenerateRW;
	tgui::Button::Ptr m_buttonExportRW;

	tgui::EditBox::Ptr m_ebRWFileName;
	tgui::Label::Ptr m_labelRWFileName;
	
	//CellularAutomata tgui elements
	tgui::Label::Ptr m_labelCA;

	tgui::EditBox::Ptr m_ebNumSimulationSteps;
	tgui::Label::Ptr m_labelNumSimulationSteps;
	tgui::EditBox::Ptr m_ebBirthLimit;
	tgui::Label::Ptr m_labelBirthLimit;
	tgui::EditBox::Ptr m_ebDeathLimit;
	tgui::Label::Ptr m_labelDeathLimit;
	tgui::EditBox::Ptr m_ebChanceStartAlive;
	tgui::Label::Ptr m_labelChanceStartAlive;
	tgui::Button::Ptr m_buttonGenerateCA;
	tgui::Button::Ptr m_buttonExportCA;

	tgui::EditBox::Ptr m_ebCAFileName;
	tgui::Label::Ptr m_labelCAFileName;


	//Grid tgui elements

	tgui::EditBox::Ptr m_ebOverlapPoint;
	tgui::EditBox::Ptr m_ebOverlapX;
	tgui::EditBox::Ptr m_ebOverlapY;
	tgui::Label::Ptr m_labelOverlapPoint;
	tgui::Label::Ptr m_labelOverlapSettings;
	tgui::Button::Ptr m_buttonGenerateGrid;
	tgui::Button::Ptr m_buttonExportGrid;

	tgui::EditBox::Ptr m_ebGridFileName;
	tgui::Label::Ptr m_labelGridFileName;

	//Generation flags
	bool m_RWGenerated;
	bool m_CAGenerated;
	bool m_gridGenerated;

};
#endif // !APP_H
