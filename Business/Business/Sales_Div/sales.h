#pragma once

#include "currency.h"
#include <vector>

class Sale
{
	int sale_id;
	int customer_id;
	std::vector<int> products;
	TTD total_sale;

public:
	Sale(int ID, int Customer);
	~Sale() = default;

	void AddItem(int Product, TTD Sale_Price);

	int GetID() const { return sale_id; }
	std::vector<int> GetItems() const { return products; }
	float GetTotalSale() const { return total_sale.value(); }
};