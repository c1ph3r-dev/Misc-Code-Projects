#include "Account.h"

void Account::UpdateBalance(BalChange update)
{
	balance += update.GetAmount();
}

std::ostream& operator<<(std::ostream& os, Account& obj)
{
	bool bIsNotFile = (os.rdbuf() == std::cout.rdbuf());
	if (bIsNotFile)
		os << "ID: " << obj.id << " ";

	os << obj.bank_name << " " << obj.type;

	if (bIsNotFile) os << '$';
	os << obj.balance << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Account& obj)
{
	bool bIsNotFile = (os.rdbuf() == std::cout.rdbuf());
	if (bIsNotFile)
		os << "ID: " << obj.id << " ";

	os << obj.bank_name << " " << obj.type;

	if (bIsNotFile) os << '$';
	os << obj.balance << std::endl;
	return os;
}