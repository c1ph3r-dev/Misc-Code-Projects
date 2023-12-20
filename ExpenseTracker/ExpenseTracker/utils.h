#pragma once
#include <chrono>
#include <time.h>
#include <iostream>
#include <string>

enum class AccountType {
	Savings,
	Chequings
};

static std::ostream& operator<<(std::ostream& os, AccountType& obj)
{
	switch (obj)
	{
	case AccountType::Savings:
		os << "Savings ";
		break;
	case AccountType::Chequings:
		os << "Chequings ";
		break;
	default:
		break;
	}

	return os;
}

static std::ostream& operator<<(std::ostream& os, const AccountType& obj)
{
	switch (obj)
	{
	case AccountType::Savings:
		os << "Savings ";
		break;
	case AccountType::Chequings:
		os << "Chequings ";
		break;
	default:
		break;
	}

	return os;
}

static std::istream& operator >> (std::istream& in, AccountType& obj)
{
	std::string name;
	in >> name;
	if (name == "Savings") obj = AccountType::Savings;
	else obj = AccountType::Chequings;

	return in;
}

struct Date {
	char date[26];
	Date()
	{
		set_date();
	}
	void set_date()
	{
		std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		ctime_s(date, sizeof date, &now_time);
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

static std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.date;
	return os;
}