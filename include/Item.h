#pragma once

#include "Craft.h"
#include "ProductionData.h"

#include <string>

class Item
{
	std::string	name;
	double		craftValue = -1;
	double		sellValue = -1;

public:
	Craft		craft;

	Item(std::string n, double sellVal) : name {n}, sellValue {sellVal}
	{}

	double				GetCraftValue(const CraftSkills&, ProductionData& data);
	double				GetSellValue();
	const std::string&	GetName() const 
	{
		return name;
	}

	void	SetCraft(const Craft& c)
	{
		craft = c;
	}

	void	DepreciateCraftValue();
};