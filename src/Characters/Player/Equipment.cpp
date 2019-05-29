#include "Equipment.hpp"
#include "GlobFunc.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Equipment::Equipment()
{
}

Equipment::Equipment(int & _zloto)
{
	zloto = _zloto;
	std::shared_ptr<Weapon>w(new Weapon{ "kij", "Zwykly kij znalezionty w lesie",1,5 });
	weapon = w;

	std::shared_ptr<Armor>b(new Armor{ "Koszula", "Koszula z lnu",5,5 });
	Breastplate = b;
		
	std::shared_ptr<Boots> bo(new Boots{ "Trzewiki", "Najbardziej pospolite buty na swiecie", 5,5 });
	boots = bo;

	std::shared_ptr<Pants> pa(new Pants{ "Lniane spodnie", "Typowo chlopskie spodnie",2,2 });
	pants = pa;

	std::shared_ptr<Helmet> he(new Helmet{ "Kaptur", "Zwyk�y kaptur z materia�u, bez �adanych w�a�ciwo�ci ochronnych",5,2 });
	helmet = he;
}

void Equipment::equipItem(spIt & item)
{
	
	if (item->getiType() == ItemType::Weapon) {

		spIt temp = weapon;
		addItem(temp);
		weapon = std::dynamic_pointer_cast<Weapon>(item);
	}
	else if (item->getiType() == ItemType::Armor) {
		std::shared_ptr<IArmor> ptIArm = std::make_shared<IArmor>();
		ptIArm = std::dynamic_pointer_cast<IArmor>(item);
		equipArmor(ptIArm);
	}
	else if (item->getiType() == ItemType::Mixture) {
		std::shared_ptr<IMixture> ptIMix = std::make_shared<IMixture>();
		ptIMix = std::dynamic_pointer_cast<IMixture>(item);
		if (mixtureB.mixtureBelt.size() == 3)
		{
			std::cin.clear();
			std::cout << "kt�r� mikstur� wymieni�? (1,2,3)";
			char c;
			GlobFunc::getch();
			c = GlobFunc::getch();
			int num;
			if (c == 49) {
				num = 0;
			}
			else if (c == 50) {
				num = 1;
			}
			else if (c == 51) {
				num = 2;
			}
			spIt temp = mixtureB.mixtureBelt.at(num);
			mixtureB.mixtureBelt.at(num) = ptIMix;
			addItem(temp);
		}
		else {
			mixtureB.addToBelt(ptIMix);
		}		
	}
}


void Equipment::equipArmor(std::shared_ptr<IArmor> & arr)
{
	spIt temp;
	switch (arr->getArmorType())
	{
	case ArmorType::Breastplate: 
	{
		temp = Breastplate;
		addItem(temp);
		Breastplate = std::dynamic_pointer_cast<Armor>(arr);
	}
		break;
	case ArmorType::Helmet: {
		temp = helmet;
		addItem(temp);
		helmet = std::dynamic_pointer_cast<Helmet>(arr);
	}
		break;
	case ArmorType::Boot: {
		temp = boots;
		addItem(temp);
		boots = std::dynamic_pointer_cast<Boots>(arr);
	}
		break;
	case ArmorType::Pants: {
		temp = pants;
		addItem(temp);
		pants = std::dynamic_pointer_cast<Pants>(arr);
	}
		break;
	}
}

void Equipment::addItem(spIt _it)
{
	backpack.addItem(_it);
}

void Equipment::displayEqui()
{
	std::string x{};
	std::shared_ptr<IItems> it;
	do
	{
		x = controlMenu();
		if (x != "EXIT")
		{

			for (unsigned int i = 0; i < backpack.slots.size(); i++)
			{
				if (backpack.slots[i]->getName() == x && backpack.slots[i]->getiType() != ItemType::Othres)
				{
					it = backpack.slots[i];
					backpack.slots.erase(backpack.slots.begin() + i);
					break;
				}
			}
			equipItem(it);
		}
	} while (x != "EXIT");
	
}

void Equipment::displayEqInfo()
{
	using namespace std;
	cout << "\t Bro�: " << weapon->getDamage() << endl;
	cout << "\t Zbroja: " << Breastplate->getArmorStat()<< "\tHe�m:"<<helmet->getArmorStat()<< "\tButy:" << boots->getArmorStat()<< "\tSpodnie:" << pants->getArmorStat()<< endl;
}


