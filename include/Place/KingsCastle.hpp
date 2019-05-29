#pragma once
#include "Place.hpp"
#include <vector>

class KingsCastle :
	public Place
{
public:
	KingsCastle();
	KingsCastle(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);

	void displayMainMenu();
	void talkWithLord();
	void tawern();
	void tawrnQuest();


	Shop blacksmith;
	Shop armorer;
	Shop alchemy;
	TawernGame tawernGame;
};

