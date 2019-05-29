#include "Arena.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include "GlobFunc.hpp"


Arena::Arena(Player * _player, int x, int y)
{
	player = _player;
	enemy = chooseEnemy(x, y);
}

int Arena::fight()
{
	std::vector<std::string> labels{ "Atak","Atak Specjalny","Silny atak","Unik (odpoczynek)", "Mikstura","Ucieczka" };
	int x;
	int endFight = 0;
	
	
	do {
		std::cin.clear();
		x = menuControl(labels);
		if (enoughEnergy(x) == true)
			continue;

		switch (x)
		{
		case 0: wskAtt = &Player::attack; break;
		case 1: wskAtt = &Player::specialAttack; break;
		case 2: wskAtt = &Player::powerFullAttack; break;
		case 3: {
			int est = enemy->getCurrStamina();

			if (est < 12) {
				enemy->avoid(0);
				player->avoid(0);
			}
			else {
				player->avoid(enemy->attack());
				if (player->checkDead() == true)
				{
					x = 5;
				}
			}
		} break;
		case 4: 
		{
			
			std::shared_ptr<IMixture> mix = player->equi.mixtureB.displayBelt();
			if (mix == nullptr)
				break;
			MixtureType mixure = mix->getMixType();
			switch (mixure)
			{
			case MixtureType::health:player->setCurrHP(mix->getValue()); break;
			case MixtureType::stamina:player->setCurrStam(mix->getValue()); break;
			case MixtureType::stength:player->addToAttakModif(mix->getValue()); break;
			}
	
		}
		break;
		}

		if (x == 0 || x == 1 || x == 2)
		{
			endFight = pAttack(wskAtt);
		}

		
		GlobFunc::key();
	} while (x != 5 && endFight == 0);

	if (endFight == 1)
		playerWin();
	player->updateParamtres();
	GlobFunc::clearScreean();
	return endFight;
}

void Arena::showInfo()
{
	using std::cout;
	using std::endl;
	cout <<"\n\t\t"<< player->getName() << "\t\t\tVS\t\t" << enemy->getName() << endl;
	cout << "\n  HP:   ";
	statisticBar(player->getHp(), player->getCurrHp()); 
	cout <<" ("<<player->getCurrHp()<<"/"<<player->getHp()<< ")\t"; 
	statisticBar(enemy->getHp(), enemy->getCurrHp());
	cout << " (" << enemy->getCurrHp() << "/" << enemy->getHp() << ")\t" << endl;


	cout << "\n  STAM: ";

	statisticBar(player->getStamina(), player->getCurrStamina());
	cout << " (" << player->getCurrStamina() << "/" << player->getStamina() << ")\t";
	statisticBar(enemy->getStamina(), enemy->getCurrStamina());
	cout << " (" << enemy->getCurrStamina() << "/" << enemy->getStamina() << ")\t" << endl;
	
}

void Arena::statisticBar(int maxVal, int curVal)
{

	float percentFromValue = (float)curVal / (float)maxVal * 100;
	float barPercent = percentFromValue / 100 * 25;
	int maxBar = 25;
	int currBar = (int)barPercent;
	int restBar = maxBar - currBar;

	for (int i = 0; i < currBar; i++) {
		std::cout << "#";
	}
	
	for (int i = 0; i < restBar; i++) {
		std::cout << "-";
	}
	
}

int Arena::menuControl(std::vector<std::string>& labels)
{
	const int MENUSIZE = labels.size();
	std::vector<char> checkBox{};
	fillCheckBox(checkBox, MENUSIZE);
	unsigned int pos = 0;
	checkBox.at(pos) = 'X';
	do
	{

		GlobFunc::clearScreean();
		showInfo();
		displayFightOption(checkBox, labels);

		char ch = GlobFunc::getch();

		switch (ch)
		{
		case 's':if (pos < checkBox.size() - 1) keyChoose(checkBox, pos, 1); break;
		case 'w': if (pos > 0) keyChoose(checkBox, pos, -1);	break;
		case 'o':return pos;
		}

	} while (true);
}


