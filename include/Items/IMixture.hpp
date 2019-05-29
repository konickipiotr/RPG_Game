#pragma once
#include "IItems.hpp"
#include "MixtureType.hpp"
class IMixture :
	public IItems
{
public:
	IMixture();
	IMixture(std::string _name, std::string _description, int _price, int _value, MixtureType _mixType);
	MixtureType getMixType();
	int getValue() const {return value;}
	virtual std::string getInfo();
	
protected:
	MixtureType mixtureType;
	int value;
};

