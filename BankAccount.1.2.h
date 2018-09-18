#pragma once

#ifndef _BANKACCOUNT
#define _BANKACCOUNT

class BankAccount {

private:
	int accountNumber;
	double balance;

public:
	BankAccount();
	BankAccount(int, double);
	const double ANNUAL_RATE;
	void setAccountNumber(int);
	void setAccountBalance(double);
	int getAccountNumber();
	double getAccountBalance();
	void enterAccountData();
	void computeInterest(int);
	void displayAccount();
};
#endif
