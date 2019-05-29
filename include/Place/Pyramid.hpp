#pragma once
#include "Place.hpp"
#include "Helmet.hpp"
#include "Armor.hpp"
#include "Boots.hpp"
#include "Pants.hpp"

class Pyramid :
	public Place
{
public:
	Pyramid();
	Pyramid(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
};