int Arena::pAttack(Player::wskAttak wskAtt)
{
	using namespace std::chrono_literals;
	int playerDamage = (player->*wskAtt)();
	enemy->recieveDamage(playerDamage);
	
	std::this_thread::sleep_for(1s);
	if (enemy->checkDead() == true) 
		return 1;
	
	int enemyDamage = enemy->enemyAttack(playerDamage);
	player->recieveDamage(enemyDamage);
	std::this_thread::sleep_for(1s);
	if (player->checkDead() == true)
		return 2;
	if (enemy->checkDead() == true)
		return 1;
	
	return 0;
}

std::shared_ptr<Enemy> Arena::chooseEnemy(int x, int y)
{
	std::shared_ptr<Enemy> enemy;
	if (x == 27 && y == 18) enemy = std::make_shared<Enemy>("�otr", 100, 10, 40, 5, 20, 30, "obronca ch�op�w", sI(new IOthers("Stary pierscien", "Stary niewiel warty pierscien", 20)));
	else if (x == 36 && y == 19) enemy = std::make_shared<Enemy>("Wilk", 120, 25, 40, 5, 0, 40, "Wilczy Kie�", sI(new IOthers("Wilcza skora", "Cenny towar", 50)));
	else if ((x == 20 && y == 17) || (x == 18 && y == 17)) enemy = std::make_shared<Enemy>("Goblin", 140, 30, 45, 5, 20, 50, "zab�jca Goblin�w", sI(new Weapon("Zardzewialy miecz", "Starry zardzewialy miecze. Prawie nie nadaje sie do walki", 15, 20)));
	else if (x == 15 && y == 19) enemy = std::make_shared<Enemy>("Bandyta", 200, 35, 45, 5, 100, 80, "Stra�nik kr�lestwa", sI(new Weapon("Toporek", "Lekki toporek", 30, 40)));
	else if ((x == 4 && y == 12) || (x == 4 && y == 10))enemy = std::make_shared<Enemy>("Zombie", 220, 35, 100, 5, 40, 100, "Prawy", sI(new  IOthers("G�owa zombie", "�ywa martowa g�owa zomie", 0)));
	else if ((x == 18 && y == 8) || (x == 19 && y == 9)) enemy = std::make_shared<Enemy>("Dzik", 230, 50, 30, 5, 0, 100, "My�liwy", sI(new IOthers("K�y dzika", "Cenny towar handlowy", 30)));
	else if (x == 1 && y == 20) enemy = std::make_shared<Enemy>("Ork", 270, 40, 50, 5, 100, 130, "Wojownik", sI(new Weapon("Top�r wojenny", "Solidnie wykonany top�r wojenny", 50, 50)));

	else if (x == 29 && y == 13) enemy = std::make_shared<Enemy>("Ob�edny rycerz", 320, 40, 50, 5, 100, 150, "Rycerz", sI(new Armor("Zardzewialy napiesnik", "Stary zardzewialy i rozpadajacy sie napiesnik", 30, 20)));
	else if (x == 12 && y == 2) enemy = std::make_shared<Enemy>("Wilko�ak", 350, 45, 60, 5, 100, 180, "Srebrny bicz", sI(new IMixture("Eliksir zdrowa", "Przywraca 80 pkt zdrowa", 100, 80, MixtureType::health)));
	else if (x == 56 && y == 15) enemy = std::make_shared<Enemy>("Golem", 380, 45, 100, 5, 0, 200, "M�ot na golemy", sI(new IOthers("Serce golema", "Cenny przedmiot alchemiczny", 120)));
	else if (x == 28 && y == 8) enemy = std::make_shared<Enemy>("Ogr", 400, 50, 60, 5, 50, 200, "Ogroc�amacz", sI(new Boots("Buty rycerskie", "Plytowe buty rycerskie lekko zardzewia�e", 100, 100)));

	else if (x == 28 && y == 3) enemy = std::make_shared<Enemy>("Harpia", 400, 45, 50, 15, 80, 200, "Harpun na Harpie", sI(new IMixture("Eliksir si�y", "Eliksir si�y dodaje 100 pkt si�y", 200, 50, MixtureType::stength)));
	else if (x == 0 && y == 2) enemy = std::make_shared<Enemy>("Troll", 420, 60, 50, 5, 150, 250, "Pi�� Trolla", sI(new IOthers("Z�oty pierscien", "Z�oty pierscie� z diamientem", 200)));
	else if (x == 46 && y == 21) enemy = std::make_shared<Enemy>("Wampir", 450, 80, 60, 5, 80, 250, "Pogrmoca Wampir�w", sI(new Pants("Szlacheckie spodnie", "Spodnie wykonane z dobrego mateia�u, jednak \n\tnie maj� �adnych w�a�ciwos�i obronnych", 150, 10)));

	else if (x == 42 && y == 4) enemy = std::make_shared<Enemy>("Minotaur", 600, 150, 100, 5, 100, 350, "Pogromaca Mitonraura", sI(new IMixture("Esencja energii", "Przywraca 100 pkt energii", 150, 100, MixtureType::stamina)));
	else if (x == 59 && y == 6) enemy = std::make_shared<Enemy>("Mumia", 700, 100, 100, 5, 100, 400, "Nieustraszony", nullptr);
	else if (x == 66 && y == 4) enemy = std::make_shared<Enemy>("Smok", 1500, 200, 200, 5, 100, 1000, "Pogromca smok�w", nullptr);
	return enemy;
}

