#include "ItemsHandler.h"

#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>

ItemsHandler::~ItemsHandler()
{
	for (auto& it : items)
		delete it.second;
}

bool ItemsHandler::LoadJson()
{
	std::ifstream i("config.json");
	if (!i.is_open())
		return false;

	nlohmann::json j;
	i >> j;
	if (j.is_null() || j.find("items") == j.end() || !j["items"].is_array())
		return false;

	for (nlohmann::json& value : j["items"])
	{
		Item item{ value["Name"] , value["Sell Value"] };
		item.craft.ingredients.reserve(value["Ingredients"].size());
		item.craft.amount = value["Amount"];
		for (nlohmann::json& ingredient : value["Ingredients"])
		{
			auto it = items.find(ingredient["Name"]);
			if (it == items.end())
			{
				std::cout << "Could not find item " << ingredient["Name"] << " in current dictionnary. (Adding item " << value["Name"] << ")" << std::endl;
				continue;
			}
			item.craft.ingredients.emplace_back(it->second, ingredient["Amount"]);
		}
		items.emplace(value["Name"], new Item(item));
	}

	return true;
}

std::pair<double, double> ItemsHandler::GetPrice(const std::string& itemName, const CraftSkills& skills, ProductionData& data)
{
	auto it = items.find(itemName);
	if (it == items.end())
		return std::make_pair(-1, -1);
	return std::make_pair(it->second->GetCraftValue(skills, data), it->second->GetSellValue());
}

void ItemsHandler::List(std::string search)
{
	for (int i = 0; i < search.size(); ++i)
		search[i] = std::tolower(search[i]);
	for (auto& it : items)
	{
		std::string s;
		s.reserve(it.first.size());
		for (int i = 0; i < it.first.size(); ++i)
			s.push_back(std::tolower(it.first[i]));
		if (s.find(search) != std::string::npos)
			std::cout << it.first << std::endl;
	}
}
