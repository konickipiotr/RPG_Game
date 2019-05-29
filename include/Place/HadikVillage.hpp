#pragma once
#include "Place.hpp"
#include <vector>

class HadikVillage :
	public Place
{
public:
	HadikVillage();
	HadikVillage(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	virtual void displayMainMenu();
	void work();
	void isQuestComplite();
private:
	std::vector<sQ> kurowQuests{};
	Shop herb;
};

