#pragma once

#include "currency.h"
#include <string>

class Logistic
{
	int log_item_id;
	std::string item_name;
	std::string item_info;
	TTD cost_ttd;

public:
	Logistic(int ID, std::string Name, std::string Desc, USD Cost);
	~Logistic() = default;

	int GetID() const { return log_item_id; }
	std::string GetName() const { return item_name; }
	std::string GetDesc() const { return item_info; }
	float GetCostTTD() const { return cost_ttd.value(); }
};