#pragma once

#include "Item.h"

#include <unordered_map>
#include <filesystem>

class ItemsHandler
{
	std::unordered_map<std::string, Item*>	items;

public:
	~ItemsHandler();
	bool					LoadConfig();
	bool					LoadJson(const std::filesystem::path& file);

	std::pair<double, double>	GetPrice(const std::string& itemName, const CraftSkills&, ProductionData& data);
	void						List(std::string search = "");
};

