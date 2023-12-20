#include "Tracker.h"
#include "Account.h"

#include <iostream>
#include <fstream>

void Tracker::AddChange(Account* account, BalChange* change)
{
	std::ofstream saveFile;
	saveFile.open("data/changes.data", std::ios_base::app);
	if (!saveFile.is_open()) throw std::runtime_error("Can't open changes file");

	saveFile << *account;
	saveFile << *change;
}

Tracker::Tracker()
{
	std::ifstream saveFile;
	saveFile.open("data/accounts.data", std::ios_base::in);
	if (!saveFile.is_open()) throw std::runtime_error("Can't open accounts file");

	while (true)
	{
		std::string bankName;
		AccountType type;
		float amount;

		saveFile >> bankName;
		if (bankName == "/end") break;

		saveFile >> type;
		saveFile >> amount;
		
		Account acc(bankName, type, amount);
		AddAccount(acc);
	}
	saveFile.close();
}

Tracker::~Tracker()
{
	std::ofstream saveFile;
	saveFile.open("data/accounts.data", std::ios_base::out);
	if (!saveFile.is_open()) std::cout << "Can't open accounts file\n";

	for (auto& account : accounts)
	{
		saveFile << account;
	}
	saveFile << "/end";
	saveFile.close();
}

void Tracker::AddAccount(const Account& account)
{
	Account newAccount = account;
	newAccount.SetID(numOfAccounts);
	numOfAccounts++;
	accounts.push_back(newAccount);
}

void Tracker::PrintAccounts() const
{
	for (auto& account : accounts)
		std::cout << account << std::endl;
}

void Tracker::AddChangeToAccount(int AccountID, BalChange change)
{
	for (auto& account : accounts)
	{
		if (account.GetID() == AccountID)
		{
			account.UpdateBalance(change);
			AddChange(&account, &change);
			break;
		}
	}
}

void Tracker::PrintChange(int ChangeID)
{
	std::ifstream saveFile;
	saveFile.open("data/changes.data", std::ios_base::in);
	if (!saveFile.is_open()) throw std::runtime_error("Can't open changes file");

	while (1)
	{
		std::string bankName;
		float amount;

		int id;
		std::string type;
		std::string desc;

		saveFile >> bankName;
		if (bankName == "/end") break;

		saveFile >> type;
		saveFile >> amount;
		saveFile >> id;
		saveFile >> type;
		saveFile >> amount;
		saveFile >> desc;

		if(type == "Income")

	}
}