void Arena::playerWin()
{
	player->addnickname(enemy->getNickname());
	reward playerReward = enemy->getEnemyReward();
	player->win(playerReward);
	player->updateParamtres();
	GlobFunc::clearScreean();
	std::cout << "\n\n\n\t !!! ZWYCIESTWO !!!\n\n";
	std::cout << "\t\tEXP +" << playerReward.exp << std::endl;
	if (playerReward.gold != 0) {
		std::cout << "\t\tZLOTO +" << playerReward.gold << std::endl;
	}
	if (playerReward.rewItem != nullptr) {
		std::cout << "\tNOWY PRZEDMIOT \n\t";
		std::cout<< playerReward.rewItem->getInfo();
	}
	GlobFunc::key();
}

bool Arena::enoughEnergy(int x)
{
	bool exhausted = false;
	if (x == 0) {
		if ((player->getCurrStamina() - 9) <= 0) {
			exhausted = true;
		}
	}
	else if (x == 1) {
		if ((player->getCurrStamina() - 20) <= 0) {
			exhausted = true;
		}
	}
	else if (x == 2) {
		if ((player->getCurrStamina() - 30) <= 0) {
			exhausted = true;
		}
	}

	if (exhausted == true) {
		std::cout << "\t Masz za malo energi " << std::endl;
		GlobFunc::key();
		return true;
	}
	

	return false;
}

void Arena::fillCheckBox(std::vector<char>& checkBox, const int & size)
{
	for (int i = 0; i < size; ++i)
	{
		checkBox.push_back(' ');
	}
	
}

void Arena::displayFightOption(std::vector<char>& checkBox, const std::vector<std::string>& labels)
{
	std::cout << std::endl;
	for (unsigned int i = 0; i < labels.size(); ++i)
	{
		std::cout << "\t\t[" << checkBox.at(i) << "]\t" << labels.at(i) << std::endl;
	}
	std::cout << std::endl;
}

void Arena::keyChoose(std::vector<char>& checkBox, unsigned int & pos, int direc)
{
	checkBox.at(pos) = ' ';
	pos = pos + direc;
	checkBox.at(pos) = 'X';
}
