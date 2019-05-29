#include "Eram.hpp"

Eram::Eram()
{
}

Eram::Eram(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap,_qt)
{
	armorer = Shop(&player, " Zbrojmistrz ", ItemType::Armor, 2);
	blacksmith = Shop(&player, " Kowal ", ItemType::Weapon, 2);
	alchemy = Shop(&player, " Alchemik ", ItemType::Mixture, 3);
	market = Shop(&player, " Targ ", ItemType::Othres, 2);
	tawernGame = TawernGame(player);
}

void Eram::displayMainMenu()
{
	std::vector<std::string> labels{ "Wyjdz z miasta" ,"Œwi¹tynie", "Zbrojmistrz", "Kowal", "Alchemik","Targ", "Karczma" };
	int pos = -1;
	do
	{
		pos = GlobFunc::controlPanel(labels, " Miasto Eram");
		switch (pos)
		{
		case 1: talkWithLord(); break;
		case 2: armorer.displayScreen(); break;
		case 3: blacksmith.displayScreen(); break;
		case 4: alchemy.displayScreen(); break;
		case 5: market.displayScreen(); break;
		case 6: tawern(); break;
		default:
			break;
		}

	} while (pos != 0);
}

void Eram::talkWithLord()
{
	if ((player->qdairy.checkstatus("main", 8) == QuestStatus::INACTIV)) {
		qt->m7();
		player->qdairy.completeMainQuest(7);
		drawmap->unlockMap(6);
	}
	if ((player->qdairy.checkstatus("main", 14) == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("main", 16) == QuestStatus::INACTIV)) {
		qt->m11();
		player->qdairy.completeMainQuest(15);
		player->qdairy.RewardForQuest(15);
		drawmap->unlockMap(10);
	}


}

void Eram::tawern()
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

void Eram::tawrnQuest()
{
	if (player->qdairy.checkstatus("eram1") == QuestStatus::TOREWARD) {
		player->completeQuest("eram1");
		completeQuestScreen("eram1");

	}

	if (player->qdairy.checkstatus("arad2") == QuestStatus::INACTIV) {
		std::cout << "\n\t Czekam na dostawe przypraw z Arad. Sprawdz czy ju¿ zosta³y wys³ane" << std::endl;
		GlobFunc::key();
	}
	else if ((player->qdairy.checkstatus("arad2") == QuestStatus::CURR) &&
		(player->equi.backpack.findItem("Paczka przypraw   ",ItemType::Othres))) {
		completeQuestScreen("arad2");
		player->completeQuest("arad3");
		player->equi.backpack.removeItem("Paczka przypraw   ");

	}
	else if ((player->qdairy.checkstatus("arad2") == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("eram1") == QuestStatus::INACTIV)) {
		qt->eram();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("eram1");
			drawmap->unlockMap(5, "others");
			
		}
	}
	else {
		qt->nomore();
	}
}


