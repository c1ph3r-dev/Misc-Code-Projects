#pragma once
#include <vector>

class Account;
class BalChange;

class Tracker {
	std::vector<Account> accounts;
	int numOfAccounts = 0;

	void AddChange(Account* account, BalChange* change);

public:
	Tracker();
	~Tracker();

	void AddAccount(const Account& account);
	inline std::vector<Account> GetAccounts() { return accounts; }
	void PrintAccounts() const;

	void AddChangeToAccount(int AccountID, BalChange change);

	void PrintChanges(int AmountToPrint);
	void PrintChange(int ChangeID);
};