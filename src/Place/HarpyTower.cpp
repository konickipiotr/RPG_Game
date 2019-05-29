#include "HarpyTower.hpp"



HarpyTower::HarpyTower(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
}

void HarpyTower::displayMainMenu()
{
	GlobFunc::clearScreean();
	cout << "\n\tPo pokonaniu Harpi, zaczynas przeszykiwa� wie�e\n\t W jednej z komnata, przypadkiem naciskarz wystajacy \n\tkamien ze �ciany i po chwili otwieraj� drzwi do tajemniczej \n\tkomnaty wype�nionej z�otem i kosztowno�ciami" << endl;
	GlobFunc::key();
	if (player->qdairy.checkstatus("castle2") == QuestStatus::CURR) {
		completeQuestScreen("castle2");
		player->completeQuest("castle2");
	}
	GlobFunc::clearScreean();
}
