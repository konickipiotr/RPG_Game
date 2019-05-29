#include "Shop.hpp"
#include <string>
#include <iostream>
#include "GlobFunc.hpp"

Shop::Shop()
{
}

Shop::Shop(Player ** _player, std::string _name, ItemType itemT, int nrshop)
{
	player = *_player;
	name = _name;
	shopType = itemT;

	switch (itemT)
	{
	case ItemType::Armor: itemArmor(nrshop);
		break;
	case ItemType::Weapon: itemWeapon(nrshop);
		break;
	case ItemType::Mixture: itemMixture(nrshop);
		break;
	case ItemType::Othres: itemOther(nrshop);
		break;
	}
}

int Shop::controlPanel(const std::vector<std::string>& labels)
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
		infoScreen();
		if(checkBox.size()>0)
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
		break;
		case 27:
		{
			return -1;
		}
		break;
		case 'b':
		{
			return -2;
		}
		break;
	}

	} while (true);
}

void Shop::displayScreen()
{
	std::vector<std::string> labelsBuy{};
	if (!vItems.empty()) {
		for (auto & i : vItems) {
			labelsBuy.push_back(i->getInfo());
		}
	}
	std::vector<std::string> labelsSell{};
	for (auto & i : player->equi.backpack.slots) {
		labelsSell.push_back(i->getInfo());
	}

	bool sellOption = false;

	int pos = 0;
	do {
		if (sellOption == false) {
			pos = controlPanel(labelsBuy );
		}
		else if (sellOption == true) {
			pos = controlPanel(labelsSell);
		}

		if (sellOption == false && pos == -2) {
			sellOption = true;
		}
		else if (sellOption == true && pos == -2) {
			sellOption = false;
		}

		if (sellOption == false && pos >= 0) {
			if (checkPlayerMoney(vItems[pos]->getIdItem()))
			{
				sI temp = buy(pos);
				player->addItem(temp);
			}
		}
		else if (sellOption == true && pos >= 0) {
			if (!player->equi.backpack.slots.empty())
			{
				if (player->equi.backpack.retItemType(pos) == shopType) {
					sell(pos);
					labelsSell.erase(labelsSell.begin() + pos);
				}
				else {
					std::cout << "\n\tNie skupujemy takiego towaru\n" << std::endl;
					system("pause");
				}
			}
		}

	} while (pos != -1);

}

void Shop::infoScreen()
{
	using namespace std;
	cout << "\n\t\t*** " << name << " ***\n\n";
	cout << "\t Witaj w moim sklepie. Rozejrzyj sis.\n\t Na pewno mam cos co Cie zainteresuje.\n\n";
	cout << "\t [ESC] - wyjscie \t [b] - kup/sprzedaj" << endl;
	cout << "\t Twoja sakiewka: " << player->getGold() << endl << endl;
}

bool Shop::checkPlayerMoney(int idItem)
{
	int priceItem = 0;
	int goldPlayer = player->getGold();
	for (auto & i : vItems)
	{
		if (i->getIdItem() == idItem)
		{
			priceItem = i->getPrice();
			break;
		}
	}

	if ((goldPlayer - priceItem) >= 0)
	{
		return true;
	}

	return false;
}

int Shop::findPosition(int idItem)
{
	for (unsigned int i = 0; i<vItems.size(); i++)
	{
		if (vItems[i]->getIdItem() == idItem)
		{
			return i;
		}
	}	
}

sI Shop::buy(int pos)
{
	player->buyGiveMoney(vItems[pos]->getPrice());
	return vItems[pos];
}

void Shop::sell(int pos)
{
	sI tmp = player->equi.backpack.moveItem(pos);
	player->takeMoney(tmp->getPrice());
}

