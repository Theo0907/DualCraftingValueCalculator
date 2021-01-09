#include "Item.h"

#include <iostream>

double Item::GetCraftValue(const CraftSkills& skills, ProductionData& data)
{
	if (craftValue == -1)
	{
		craftValue = craft.ComputeCraftValue(skills);
		if (craftValue == -1)
			craftValue = sellValue;
	}
	if (craftValue == -1)
		std::cout << "Item " << name << " could not compute value properly." << std::endl;

	for (auto& it : craft.prodData.CraftedItems)
	{
		data.CraftedItems[it.first] += it.second;
	}
	return craftValue;
}

double Item::GetSellValue()
{
	return sellValue;
}

void Item::DepreciateCraftValue()
{
	craftValue = -1;
}
