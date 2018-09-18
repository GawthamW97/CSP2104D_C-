#include "stdafx.h"
#include "BankAccount.h"
#include "Transaction.h"
#include <iostream>
#include <string>

using namespace std;


Transaction::Transaction(int transactionID, double amount, int accountNumber1, double balance1, int accountNumber2, double balance2) :fromAccount(accountNumber1, balance1), toAccount(accountNumber2, balance2) {

	this->transactionID = transactionID;
	this->amount = amount;
}

bool Transaction::transferAmount() {
	if (fromAccount.getAccountBalance() - getAmount() <= 0) {
		cout << "The remaining balance is in negative!" << endl;
		return false;
	}if ((fromAccount.getAccountBalance() - getAmount() < 10)) {
		cout << "Warning - Your remaining balance will be less than $10.00" << endl;
	}if (toAccount.getAccountBalance() + getAmount() >= 100000.00) {
		cout << "Warning -The transfer amount is the highest amount that is federally insured" << endl;
	}if (fromAccount.getAccountNumber() == toAccount.getAccountNumber()) {
		cout << "The Account Numbers that were entered are same! " << endl;
		return false;
	}
	return true;
}

double Transaction::newBalance1() {
	this->fromAccount.setAccountBalance(fromAccount.getAccountBalance() - getAmount());
	return this->fromAccount.getAccountBalance();
}

double Transaction::newBalance2() {
	this->toAccount.setAccountBalance(toAccount.getAccountBalance() + getAmount());
	return this->toAccount.getAccountBalance();
}

double Transaction::getAmount() {
	return this->amount;
}

BankAccount Transaction::getFromAccount() {
	return this->fromAccount;
}

BankAccount Transaction::getToAccount() {
	return this->toAccount;
}

int Transaction::getTransactionID() {
	return this->transactionID;
}



