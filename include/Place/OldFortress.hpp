#pragma once
#include "Place.hpp"
#include "../Items/IOthers.hpp"

class OldFortress :
	public Place
{
public:
	OldFortress();
	OldFortress(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
};

