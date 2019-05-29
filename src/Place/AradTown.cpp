#include "AradTown.hpp"

AradTown::AradTown()
{
}

AradTown::AradTown(Player * _player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap,_qt)
{
	armorer = Shop(&player, " Zbrojmistrz ", ItemType::Armor, 1);
	blacksmith = Shop(&player, " Kowal ", ItemType::Weapon, 1);
	alchemy = Shop(&player, " Alchemik ", ItemType::Mixture, 1);
	market = Shop(&player, " Targ ", ItemType::Othres, 1);
	tawernGame = TawernGame(player);
}

AradTown::~AradTown()
{
}

void AradTown::displayMainMenu()
{
	std::vector<std::string> labels{ "Wyjdz z miasta" ,"Lord Arison", "Zbrojmistrz", "Kowal", "Alchemik","Targ", "Karczma"};
	int pos = -1;
	do
	{
		pos = GlobFunc::controlPanel(labels, " Miasto Arad");
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

void AradTown::talkWithLord()
{
	reward r{};
	if ((player->qdairy.checkstatus("main", 2) == QuestStatus::INACTIV)) {
		qt->m3();
		player->qdairy.completeMainQuest(1);
		drawmap->unlockMap(2);
	}
	if ((player->qdairy.checkstatus("main", 2) == QuestStatus::COMPLETE)&&
		(player->qdairy.checkstatus("main", 4) == QuestStatus::INACTIV)) {
		completeQuestScreen(3);
		r = player->qdairy.RewardForQuest(3);
		player->win(r);
		qt->m4();
		player->qdairy.completeMainQuest(3);
		drawmap->unlockMap(3);
	}
	if ((player->qdairy.checkstatus("main", 4) == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("main", 6) == QuestStatus::INACTIV)) {
		completeQuestScreen(5);
		qt->m5();
		r = player->qdairy.RewardForQuest(5);
		player->win(r);
		player->qdairy.completeMainQuest(5);
		drawmap->unlockMap(4);
	}
}

void AradTown::tawern()
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

void AradTown::tawrnQuest()
{
	if (player->qdairy.checkstatus("arad1") == QuestStatus::INACTIV) {
		qt->arad1();
		player->qdairy.takeQuest("arad1");
		drawmap->unlockMap(2, "others");
	}

	else if ((player->qdairy.checkstatus("arad1") == QuestStatus::COMPLETE) &&
		(player->qdairy.checkstatus("arad2") == QuestStatus::INACTIV)){
		qt->arad2();
		if (takedQuest() == true) {
			player->qdairy.takeQuest("arad2");
			sI paczka(new IOthers("Paczka przypraw", "Paczka przypraw do piwa dla karczmarza z Eram", 50));
			player->addItem(paczka);
		}
	}
	else {
		qt->nomore();
	}
}

