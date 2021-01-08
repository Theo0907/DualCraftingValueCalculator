#pragma once

#include "Item.h"

#include <unordered_map>

class ItemsHandler
{
	std::unordered_map<std::string, Item*>	items;

public:
	~ItemsHandler();

	bool					LoadJson();

	std::pair<double, double>	GetPrice(const std::string& itemName, const CraftSkills&);
	void						List(std::string search = "");
};

