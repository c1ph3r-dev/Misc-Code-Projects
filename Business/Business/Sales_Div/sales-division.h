#pragma once

#include "logistics.h"
#include "purchase.h"
#include "products.h"
#include "customer.h"
#include "sales.h"

class SalesDivision
{
	std::vector<Logistic> ItemsToBuy;
	std::vector<Purchase> Purchases;
	std::vector<Product> ProductsToSell;
	std::vector<Customer> Customers;
	std::vector<Sale> Sales;

public:
	SalesDivision();
};