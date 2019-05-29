#pragma once
#include "IArmor.hpp"
class Armor:
	public IArmor
{
public:
	Armor(std::string _name, std::string _description, int _price, int _armor);
};

