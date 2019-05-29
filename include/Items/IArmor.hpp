#pragma once
#include "IItems.hpp"
#include "ArmorType.hpp"
class IArmor :
	public IItems
{
public:
	IArmor();
	IArmor(std::string _name, std::string _description, int _price, int _armor);
	int getArmorStat() const { return armorStat; }
	ArmorType  getArmorType() const { return armorType; }
	std::string getInfo();

protected:
	int armorStat;
	ArmorType armorType;
};

