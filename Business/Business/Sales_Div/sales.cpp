#include "sales.h"

Sale::Sale(int ID, int Customer)
	: sale_id(ID), customer_id(Customer), total_sale(TTD(0.f))
{
}

void Sale::AddItem(int Product, TTD Sale_Price)
{
	products.push_back(Product);
	total_sale += Sale_Price;
}
