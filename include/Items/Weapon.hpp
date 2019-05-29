#pragma once
#include "IItems.hpp"
class Weapon :
	public IItems
{
public:
	Weapon(std::string _name, std::string _description, int _price, int _damage);
	int getDamage() const {	return damage; }
	virtual std::string getInfo();
private:
	
	int damage;
};

