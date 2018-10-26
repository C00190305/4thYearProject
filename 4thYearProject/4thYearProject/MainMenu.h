#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
	MainMenu();
	MainMenu(sf::RenderWindow* window);
private:
	tgui::Gui* m_gui;
	tgui::Button::Ptr m_randomWalkButton;
	tgui::Button::Ptr m_bspButton;
	tgui::Button::Ptr m_cellularAutomataButton;
	sf::RenderWindow* m_window;
};

#endif