#pragma once
#include <string>

#include "BalanceChange.h"
#include "utils.h"

class Account {
	int id;
	std::string bank_name;
	AccountType type;
	float balance;
public:
	Account(std::string BankName, AccountType AccType, float StaringBalance = 0.f) :
		bank_name(BankName), type(AccType), balance(StaringBalance) {}
	~Account() = default;

	inline void SetID(int Id) { id = Id; }
	inline int GetID() const { return id; }

	void UpdateBalance(BalChange update);
	friend std::ostream& operator<<(std::ostream& os, Account& obj);
	friend std::ostream& operator<<(std::ostream& os, const Account& obj);

	inline float GetBalance() const { return balance; }
};