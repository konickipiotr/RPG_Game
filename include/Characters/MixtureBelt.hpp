#pragma once
#include <memory>
#include <vector>
#include "IMixture.hpp"

typedef std::shared_ptr<IMixture> uqMix;
class MixtureBelt
{
public:
	MixtureBelt();
	void addToBelt(uqMix toAddMix);
	void removeFromBelt(const int & num);
	uqMix displayBelt();
	
	int graph(std::vector<std::string> & mix);
	std::vector<uqMix > mixtureBelt;	
};

