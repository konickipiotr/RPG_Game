#include "IArmor.hpp"
#include <iostream>

IArmor::IArmor()
{
}

IArmor::IArmor(std::string _name, std::string _description, int _price, int _armor)
	:IItems(_name, _description, _price), armorStat{ _armor }
{
	iType = ItemType::Armor;
}

std::string IArmor::getInfo()
{
	std::string priceS = std::to_string(price);
	std::string damageS = std::to_string(armorStat);
	std::string str = name + "\t| " + priceS + " gold \t| " + damageS + "\t| " + description;
	return str;
}
