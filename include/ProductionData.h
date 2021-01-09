#pragma once

#include <unordered_map>

class Item;

struct ProductionData
{
	std::unordered_map<Item*, double>	CraftedItems;
};