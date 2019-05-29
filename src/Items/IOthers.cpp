#include "IOthers.hpp"
#include <iostream>


IOthers::IOthers(std::string _name, std::string _description, int _price)
	:IItems(_name, _description, _price)
{
	iType = ItemType::Othres;
}

std::string IOthers::getInfo()
{
	std::string priceS = std::to_string(price);
	std::string str = name + "\t| " + priceS + " gold \t| " + description;
	return str;
}