void Shop::itemArmor(int nrshop)
{
	switch (nrshop)
	{
	case 1: {
		vItems.push_back(std::shared_ptr<IItems>(new Armor("Sk�rzany kaftan", "Zapeniaj�cy podstawow� ochron� sk�rzany kaftan", 200, 50)));
		vItems.push_back(std::shared_ptr<IItems>(new Armor("Kolczuga", "Standardowa ochrona zwyk�ego szergowego", 400, 100)));

		vItems.push_back(std::shared_ptr<IItems>(new Helmet("Futrzana czapka", "Czapka zrobiano grubej sk�ry tura", 100, 20)));
		vItems.push_back(std::shared_ptr<IItems>(new Helmet("Czepiec kolczy", "Standardowa ochrona g�owy stra�y miejskiej", 150, 50)));

		vItems.push_back(std::shared_ptr<IItems>(new Boots("Sk�rzane buty", "Zwyk�e sk�rzane buty", 120, 30)));
		vItems.push_back(std::shared_ptr<IItems>(new Pants("Sk�rzne nogawice", "Zwyk�e sk�rzane nogawice", 150, 20)));
	
	} break;
	case 2: {
		vItems.push_back(std::shared_ptr<IItems>(new Armor("Zbroja �wiekowana", "Nabijana metalowymi �wiekami sk�rzana zbroja", 150, 80)));
		vItems.push_back(std::shared_ptr<IItems>(new Armor("Zbroja �uskowa", "Zbroja stowrzona z po�acznienia ma�ych metalowych p�ytek", 350, 140)));
		vItems.push_back(std::shared_ptr<IItems>(new Armor("Zbroja p�ytowa", "Najlepsza i zarazem najdro�sza zbroja", 1000, 300)));

		vItems.push_back(std::shared_ptr<IItems>(new Helmet("He�m z przy�bic�", "Solidny rycerski he�m z przy�bic�", 400, 100)));
		vItems.push_back(std::shared_ptr<IItems>(new Boots("P�ytowe buty", "P�ytowe rycerskie buty", 300, 80)));
		vItems.push_back(std::shared_ptr<IItems>(new Pants("P�ytowe nogawice", "P�ytowe rycerskie nogawice", 300, 100)));
	} break;
	}
}

void Shop::itemWeapon(int nrshop)
{
	switch (nrshop)
	{
	case 1: {
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("Siekiera", "Zwyk�a siekiera", 150, 50)));
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("Miecz prosty", "Standardowa bro� rycerzy", 300, 80)));
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("Top�r wojenny", "Pote�na bro�", 1000, 120)));


	} break;
	case 2: {
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("M�ot wojenny", "Mo�e nienajwygodniejszy, ale za to zadaje pote�ne obra�enia ", 200, 80)));
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("Bu�at ", "Egzotyczny miecz z dalekiego po�udnia", 300, 100)));
		vItems.push_back(std::shared_ptr<IItems>(new Weapon("Miecz ksia��cy", "Bro� wyoknana z najlepszej mo�liewj stali", 500, 200)));
	} break;
	}
}

void Shop::itemMixture(int nrshop)
{
	switch (nrshop)
	{
	case 1: {
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka zdrowia", "Przywraca 20 pkt �ycia", 20, 20, MixtureType::health)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka wytrzyma�o�ci", "Przywraca 20 pkt energii", 20, 20, MixtureType::stamina)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka si�y", "Zwi�ksza si�� o 20 pkt", 20, 20, MixtureType::stength)));
	} break;
	case 2: {
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka zdrowia", "Przywraca 20 pkt �ycia", 20, 20, MixtureType::health)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka wytrzyma�o�ci", "Przywraca 20 pkt energii", 20, 20, MixtureType::stamina)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Fiolka si�y", "Zwi�ksza si�� o 20 pkt", 40, 20, MixtureType::stength)));

		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura zdorwia", "Przywraca 50 pkt �ycia", 70, 50, MixtureType::health)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura wytrzyma�o�ci", "Przywraca 50 pkt energii", 70, 50, MixtureType::stamina)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura sily", "Zwi�ksza si�� o 50 pkt", 100, 50, MixtureType::stength)));
	} break;
	case 3: {
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura zdorwia", "Przywraca 50 pkt �ycia", 70, 50, MixtureType::health)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura wytrzyma�o�ci", "Przywraca 50 pkt energii", 70, 50, MixtureType::stamina)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Mixtura sily", "Zwi�ksza si�� o 50 pkt", 100, 50, MixtureType::stength)));

		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Eliksir zdrowia", "Przywraca 80 pkt �ycia", 100, 80, MixtureType::health)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Eliksir wytrzyma�o�ci", "Przywraca 80 pkt energii", 100, 80, MixtureType::stamina)));
		vItems.push_back(std::shared_ptr<IItems>(new IMixture("Eliksir si�y", "Zwi�ksza si�� o 80 pkt", 150, 80, MixtureType::stength)));

	} break;
	}
}

void Shop::itemOther(int nrshop)
{
	switch (nrshop)
	{
	case 1: {
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Gwo�dzie", "Metalowe gwo�dzie", 20)));
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Worek pszenicy", "Worek przenicy", 20)));
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Pergamin", "czysty fragment pergaminu", 20)));
	} break;
	case 2: {
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Gwo�dzie", "Metalowe gwo�dzie", 20)));
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Worek pszenicy", "Worek przenicy", 20)));
		vItems.push_back(std::shared_ptr<IItems>(new IOthers("Pergamin", "czysty fragment pergaminu", 20)));
	} break;
	}
}


