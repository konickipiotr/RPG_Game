#pragma once
#include "IItems.hpp"
#include <vector>
#include <memory>
#include "IOthers.hpp"
#include "Weapon.hpp"
#include "IArmor.hpp"
#include "Armor.hpp"
#include "Boots.hpp"
#include "Pants.hpp"
#include "Helmet.hpp"
#include "IMixture.hpp"

typedef std::shared_ptr<IItems> It;
class Backpack
{
public:
	Backpack();
	void addItem(It & _item);
	void removeItem(int num);
	void removeItem(std::string idS);
	It moveItem(int num);
	void dispalyBackpack();
	bool findItem(std::string itemName, ItemType itemT);
	int checkFreeSlots();
	ItemType retItemType(int num);
	std::vector<It> slots;
};

