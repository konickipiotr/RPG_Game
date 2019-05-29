#include "HadikVillage.hpp"



HadikVillage::HadikVillage()
{
	
}

HadikVillage::HadikVillage(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
	herb = Shop(&_player, "Zielarka", ItemType::Mixture, 1);
}

void HadikVillage::displayMainMenu()
{
	std::vector<std::string> labels{ "Opusc wies" ,"Porozmawiaj z wojtem", "Odwiedz zielarke" };
	int pos = -1;
	do
	{
		pos = GlobFunc::controlPanel(labels, "Wies Kurowo");
		switch (pos)
		{
		case 1: work();
			break;
		case 2: herb.displayScreen();
			break;
		default:
			break;
		}

	} while (pos != 0);
}

void HadikVillage::work()
{
	isQuestComplite();
	if (player->qdairy.checkstatus("hadik") == QuestStatus::INACTIV) {
		qt->hadi();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("hadik");
			drawmap->unlockMap(6, "others");
		}
	}
	else {
		qt->nomore();
	}
}

void HadikVillage::isQuestComplite()
{
	if (player->qdairy.checkstatus("hadik") == QuestStatus::TOREWARD) {
		completeQuestScreen("hadik");
		player->completeQuest("hadik");
	}
}

