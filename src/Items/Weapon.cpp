#include "Weapon.hpp"
#include <iostream>


Weapon::Weapon(std::string _name, std::string _description, int _price, int _damage)
	:IItems(_name, _description, _price), damage{_damage}
{
	iType = ItemType::Weapon;
}

std::string Weapon::getInfo()
{
	std::string priceS = std::to_string(price);
	std::string damageS = std::to_string(damage);
	std::string str = name + "\t| " + priceS + " gold \t| " + damageS + "\t| " + description;
return str;
}
