#include "Mapa.hpp"
#include "Player.hpp"
#include <iostream>
#include <memory>

Mapa::Mapa()
{
}

Mapa::Mapa(std::string name)
{
	posX = 27;
	posY = 24;
	playerPos = 'O';
	player = Player(name);
	drawmap = DrawMap(&player);
	qt = QTexts(&player);
	qt.m1();
}

void Mapa::displayMap()
{
	GlobFunc::clearScreean();
	
	const int y{ 25 };
	const int x{ 70 };


	for (int i = 0; i < y; i++) {
		for (int j = 0; j <x; j++) {
			m[j][i] = ' ';
		}
	}

	int posX = 27;
	int posY = 24;
	char old = '*';
	
	do
	{
		GlobFunc::clearScreean();
		drawmap.draw(m);
		
		m[posX][posY] = playerPos;
		m[posX][posY] = playerPos;

		std::cout << "\t|";
		for (int i = 0; i < x; ++i)
		{
			std::cout << "-";
		}
		std::cout << "|\n\t|";
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				std::cout << m[j][i];
			}
			std::cout <<"|"<< std::endl;
			std::cout << "\t|";
		}

		for (int i = 0; i < x; ++i)
		{
			std::cout << "-";
		}
		std::cout << "|";
		std::cout << "\n\t| ESC - wyjscie |  q - dziennik zadan  |  e - ekwipunek  |  c - postac |\n";
		GlobFunc::controlInfo();
		char key = GlobFunc::getch();

		int v = 0;
		int h = 0;
		switch (key)
		{
		case 's':
		{
			v = 1;
			if (m[posX +h ][posY + v] == '*' || m[posX + h][posY + v] == '#' || m[posX + h][posY + v] == '&')
			{
				
					m[posX][posY] = old;
					posY++;
					old = m[posX][posY];
					m[posX][posY] = playerPos;
	
			}
			else if (m[posX + h][posY + v] == '@')
			{
				ArenaPlace(posX, posY,v,h);
			}
		}
		break;
		case 'w':
		{
			v = -1;
			if (m[posX + h][posY + v] == '*' || m[posX + h][posY + v] == '#' || m[posX + h][posY + v] == '&')
			{
				m[posX][posY] = old;
				posY--;
				old = m[posX][posY];
				m[posX][posY] = playerPos;

			}
			else if (m[posX + h][posY + v] == '@')
			{
				ArenaPlace(posX, posY, v, h);
			}
		}
		break;
		case 'd':
		{
			h = 1;
			if (m[posX + h][posY + v] == '*' || m[posX + h][posY + v] == '#' || m[posX + h][posY + v] == '&')
			{
				m[posX][posY] = old;
				posX++;
				old = m[posX][posY];
				m[posX][posY] = playerPos;

			}
			else if (m[posX + h][posY + v] == '@')
			{
				ArenaPlace(posX, posY, v, h);
			}
		}
		break;
		case 'a':
		{
			h = -1;
			if (m[posX + h][posY + v] == '*' || m[posX + h][posY + v] == '#' || m[posX + h][posY + v] == '&')
			{
				m[posX][posY] = old;
				posX--;
				old = m[posX][posY];
				m[posX][posY] = playerPos;

			}
			else if (m[posX + h][posY + v] == '@')
			{
				ArenaPlace(posX, posY, v, h);
			}
		}
		break;
		case 'o':
		{
			if (m[posX][posY] == 'O' && old == '#') {
				std::shared_ptr<Place>nPlace;
				newPlace(posX, posY, nPlace);
				visitPlace(nPlace);
			}
		}
		break;
		case 27:
		{
			std::cout << "\tCzy napewno czesz wyjsc z gry?(y/n)";
			GlobFunc::getch();
			char c = GlobFunc::getch();
			if (c == 'y')
				exit(0);
			GlobFunc::clearScreean();

		}
		break;
		case 'e':
		{
			player.equipment();
			GlobFunc::clearScreean();
		}
			break;
		case 'c':
		{
			player.statInfo();
			GlobFunc::clearScreean();
		}
		break;
		case 'q':
		{
			GlobFunc::clearScreean();
			player.qdairy.dairyQuests();
			GlobFunc::clearScreean();
			
		}
		break;
		}	
		checkQuestComplete();

	} while (gameOver == false);
}

