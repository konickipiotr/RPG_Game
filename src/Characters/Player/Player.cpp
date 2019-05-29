#include "Player.hpp"
#include <random>
#include <iostream>
#include <array>
#include <random>
#include "GlobFunc.hpp"

Player::Player()
{
}
Player::Player(std::string _name)
{
	name = _name;
	hp = 120;
	currHp = hp;
	streight = 15;
	streight = 10;
	stamina = 40;
	currStamina = stamina;
	death = false;
	lucky = 10;
	attackModify = 0;
	basicHp = hp;
	armor = 0;
	gold = 20;
	equi = Equipment(gold);
}


Player::~Player()
{
}

int Player::powerFullAttack()
{
	int mstamina = 30;
	int hit;
	std::string isCritical = "  ";
	if (currStamina - mstamina >= 0) {
		currStamina -= mstamina;

		if (criticalHit()) {
			isCritical = "!! Critical Hit !!";
			hit =  3 * streight + attackModify;
		}
		else {
			hit = 2 * streight + attackModify;
		}
		printLogFight("Silny atak ", hit, isCritical);
		return hit;
	}
	else
		return 0;
}

int Player::specialAttack()
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> a(0, streight*0.6);
	int special = a(gen);
	int mstamina = 20;
	std::string isCritical = "  ";
	int hit = 0;
	if (currStamina - mstamina >= 0) {
		currStamina -= mstamina;

		if (criticalHit()) {
			isCritical = "!! Critical Hit !!";
			hit = 2 * streight + attackModify + special;
		}
		else {
			hit = streight + attackModify + special;
		}
		printLogFight("Atak specjalny ", hit, isCritical);
		return hit;
	}
	else
		return 0;
}

void Player::updateParamtres()
{
	attackModify = 0;
	attackModify += equi.weapon->getDamage();
	
	armor = 0;
	armor += equi.Breastplate->getArmorStat();
	armor += equi.helmet->getArmorStat();
	armor += equi.boots->getArmorStat();
	armor += equi.pants->getArmorStat();

	hp = basicHp + armor;
	currHp = hp;
	currStamina = stamina;

}

void Player::equipment()
{
	equi.displayEqui();
	updateParamtres();
}

void Player::completeQuest(std::string idS)
{
	reward r{};
	r = qdairy.completeQuest(idS);
	win(r);
}

void Player::statInfo()
{
	int pos = -1;
	do
	{
		updateParamtres();
		pos = statictiControl();
		if (pos == 4)
			return;

		if (levelInfo.getSkilPoints() > 0)
		{
			levelInfo.useSkillPoint();
			switch (pos)
			{
			case 0:basicHp += 5; break;
			case 1:streight += 5; break;
			case 2:stamina += 5; break;
			case 3:lucky += 3; break;
			case 4:return; break;
			}
		}
		updateParamtres();
	} while (true);
}

int Player::statictiControl()
{
	using namespace std;
	array<char, 5> checkBox{ ' ',' ', ' ',' '};
	unsigned int pos = 0;
	do
	{
		GlobFunc::clearScreean();
		checkBox.at(pos) = 'X';
		cout << "\n\t\t *** STATYSTIKI GRACZA ***\n";
		levelInfo.displeyLeveInfo();
		cout << "\t\t------------------------" << endl;
		equi.displayEqInfo();
		cout <<"\t\t------------------------"<< endl;
		cout << "\t Zloto " << gold << " $" << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t Punkty umiejetnosci: " << levelInfo.getSkilPoints() << endl;
		cout << "\t Zycie        " << basicHp << "  \t+5 ["<< checkBox.at(0)<<"]" << std::endl;
		cout << "\t Sila         " << streight << " \t+5 [" << checkBox.at(1) << "]" << std::endl;
		cout << "\t Wytrzymalosc " << stamina << "  \t+5 [" << checkBox.at(2) << "]" << std::endl;
		cout << "\t Szczescie    " << lucky << "    \t+3 [" << checkBox.at(3) << "]" << std::endl;
		cout << "\t Powrot    - ESC             \t  " << std::endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\t\t Suma statystyk: " << endl;
		cout << "\t Podstawowe obrazenie: "<< streight+ attackModify << "\t Podstawowa obrona: " << basicHp + armor << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\t\t Zadania: " << endl;
		
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
		break;
		case 27:
		{
			return 4;
		}
		break;
		}
	} while (true);
}

void Player::win(reward & r)
{
	gold += r.gold;
	levelInfo.addExp(r.exp);
	if (r.rewItem != nullptr)
		addItem(r.rewItem);
}

void Player::addItem(sI & _item)

{
	char c = '1';
	if (equi.backpack.checkFreeSlots() == 0) {
		do {

			std::cout << "\n\tPlecak jest pe�ny" << std::endl;
			std::cout << "\tCzy chcesz usun�� jaki� przedmiot z plecaka? (y/n)" << std::endl;

			while (c != 'y' && c != 'n')
				c = GlobFunc::getch();

			if (c == 'y')
				equi.displayEqui();
			else if (c == 'n')
				return;

		} while (c != 'y' && c != 'n');
	}
	equi.addItem(_item);
}

void Player::buyGiveMoney(int price)
{
	gold -= price;
}

void Player::addnickname(std::string _nickname)
{
	nickname.push_back(_nickname);
}

std::string Player::getNickname()
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	std::uniform_int_distribution<> a(0, nickname.size()-1);
	int pos = a(gen);
	return nickname[pos];
}

void Player::setCurrStam(int value)
{
	if ((currStamina + value) >= stamina)
		currStamina = stamina;
	else
		currStamina += value;
}

void Player::setCurrHP(int value)
{
	if ((currHp + value) >= hp)
		currHp = hp;
	else
		currHp += value;
}


