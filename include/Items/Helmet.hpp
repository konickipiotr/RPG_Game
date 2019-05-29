#pragma once
#include "IArmor.hpp"
class Helmet
	:public IArmor
{
public:
	Helmet(std::string _name, std::string _description, int _price, int _armor);
};

