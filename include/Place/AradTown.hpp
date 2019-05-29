#pragma once
#include "Place.hpp"
#include <vector>
#include "../GlobFunc.hpp"
#include "../Shop.hpp"
#include "../TawernGame.hpp"

class AradTown :
	public Place
{
public:

	AradTown();
	AradTown(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	~AradTown();

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