std::string Equipment::controlMenu()
{
	std::vector<std::string> bpLabel{ 17," empty            " };
	std::vector<std::string> mixtureBelt{};
	std::vector<char> checkBox{};
	for (auto & i : bpLabel)
	{
		i = " empty            ";
	}
	bpLabel[0] = weapon->getName();
	bpLabel[1] = Breastplate->getName();
	bpLabel[2] = boots->getName();
	bpLabel[3] = pants->getName();
	bpLabel[4] = helmet->getName();



	for (unsigned int i = 0; i < bpLabel.size(); i++) {
		checkBox.push_back(' ');
	}
	unsigned int pos = 5;
	do {


		for (unsigned int i = 0, j = 5; i < backpack.slots.size(); i++) {
			if (backpack.slots[i]->getName() != "") {
				bpLabel[j] = backpack.slots[i]->getName();
				j++;
			}
		}
		checkBox.at(pos) = 'X';
		GlobFunc::clearScreean();
		std::cout << "\n\t\t *** Ekwipunek ***\n\n";
		std::cout << "\tZ�oto: " << zloto << std::endl;
		std::cout << "\t\t\t Bro�: " << bpLabel.at(0) << std::endl;
		std::cout << "\t Zbroja: " << bpLabel.at(1);
		std::cout << "\t He�m: " << bpLabel.at(4) << std::endl;
		std::cout << "\t Buty: " << bpLabel.at(2);
		std::cout << "\t Spodnie: " << bpLabel.at(3);
		std::cout << "\n\t----------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "\t\t\tPLECAK" << std::endl;
		for (unsigned int i = 5; i < checkBox.size(); i++) {
			if (i % 2 != 0) {
				std::cout << std::endl;
				std::cout << "\t";
			}
			std::cout << "[" << checkBox.at(i) << "] " << bpLabel.at(i);
		}

		std::cout << "\n\t----------------------------------------------------------------" << std::endl;
		std::cout << "\t\t\t\t MIXTURES BELT " << std::endl;
		std::cout << "\t | ";
		for (unsigned int i = 0; i < 3; i++)
		{
			if (i < mixtureB.mixtureBelt.size())
			{
				std::cout << mixtureB.mixtureBelt[i]->getName();
			}
			else {
				std::cout << "empty        ";
			}
			std::cout << " | ";
		}
		std::cout << std::endl;
		
	
		std::cout << "\t----------------------------------------------------------------" << std::endl;
		std::cout << "\t Suma opancerzenia: " << helmet->getArmorStat() + Breastplate->getArmorStat() + boots->getArmorStat() + pants->getArmorStat() << std::endl;
		std::cout << "\t Obra�enia od broni: " << weapon->getDamage() << std::endl;
		std::cout << "\t----------------------------------------------------------------" << std::endl;
		std::cout << "\t[ESC] POWROT \t x - wyrzu� przedmiot" << std::endl;
		
		for (auto & i : backpack.slots)
		{
			if (i->getName() == bpLabel[pos])
			{
				i->getInfo();
				break;
			}
		}

		
		char ch = GlobFunc::getch();

		switch (ch)
		{
		case 's':
		{
			if (pos < checkBox.size() - 2)
			{
				checkBox.at(pos) = ' ';
				pos=pos+2;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'w':
		{
			if (pos > 6)
			{
				checkBox.at(pos) = ' ';
				pos=pos-2;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'd':
		{
			if (pos >= 5 && pos < checkBox.size()-1)
			{
				checkBox.at(pos) = ' ';
				pos++;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'a':
		{
			if (pos < checkBox.size() && pos > 5)
			{
				checkBox.at(pos) = ' ';
				pos--;
				checkBox.at(pos) = 'X';
			}
		}
		break;
		case 'o':
		{
			if(bpLabel[pos] != " empty            ")
				return bpLabel[pos];
		}
		break;
		case 27:
		{
			return "EXIT";
		}
		break;
		case 'x':
		{
			if (bpLabel[pos] != " empty            ") {
				backpack.removeItem(pos - 5);
				bpLabel.erase(bpLabel.begin() + pos);
				bpLabel.push_back(" empty            ");
			}
		}
		break;
		
		}

	} while (true);

}
