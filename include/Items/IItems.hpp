#pragma once
#include <string>
#include "ItemType.hpp"
#include <string>
class IItems
{
public:
	IItems();
	IItems(std::string _name, std::string _description, int _price);
	virtual std::string getInfo() = 0;
	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
	ItemType getiType() const { return iType; }
	int getPrice() const { return price; }
	int getIdItem() const { return id; };
	
protected:
	std::string name;
	std::string description;
	ItemType iType;
	int price;
	int id;
	static int idgen;

};

