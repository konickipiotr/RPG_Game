#pragma once
#include "IArmor.hpp"
class Pants :
	public IArmor
{
public:
	Pants(std::string _name, std::string _description, int _price, int _armor);
};

