#pragma once
#include <string>

class BalChange {
protected:
	int id;
	float amount;
	std::string description;

public:
	BalChange(float Amount, std::string Desc) : amount(Amount), description(Desc) {}
	virtual ~BalChange() = default;
	float GetAmount() const { return amount;  }

	friend std::ostream& operator<<(std::ostream& os, BalChange& obj);
	friend std::ostream& operator<<(std::ostream& os, const BalChange& obj);
};

class Expense final : public BalChange{
public:
	Expense(float Amount, std::string Desc) : BalChange(-1.f * Amount, Desc) {}
	~Expense() = default;
};

class Income final : public BalChange {
public:
	Income(float Amount, std::string Desc) : BalChange(Amount, Desc) {}
	~Income() = default;
};

std::ostream& operator<<(std::ostream& os, BalChange& obj)
{
	os << obj.id << " ";
	if (auto expense = dynamic_cast<Expense*>(&obj)) os << "Expense ";
	else if (auto income = dynamic_cast<Income*>(&obj)) os << "Income ";

	os << obj.amount << " " << obj.description << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const BalChange& obj)
{
	BalChange local = obj;

	os << obj.id << " ";
	if (auto expense = dynamic_cast<Expense*>(&local)) os << "Expense ";
	else if (auto income = dynamic_cast<Income*>(&local)) os << "Income ";

	os << obj.amount << " " << obj.description << std::endl;
	return os;
}