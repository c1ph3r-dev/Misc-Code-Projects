#pragma once

#include <string>

class Customer
{
	int customer_id;
	std::string name;
	std::string phone_number;

public:
	Customer(int ID, std::string Name, std::string Phone_Number);
	~Customer() = default;

	int GetID() const { return customer_id; }
	std::string GetName() const { return name; }
	std::string GetPhoneNumber() const { return phone_number; }
};