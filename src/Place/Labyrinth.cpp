#include "Labyrinth.hpp"
#include "Weapon.hpp"


Labyrinth::Labyrinth()
{
}

Labyrinth::Labyrinth(Player *_player, std::string idS, DrawMap * _drawmap, QTexts * _qt)
	:Place(_player, idS, _drawmap, _qt)
{
}

void Labyrinth::displayMainMenu()
{
	GlobFunc::clearScreean();
	cout << "\n\t\t ***LABIRYNT ***\n";
	cout << "\n\tPo pokonaniu minotaura, stoisz u progu labiryntu\n\tw kt�rym gdzie� znajduje sie miecz bog�w. \n\tMusisz tylko znale�� do niego drog�\n";
	GlobFunc::key();
	graf();
	bool sword = false;
	char key;
	do {
		graf();
		key = GlobFunc::getch();
		switch (key)
		{
		case 'a': {
			fakeLab();
		}break;
		case 'w': {
			fakeLab();
		}break;
		case 'd': {
			fakeLab(sword);
		}break;
		}
		

	} while (sword == false);


	if (player->qdairy.checkstatus("main", 11) == QuestStatus::CURR) {
		std::shared_ptr<IItems> godSword(new Weapon("miecz bogow", "przepowiednia", 1000, 250));
		player->addItem(godSword);
	}
	bool found = player->equi.backpack.findItem("miecz bogow       ", ItemType::Weapon);
	if (found == true)
	{
		player->qdairy.completeMainQuest(11);
		drawmap->unlockMap(9);
	}
}

void Labyrinth::fakeLab()
{
	graf();
	char key;
	do {
		key = GlobFunc::getch();
		switch (key)
		{
		case 75: {
			DeadEnd();
			return;
		}break;
		case 70: {
			DeadEnd();
			return;
		}break;
		case 77: {
			DeadEnd();
			return;
		}break;
		}

	} while (true);
}

void Labyrinth::fakeLab(bool & found)
{
	
	graf();
	char key;
	do {
		key = GlobFunc::getch();
		switch (key)
		{
		case 75: {
			goodWay(found);
			return;
		}break;
		case 70: {
			DeadEnd();
			return;
		}break;
		case 77: {
			DeadEnd();
			return;
		}break;
		}

	} while (true);

}

void Labyrinth::DeadEnd()
{
	GlobFunc::clearScreean();
	cout << "\n\t�lepy zau�ek. Muszisz wr�ci� do pocz�tku\n";
	GlobFunc::key();
}

void Labyrinth::goodWay(bool & found)
{
	GlobFunc::clearScreean();
	cout << "\n\tUda�o si�!! Trafi�e� do wielkiej sali na �rodku, k�rej \n\t znajduje si� arcypiekny miecz. Miecz zesz�ny przez bog�w\n";
	found = true;

	GlobFunc::key();
}

void Labyrinth::graf()
{
	GlobFunc::clearScreean();
	cout << "\n\t\t ***LABIRYNT ***\n";
	cout << "\t###### \t\t\t ###### \t\t\t ######\n";
	cout << "\t###### \t\t\t ###### \t\t\t ######\n";
	cout << "\t###### \t\t\t ###### \t\t\t ######\n";
	cout << "\t###### \t\t\t ###### \t\t\t ######\n";
	cout << "\n\t\t\t Wybierz <- ^ ->  \n";

}
