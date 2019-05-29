#pragma once
#include "Place.hpp"
class Labyrinth :
	public Place
{
public:
	Labyrinth();
	Labyrinth(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
	void fakeLab();
	void fakeLab(bool & found);
	void DeadEnd();
	void goodWay(bool & found);
	void graf();
};

