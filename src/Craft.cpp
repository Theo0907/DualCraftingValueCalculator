#include "Craft.h"
#include "Item.h"

double Craft::ComputeCraftValue(const CraftSkills& skills)
{
	if (ingredients.size() == 0)
		return -1;
	double result = 0;
	for (unsigned i = 0; i < ingredients.size(); ++i)
		result += ingredients[i].first->GetCraftValue(skills) != -1 ? (ingredients[i].first->GetCraftValue(skills) * ingredients[i].second) / amount : 0;

	return result;
}
