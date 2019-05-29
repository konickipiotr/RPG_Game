#pragma once
#include "Place.hpp"
#include "../TawernGame.hpp"
#include <vector>

class Eram :
	public Place
{
public:
	Eram();
	Eram(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	void displayMainMenu();
	void talkWithLord();
	void tawern();
	void tawrnQuest();

	Shop blacksmith;
	Shop armorer;
	Shop alchemy;
	Shop market;
	TawernGame tawernGame;
};

