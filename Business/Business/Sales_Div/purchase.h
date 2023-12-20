#pragma once

#include "currency.h"
#include <stdio.h>
#include <time.h>
#include <stdint.h>

class Purchase
{
	int purchase_id;
	int purchased_item_id;
	TTD purchase_price;
	int purchase_amount;
	std::time_t purchase_date;

public:
	Purchase(int ID, int Purchase_Item_ID, TTD Purchase_Price, int Purchase_Amount, std::time_t Purchase_Date);
	~Purchase() = default;

	int GetID() const { return purchase_id; }
	int GetPurchasedItemID() const { return purchased_item_id; }
	float GetPerItemPrice() const { return purchase_price.value(); }
	float GetTotalPrice() const { return purchase_price.value() * purchase_amount; }
	int GetPurchaseAmount() const { return purchase_amount; }
	std::time_t GetPurchaseDate() const { return purchase_date; }

};