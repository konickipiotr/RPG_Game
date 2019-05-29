#include "MagTower.hpp"

MagTower::MagTower()
{
}

MagTower::MagTower(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap,_qt)
{
}

void MagTower::displayMainMenu()
{
	GlobFunc::clearScreean();
	if ((player->qdairy.checkstatus("main", 9) == QuestStatus::INACTIV)) {
		qt->m8();
		player->qdairy.completeMainQuest(8);
		drawmap->unlockMap(7);
	}
	if ((player->qdairy.checkstatus("main", 9) == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("main", 11) == QuestStatus::INACTIV)) {
		qt->m85();
		player->qdairy.completeMainQuest(10);
		drawmap->unlockMap(8);
		player->equi.backpack.removeItem("Stary zw�j        ");
	}
	if ((player->qdairy.checkstatus("main", 12) == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("main", 14) == QuestStatus::INACTIV)) {
		qt->m9();
		player->qdairy.completeMainQuest(13);
	}
	GlobFunc::clearScreean();
}

