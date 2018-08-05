# CSP2104D_C-
// Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct BankAccount{
	int accountNumber;
	string customerName;
	double balance;
	string password;
};
BankAccount client[2];
int accNum;
double accBal;
int main()
{
	int accNum;
	string clientName;
	int i = 0;
	while (i < 2) {
		/*----------------------------------------Check Account Number----------------------------------------*/
		do {
			cout << "Enter account Number : ";
			cin >> accNum;
			if (accNum >= 1000 && accNum <= 9999) {
				client[i].accountNumber = accNum;
			}
			else {
				cout << "Invalid Input" << endl;
			}
		} while (accNum < 1000 || accNum>9999);

		cout << "Enter customer name : ";
		cin >> client[i].customerName;
		cout << "Enter account balance : ";
		cin >> client[i].balance;
		cout << "Enter password : ";
		cin >> client[i].password;
		cout << endl;
		i++;
	}
		char user_wish;
		int accNum1;
		int accNum2;
		double amount;

		cout << "Would you like to Transfer money ? "; 
		cin >> user_wish;
		switch (user_wish) {
		case 'Y':/*-----------------------------------------------Transfering Money-----------------------------------*/
		case 'y':
			do {
				cout << "Enter your Account Number : ";
				cin.ignore();
				cin >> accNum1;
				cout << "Enter the Account Number to be Transfered : ";
				cin.ignore();
				cin >> accNum2;
				if (accNum1 >= 1000 && accNum1 <= 9999 && accNum2 >= 1000 && accNum2 <= 9999) {
					client[i - 2].accountNumber = accNum1;
					client[i - 1].accountNumber = accNum2;
				}
				else {
					cout << "Invalid Input" << endl;
				}
			} while (accNum1 < 1000 || accNum1 >9999);

			if (accNum1 != accNum2) {
				cout << "Enter the Amount You want to transfer : ";  //Money Transaction............
				cin >> amount;
				if ((client[i - 2].balance - amount < 10)) {
					cout << "Warning - Your remaining balance will be less than $10.00" << endl;
				}if (client[i - 2].balance - amount < 0) {
					cout << "The remaining balance is in negative!" << endl;
					return 0;
				}if (client[i - 1].balance + amount >= 100000.00) {
					cout << "Warning -The transfer amount is the highest amount that is federally insured" << endl;
				}
				client[i - 2].balance = client[i - 2].balance - amount;
				client[i - 1].balance = client[i - 1].balance + amount;

				cout << "First Account balance- "<< client[i - 2].balance << endl;
				cout << "Second Account balance- " << client[i - 1].balance << endl;
			}
			else {
				cout << "Invalid Username or Password " << endl;
				return 0;
			}
			break;
		case 'N':
		case 'n':
			cout << "Thank You" << endl;
			break;
		default:
			cout << "Invalid Input" << endl;
//-----------------------checking the balance----------------------------------
		cout << "Would You like to check your account balance? ";
		cin.ignore();
		cin >> user_wish;
		switch (user_wish) {
		case 'Y':
		case 'y':
			cout << "Enter your Account Number : ";
			cin >> accNum;
			cout << "Enter your Name : ";
			cin >> clientName;
			if (accNum == client[i].accountNumber && clientName == client[i].customerName) {
				cout <<"Your account Balance is "<< client[i].balance<<endl;
				cout << "Next customer please";
			}
			else {
				cout << "Invalid Username or Password "<<endl;
			}
			break;
		case 'N':
		case 'n':
			cout << "Thank You"<<endl;
			break;
		default:
			cout << "Invalid Input"<<endl;
		}
	}
	system("pause");
    return 0;
}
	
