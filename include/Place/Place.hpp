#pragma once
#include <vector>
#include "Player.hpp"
#include "DrawMap.hpp"
#include "QTexts.hpp"
#include "GlobFunc.hpp"
#include "reward.hpp"
#include "Shop.hpp"
#include "TawernGame.hpp"

class Place
{
public:
	Place();
	Place(Player * _player, std::string _idS, DrawMap * _drawmap, QTexts * _qt);
	virtual void displayMainMenu() = 0;
	void completeQuestScreen(std::string idS);
	void completeQuestScreen(int num);
	bool takedQuest();

protected:
	int controlPanel(const std::vector<std::string> & labels);

	Player * player;
	std::string idS;
	DrawMap * drawmap;
	QTexts * qt;
};

