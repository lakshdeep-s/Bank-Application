#include<iostream>
#include<vector>
#include<string>
#include "Accounts.h"
using namespace std;

int main(void) {
	Accounts emp1;
	emp1.setAccountHolderName("Lakshdeep Singh");
	cout << "Name of User : " << emp1.getAccountHolderName() << endl;
	emp1.setAccountBalance(10000);
	cout << "Account Balance : " << emp1.getAccountBalance() << endl;
	return 0;
}