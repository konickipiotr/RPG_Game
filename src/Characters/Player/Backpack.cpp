#include "Backpack.hpp"
#include <iostream>



Backpack::Backpack()
{
	slots.reserve(12);
	slots.push_back(It(new IMixture("Fiolka zdrowa", "Przywraca 20 pkt zycia", 50,20, MixtureType::health)));
}

void Backpack::addItem(It & _item)
{
	if (slots.size() < 12) {
		slots.push_back(_item);
	}	
}

void Backpack::removeItem(int num)
{
	if (!slots.empty() || slots.size() > num)
		slots.erase(slots.begin() + num);
}

void Backpack::removeItem(std::string idS)
{
	for (int i = 0; i < slots.size(); i++) {
		if (slots.at(i)->getName() == idS) {
			slots.erase(slots.begin() + i);
		}
	}
}

It Backpack::moveItem(int num)
{
	It temp = slots.at(num);
	slots.erase(slots.begin() + num);
	return temp;
}

void Backpack::dispalyBackpack()
{
	for (auto & i : slots)
		std::cout << i->getName() << " " << i->getDescription() << " " << i->getPrice() << std::endl;
}

bool Backpack::findItem(std::string itemName, ItemType itemT)
{
	for (auto & i : slots) {
		if (i->getiType() == itemT && i->getName() == itemName)
			return true;
	}
	return false;
}

int Backpack::checkFreeSlots()
{
	return 12-slots.size();
}

ItemType Backpack::retItemType(int num)
{
	
	return slots[num]->getiType();
}
