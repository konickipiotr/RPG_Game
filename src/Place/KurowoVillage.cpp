#include "KurowoVillage.hpp"

KurowoVillage::KurowoVillage(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
	herb = Shop(&_player, "Zielarka", ItemType::Mixture, 1);
}

void KurowoVillage::displayMainMenu()
{
	std::vector<std::string> labels{ "Opusc wies" ,"Porozmawiaj z wojtem", "Odwiedz zielarke" };
	int pos = -1;
	do
	{
		pos = GlobFunc::controlPanel(labels, "Wies Kurowo");
		switch (pos)
		{
		case 1: TalkWithMayor();
			break;
		case 2: herb.displayScreen();
			break;
		default:
			break;
		}

	} while (pos != 0);
}

void KurowoVillage::TalkWithMayor()
{
	std::vector<std::string> labels{ "Powrot" ,"Czy znajdzie sie tu jakas praca?", "Czy mozesz mi cos opowiedziec o okolicy?" };
	int pos = -1;
	isQuestComplite();
	do
	{
		pos = GlobFunc::controlPanel(labels, "WOJT");
		switch (pos)
		{
		case 1: work();
			break;
		case 2: {
			TalkAboutWorld();
			player->qdairy.completeMainQuest(0);
			drawmap->unlockMap(1);
		}
			break;
		default:
			break;
		}

	} while (pos != 0);
}

void KurowoVillage::TalkAboutWorld()
{
	qt->m2();
}

void KurowoVillage::work()
{
	
	if (player->qdairy.checkstatus("kur1") == QuestStatus::INACTIV) {
		qt->kur1();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("kur1");
			drawmap->unlockMap(0, "others");
		}
	}
	else if ((player->qdairy.checkstatus("kur1") == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("kur2") == QuestStatus::INACTIV)) {
		qt->kur2();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("kur2");
			drawmap->unlockMap(1, "others");
		}
	}
	else if ((player->qdairy.checkstatus("kur2") == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("kur3") == QuestStatus::INACTIV)) {
		qt->kur3();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("kur3");
		}
	}
	else {
		qt->nomore();
	}

}


void KurowoVillage::isQuestComplite()
{
	if (player->qdairy.checkstatus("kur1") == QuestStatus::TOREWARD) {
		completeQuestScreen("kur1");
		player->completeQuest("kur1");
	}
	if (player->qdairy.checkstatus("kur2") == QuestStatus::TOREWARD) {
		player->completeQuest("kur2");
		completeQuestScreen("kur2");
	}
	if (player->equi.backpack.findItem("Gwo�dzie          ", ItemType::Othres)) {
		player->completeQuest("kur3");
		completeQuestScreen("kur3");
		player->equi.backpack.removeItem("Gwo�dzie          ");
	}


}
