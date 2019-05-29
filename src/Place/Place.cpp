#include "Place.hpp"
#include <iostream>
#include <string>

Place::Place()
{}

Place::Place(Player * _player, std::string _idS, DrawMap * _drawmap, QTexts * _qt)
{
	player = _player;
	idS = _idS;
	drawmap = _drawmap;
	qt = _qt;
}


int Place::controlPanel(const std::vector<std::string> & labels)
{
	std::vector<char> checkBox;
	for (unsigned int i = 0; i < labels.size(); i++)
	{
		checkBox.push_back(' ');
	}

	unsigned int pos = 0;
	do
	{
		GlobFunc::clearScreean();
		checkBox.at(pos) = 'X';
		for (unsigned int i = 0; i < labels.size(); i++)
		{
			std::cout << "\t[" << checkBox.at(i) << "]  " << labels.at(i) << std::endl;
		}
		char key;
		key = GlobFunc::getch();

		switch (key)
		{
		case 's':
		{
			if (pos < checkBox.size() - 1)
			{
				checkBox.at(pos) = ' ';
				pos++;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'w':
		{
			if (pos > 0)
			{
				checkBox.at(pos) = ' ';
				pos--;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'o':
		{
			return pos;
		}
		}
	} while (true);
}

void Place::completeQuestScreen(std::string idS)
{
	reward r = player->qdairy.completeQuest(idS);
	using namespace std;
	GlobFunc::clearScreean();
	cout << "\n\t\t ZADANIE ZAKO�CZONE\n";
	cout << "\n\tDzi�kuj� "<<player->getName()<<" "<<player->getNickname()<<" oto twoja nagroda:" << endl;
	cout << "\tZ�oto: " << r.gold << endl;
	cout << "\tExp:   " << r.exp << endl;
	if (r.rewItem != nullptr) {
		cout << "\tPrzedmiot: \n\t";
		std::cout<<r.rewItem->getInfo();
	}
	
	qt->helper();
}

void Place::completeQuestScreen(int num)
{
	reward r = player->qdairy.RewardForQuest(num);
	using namespace std;
	GlobFunc::clearScreean();
	cout << "\n\t\t ZADANIE ZAKO�CZONE\n";
	cout << "\n\tDzi�kuj� " << player->getName() << " " << player->getNickname() << " oto twoja nagroda:" << endl;
	cout << "\tZ�oto: " << r.gold << endl;
	cout << "\tExp:   " << r.exp << endl;
	if (r.rewItem != nullptr) {
		cout << "\tPrzedmiot: \n\t";
		std::cout << r.rewItem->getInfo();
	}

	qt->helper();
}


bool Place::takedQuest()
{
	std::cout << "\n\tCzy przyjmujesz zadanie? (y/n)" << std::endl;
	char c;
	do {
		c = GlobFunc::getch();
		if (c == 'y')
			return true;
	} while (c != 'n');
	return false;
}
