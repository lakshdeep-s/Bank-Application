#include "Accounts.h"
#include<string>
#include<iostream>

// Constructor
Accounts::Accounts(std::string name, double balance)
	:accountHolderName{ name }, accountBalance{ balance } {
}

// Destructor
Accounts::~Accounts() {};

// Copy Constructur
Accounts::Accounts(const Accounts& source)
	:Accounts{source.accountHolderName, source.accountBalance}{
}

//-------
void Accounts::setAccountHolderName(std::string nameVal) {
	accountHolderName = nameVal;
}

std::string Accounts::getAccountHolderName() {
	return accountHolderName;
}

//-------

void Accounts::setAccountBalance(double balanceVal) {
	accountBalance = balanceVal;
}

double Accounts::getAccountBalance() {
	return accountBalance;
}

//-------
double Accounts::getWithTaxRate() {
	return withTaxRate;
}
double Accounts::getDepositTaxRate() {
	return depositTaxRate;
}

//-------
double Accounts::applyWithTax(const double amount) {
	double newAmount = amount - amount * getWithTaxRate();
	return newAmount;
}
double Accounts::applyDepositTax(const double amount) {
	double newAmount = amount - amount * getDepositTaxRate();
	return newAmount;
}

//-------

void Accounts::withdrawFromAccount(double withAmount) {
	if (withAmount > 10000) {
		if (applyWithTax(withAmount) <= accountBalance)
		{
			accountBalance -= applyWithTax(withAmount);
			std::cout << "\n---- Successful Transaction ----\n";
		}
		else {
			std::cout << "\n---- Insufficient Funds ----\n";
		}
	}
	else {
		if (withAmount <= accountBalance) {
			accountBalance -= withAmount;
			std::cout << "\n---- Successful Transaction ----\n";
		}
		else {
			std::cout << "\n---- Insufficient Funds ----\n";
		}
	}
}

void Accounts::depositToAccount(double depositAmount) {
	if (depositAmount > 20000) {
		accountBalance += applyDepositTax(depositAmount);
		std::cout << "\n---- Successful Transaction ----\n";
	}
	else {
		accountBalance += depositAmount;
		std::cout << "\n---- Successful Transaction ----\n";
	}
}