#pragma once
#include "Backpack.hpp"
#include "MixtureBelt.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"
#include "Boots.hpp"
#include "Pants.hpp"
#include "Helmet.hpp"

class Equipment
{
	typedef std::unique_ptr<IItems> It;
	typedef std::shared_ptr<IItems> spIt;
public:
	Equipment();
	Equipment(int & _zloto);
	void equipItem(spIt & item);
	void equipArmor(std::shared_ptr<IArmor> & arr);
	void addItem(spIt _it);
	void displayEqui();
	void displayEqInfo();
	std::string  controlMenu();
	Backpack backpack;
	MixtureBelt mixtureB;


	std::shared_ptr<Weapon> weapon;
	std::shared_ptr<Armor> Breastplate;
	std::shared_ptr<Boots> boots;
	std::shared_ptr<Pants> pants;
	std::shared_ptr<Helmet> helmet;
	int zloto;

};

