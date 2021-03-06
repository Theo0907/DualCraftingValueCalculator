#pragma once

#include "CraftParams.h"
#include "CraftSkills.h"
#include "ProductionData.h"

#include <vector>

class Item;

struct Craft
{
	CraftParams								params;
	//required item + amount
	std::vector<std::pair<Item*, double>>	ingredients;
	double									amount;
	//Item*				result;
	ProductionData							prodData;

	double	ComputeCraftValue(const CraftSkills&);
};