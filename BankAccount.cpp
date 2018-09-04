#include "stdafx.h"
#include "BankAccount.h"
#include <iostream>
#include <string>

using namespace std;

BankAccount::BankAccount()
	:ANNUAL_RATE(3.0)
{}

BankAccount::BankAccount(int accountNum, double accbalance)
	:accountNumber(accountNum),balance(accbalance),ANNUAL_RATE(3.)
	{}
void BankAccount::setAccountNumber(int accountNumber) {
	if (accountNumber >= 1000 && accountNumber <= 9999) {
		this->accountNumber = accountNumber;
	}
	else {
		cout << "Invalid Account number";
		//system.exit(-1);
	}
}

void BankAccount::setAccountBalance(double balance) {
	if (balance > 0 && balance < 100000) {
		this->balance = balance;
	}
	else {
		cout << "invalid input";
		//system.exit(-1);
	}
}

int BankAccount::getAccountNumber() {
	return this->accountNumber;
}

double BankAccount::getAccountBalance() {
	return this->balance;
}
//----------------------------Enter Account Details----------------------------------

void BankAccount::enterAccountData() {
	int accountNum;
	double accountBalance;
	do {
		cout << "Enter Account Number : ";
		cin >> accountNum;
		this->setAccountNumber(accountNum);
	} while (accountNum < 1000 || accountNum > 9999);

	do {
		cout << "Enter Account Balance : ";
		cin >> accountBalance;
		this->setAccountBalance(accountBalance);
	} while (accountBalance < 0 || accountBalance > 100000);
}
//--------------------------------Compute interest--------------------------------------

void BankAccount::computeInterest(int year) {
		double startBalance = this->balance;
		cout << "Year \t Interest \t Starting balance \t End Balance" << endl;

		for (int i = 1; i <= year; i++)
		{
			double interest = startBalance * this->ANNUAL_RATE / 100;
			double endBalance = startBalance + interest;

			cout << "  " << i << " \t | \t " << interest << "\t | \t" << startBalance << "\t | \t" << endBalance << endl;
			startBalance = endBalance;
		}cout << endl;
}
//-------------------------------Display Account Details------------------------------------

void BankAccount::displayAccount() {
	cout << "-----------------------------Account Information----------------------------" << endl;
	cout << "Account Number : " << this->getAccountNumber() << endl;
	cout << "Account Balance: " << this->getAccountBalance() << endl;
	cout << "Interest Rate : " << this->ANNUAL_RATE << endl;
	cout << endl;
}
