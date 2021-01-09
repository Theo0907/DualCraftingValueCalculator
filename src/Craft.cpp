#include "Craft.h"
#include "Item.h"

double Craft::ComputeCraftValue(const CraftSkills& skills, ProductionData& data)
{
	if (ingredients.size() == 0)
		return -1;
	double result = 0;
	for (unsigned i = 0; i < ingredients.size(); ++i)
	{
		double value{ ingredients[i].first->GetCraftValue(skills, data) };
		if (value != -1)
			result +=  (value * ingredients[i].second) / amount;
		data.CraftedItems[ingredients[i].first] += ingredients[i].second;
	}

	return result;
}
