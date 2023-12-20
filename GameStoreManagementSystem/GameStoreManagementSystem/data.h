#pragma once
#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <string>
#include <sstream>

struct Product
{
	int ProductId;
	std::string ProductName;
	double Cost, SellingPrice;
	int Quantity;

	void Read(std::string inputLine)
	{
		std::stringstream inputString(inputLine);

		std::string tempString;

		std::getline(inputString, tempString, ',');
		ProductId = std::stoi(tempString);

		std::getline(inputString, ProductName, ',');

		std::getline(inputString, tempString, ',');
		Cost = std::stod(tempString);

		std::getline(inputString, tempString, ',');
		SellingPrice = std::stod(tempString);

		std::getline(inputString, tempString, ',');
		Quantity = std::stoi(tempString);
	}
};

struct Transaction
{
	int TransactionId, ProductSold, QuantitySold;
	std::string DateOfTransaction;

	void Read(std::string inputLine)
	{
		std::stringstream inputString(inputLine);

		std::string tempString;

		std::getline(inputString, tempString, ',');
		TransactionId = std::stoi(tempString);

		std::getline(inputString, tempString, ',');
		ProductSold = std::stoi(tempString);

		std::getline(inputString, tempString, ',');
		QuantitySold = std::stoi(tempString);

		std::getline(inputString, DateOfTransaction, ',');
	}
};

struct DailySales
{
	std::string SalesDate;
	double TotalSold;

	void Read(std::string inputLine)
	{
		std::stringstream inputString(inputLine);

		std::string tempString;

		std::getline(inputString, SalesDate, ',');

		std::getline(inputString, tempString, ',');
		TotalSold = std::stod(tempString);
	}
};

#endif // !DATA_H_
