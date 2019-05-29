#pragma once
#include "Place.hpp"
#include "Player.hpp"
class HarpyTower :
	public Place
{
public:
	HarpyTower(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
};