void Mapa::visitPlace(std::shared_ptr<Place> place)
{
	place->displayMainMenu();
}

void Mapa::newPlace(int x, int y,std::shared_ptr<Place> & nPlace)
{
	if (x == 27 && y == 20)	nPlace = std::make_shared<KurowoVillage>(&player,"kur", &drawmap, &qt);
	else if (x == 14 && y == 13)nPlace = std::make_shared<AradTown>(&player, "arad", &drawmap, &qt);
	else if (x == 40 && y == 9)nPlace = std::make_shared<KingsCastle>(&player, "castle", &drawmap, &qt);
	else if (x == 46 && y == 16)nPlace = std::make_shared<HadikVillage>(&player, "hadik", &drawmap, &qt);
	else if (x == 60 && y == 12)nPlace = std::make_shared<Eram>(&player, "eram", &drawmap, &qt);
	else if (x == 28 && y == 1)nPlace = std::make_shared<HarpyTower>(&player, "harpy", &drawmap, &qt);
	else if (x == 42 && y == 2)nPlace = std::make_shared<Labyrinth>(&player, "labtr", &drawmap, &qt);
	else if (x == 15 && y == 24)nPlace = std::make_shared<OldFortress>(&player, "oldfort", &drawmap, &qt);
	else if (x == 60 && y == 20)nPlace = std::make_shared<MagTower>(&player, "magtow", &drawmap, &qt);
	else if (x == 59 && y == 8)nPlace = std::make_shared<Pyramid>(&player, "pyramid", &drawmap, &qt);
}

void Mapa::ArenaPlace(const int & posX, const int & posY, int v, int h)
{
	int win;
	std::unique_ptr<Arena> ar(new Arena(&player, posX, posY));
	win = ar->fight();
	switch (win)
	{
	case 0: std::cout << "ucieczka" << std::endl;
		break;
	case 1: 
	{
		int x = posX + h;
		int y = posY + v;
		drawmap.winBattlePlace(m, x, y);
	}
		break;
	case 2: gameOver = true; break;
	default:
		break;
	}
	GlobFunc::clearScreean();
}

void Mapa::checkQuestComplete()
{
		if (m[15][20] == '&') player.qdairy.completeMainQuest(2); //bandyta
		if (m[4][11] == '&') player.qdairy.completeMainQuest(4);
		if (m[1][21] == '&') player.qdairy.completeOtherQuest("arad1"); //okr
		if (m[37][19] == '&'&& player.qdairy.checkstatus("kur2") == QuestStatus::CURR) player.qdairy.toreward("kur2");//wilk
		if (m[27][17] == '&' && player.qdairy.checkstatus("kur1") == QuestStatus::CURR) player.qdairy.toreward("kur1");//wilk
		if (m[27][17] == '&' && player.qdairy.checkstatus("hadik") == QuestStatus::CURR) player.qdairy.toreward("hadik");//wampir
		if (m[0][1] == '&' && player.qdairy.checkstatus("eram1") == QuestStatus::CURR) player.qdairy.toreward("eram1");//troll
		if (m[12][1] == '&' && player.qdairy.checkstatus("castle1") == QuestStatus::CURR) player.qdairy.toreward("castle1");//wilko�ak
		if (m[67][4] == '&'){
			player.qdairy.completeMainQuest(16);
			gameOver = true;
			winGame();
		}
		if (player.equi.backpack.findItem("miecz bog�w      ", ItemType::Weapon)) {
			player.qdairy.completeMainQuest(11);
		}
}

void Mapa::winGame()
{
	GlobFunc::clearScreean();
	std::cout << "\n\t\t!!! Wyga�e� !!!\n";
	GlobFunc::key();
}

void Mapa::playerlose()
{
	GlobFunc::clearScreean();
	std::cout << "\n\t !! Przegra�e� !!\n";
	GlobFunc::key();
	GlobFunc::clearScreean();
}







