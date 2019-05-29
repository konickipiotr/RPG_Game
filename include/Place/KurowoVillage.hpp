#pragma once
#include "Place.hpp"
#include <vector>
#include <memory>


typedef std::shared_ptr<Quest> sQ;
class KurowoVillage :
	public Place
{
public:
	KurowoVillage(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt);
	virtual void displayMainMenu();
	void TalkWithMayor();
	void TalkAboutWorld();
	void work();
	void isQuestComplite();
private:
	std::vector<sQ> kurowQuests{};
	Shop herb;
};

