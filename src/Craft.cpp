#include "Craft.h"
#include "Item.h"

double Craft::ComputeCraftValue(const CraftSkills& skills)
{
	if (ingredients.size() == 0)
		return -1;
	prodData.CraftedItems.clear();
	double result = 0;
	for (unsigned i = 0; i < ingredients.size(); ++i)
	{
		ProductionData d;
		double value{ ingredients[i].first->GetCraftValue(skills, d) };
		if (value != -1)
			result +=  (value * ingredients[i].second) / amount;
		
		prodData.CraftedItems[ingredients[i].first] += ingredients[i].second / amount;
		for (auto& it : d.CraftedItems)
		{
			prodData.CraftedItems[it.first] += ingredients[i].second * it.second / amount;
		}
	}

	return result;
}
