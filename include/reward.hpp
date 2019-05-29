#pragma once
#include "Items/IItems.hpp"
#include <memory>
struct reward
{
	int exp;
	int gold;
	std::shared_ptr<IItems> rewItem{ nullptr };
};