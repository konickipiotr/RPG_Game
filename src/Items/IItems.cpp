#include "IItems.hpp"
#include <iostream>


IItems::IItems()
{
	name = "";
	description = "";
	price = 0;
}

IItems::IItems(std::string _name, std::string _description, int _price)
	: description(_description), price(_price)
{
	int len = _name.length();
	if (len> 18) {
		name = _name.substr(0,18);
	}
	else if (len < 18) {
		name = _name;
		for (int i = 0; i < (18 - len); ++i) {
			name.append(" ");
		}
	}
	else {
		name = _name;
	}

	id = idgen++;
	
}
int IItems::idgen = 0;



