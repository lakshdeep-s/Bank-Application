#pragma once
#include<string>

class Accounts {
private:
	std::string accountHolderName;
	double accountBalance;
	const double depositTaxRate{ 0.05 };
	const double withTaxRate{ 0.03 };
// private methods 
	double applyWithTax(const double amount);
	double applyDepositTax(const double amount);

public:
	// Constructor
	Accounts(std::string name = "None", double balance = 0.0);

	// Destructor
	~Accounts();

	// Copy Constructor
	Accounts(const Accounts& source);

	// Getter and Setter for Account Holder
	void setAccountHolderName(std::string nameVal);
	std::string getAccountHolderName();

	// Gettter and Setter for Account balance
	void setAccountBalance(double balanceVal);
	double getAccountBalance();

	// getter for taxRates
	double getWithTaxRate();
	double getDepositTaxRate();

	// Account Witdhrawl 
	void withdrawFromAccount(double withAmount);
	void depositToAccount(double depositAmount);
};