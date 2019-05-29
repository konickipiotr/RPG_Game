#pragma once
#include "IArmor.hpp"
class Boots :
	public IArmor
{
public:
	Boots(std::string _name, std::string _description, int _price, int _armor);
};

