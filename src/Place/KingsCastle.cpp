#include "KingsCastle.hpp"



KingsCastle::KingsCastle()
{
}

KingsCastle::KingsCastle(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
	armorer = Shop(&player, " Zbrojmistrz ", ItemType::Armor, 2);
	blacksmith = Shop(&player, " Kowal ", ItemType::Weapon, 2);
	alchemy = Shop(&player, " Alchemik ", ItemType::Mixture, 2);
	tawernGame = TawernGame(player);
}

void KingsCastle::displayMainMenu()
{
	std::vector<std::string> labels{ "Wyjdz z miasta" ,"Król", "Zbrojmistrz", "Kowal", "Alchemik", "Karczma" };
	int pos = -1;
	do
	{
		pos = GlobFunc::controlPanel(labels, " Zamek Królewski");
		switch (pos)
		{
		case 1: talkWithLord(); break;
		case 2: armorer.displayScreen(); break;
		case 3: blacksmith.displayScreen(); break;
		case 4: alchemy.displayScreen(); break;
		case 5: tawern(); break;
		default:
			break;
		}

	} while (pos != 0);
}

void KingsCastle::talkWithLord()
{
	if ((player->qdairy.checkstatus("main", 7) == QuestStatus::INACTIV)) {
		qt->m6();
		player->qdairy.completeMainQuest(6);
		drawmap->unlockMap(5);
		player->equi.backpack.removeItem("G³owa zombie      ");
	}
	if ((player->qdairy.checkstatus("main", 13) == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("main", 15) == QuestStatus::INACTIV)) {
		qt->m10();
		player->qdairy.completeMainQuest(14);
		player->qdairy.RewardForQuest(14);
		drawmap->unlockMap(12);
	}
}

void KingsCastle::tawern()
{
	std::vector<std::string> labels{ "Powrot","Zapytaj o wydarzenia","graj w kosci" };
	int x = 0;
	do
	{
		x = GlobFunc::controlPanel(labels, "Karczma");
		switch (x)
		{
		case 1:tawrnQuest(); break;
		case 2:tawernGame.startGame(); break;
		}


	} while (x != 0);
}

void KingsCastle::tawrnQuest()
{
	if (player->qdairy.checkstatus("castle1") == QuestStatus::TOREWARD) {
		completeQuestScreen("castle1");
		player->completeQuest("castle1");
	}

	if (player->qdairy.checkstatus("castle1") == QuestStatus::INACTIV) {
		qt->castle1();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("castle1");
			drawmap->unlockMap(3, "others");
		}
	}
	else if ((player->qdairy.checkstatus("castle1") == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("castle2") == QuestStatus::INACTIV)) {
		qt->castle2();
		player->qdairy.takeQuest("castle2");
		drawmap->unlockMap(4, "others");

	}
	else {
		qt->nomore();
	}
}
