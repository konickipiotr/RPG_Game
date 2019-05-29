#pragma once
#include "Place.hpp"
class MagTower :
	public Place
{
public:
	MagTower();
	MagTower(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
};

