#include "Pants.hpp"

Pants::Pants(std::string _name, std::string _description, int _price, int _armor)
	:IArmor(_name, _description, _price, _armor)
{
	armorType = ArmorType::Pants;
}