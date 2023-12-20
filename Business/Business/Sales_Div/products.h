#pragma once

#include "currency.h"
#include <string>

class Product
{
	int purchased_item;
	int product_id;
	std::string name;
	std::string desc;
	TTD selling_price;
	int stock;

public:
	Product(int Purchased_Item_ID, int ID, std::string Name, std::string Desc, TTD Price, int StockAmount);
	~Product() = default;

	int GetPurchasedItemID() const { return purchased_item; }
	int GetID() const { return product_id; }
	std::string GetName() const { return name; }
	std::string GetDesc() const { return desc; }
	float GetPrice() const { return selling_price.value(); }
	int GetStockAmount() const { return stock; }
};