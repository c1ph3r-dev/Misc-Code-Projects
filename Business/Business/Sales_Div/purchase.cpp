#include "purchase.h"

Purchase::Purchase(int ID, int Purchase_Item_ID, TTD Purchase_Price, int Purchase_Amount, std::time_t Purchase_Date)
	: purchase_id(ID), purchased_item_id(Purchase_Item_ID), purchase_price(Purchase_Price), purchase_amount(Purchase_Amount), purchase_date(Purchase_Date)
{
}
