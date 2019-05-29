#include "IMixture.hpp"
#include <iostream>

IMixture::IMixture()
{
	iType = ItemType::Mixture;
}

IMixture::IMixture(std::string _name, std::string _description, int _price, int _value, MixtureType _mixType)
	:IItems(_name, _description, _price), value{ _value }, mixtureType{ _mixType }
{
	iType = ItemType::Mixture;
}

MixtureType IMixture::getMixType()
{
	switch (mixtureType)
	{
	case MixtureType::health: return MixtureType::health;
		break;
	case MixtureType::stength: return MixtureType::stength;
		break;
	case MixtureType::stamina: return MixtureType::stamina;
		break;
	}
}

std::string IMixture::getInfo()
{
	std::string priceS = std::to_string(price);
	std::string valueS = std::to_string(value);
	std::string str = name + "\t| " + priceS + " gold \t| " + valueS + "\t| " + description;
	return str;
}
