#pragma once
#include <string>
#include "IItems.hpp"
class IOthers
	: public IItems
{
public:
	IOthers(std::string _name, std::string _description, int _price);
	virtual std::string getInfo();
};

