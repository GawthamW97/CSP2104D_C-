#pragma once
#ifndef _TRANSACTION
#define _TRANSACTION

class Transaction {
private:
	int transactionID;
	double amount;
	BankAccount fromAccount;
	BankAccount toAccount;
public: 
	Transaction(int,double,int,double,int,double);
	bool transferAmount();
	double newBalance1();
	double newBalance2();
	double getAmount();
	int getTransactionID();
	BankAccount getFromAccount();
	BankAccount getToAccount();
};
#endif // !_TRANSACTION
