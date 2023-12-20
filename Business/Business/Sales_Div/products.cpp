#include "products.h"

Product::Product(int Purchased_Item_ID, int ID, std::string Name, std::string Desc, TTD Price, int StockAmount)
	: purchased_item(Purchased_Item_ID), product_id(ID), name(Name), desc(Desc), selling_price(Price), stock(StockAmount)
{
}
