#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transaction
{
public:
	Transaction(char type, double amount, double balance, string description);
	char getType();
	double getAmount();
	double getBalance();
	string getDescription();

private:
	char type;
	double amount;
	double balance;
	string description;
};

class Account
{
public:
	Account();
	Account(string name, int ID, double balance);
	void withdraw(double amount);
	void deposit(double amount);
	int getID();
	void setID(int ID);
	double getBalance();
	void setBalance(double balance);
	double getAnnualInterestRate();
	void setAnnualInterestRate(double InterestRate);
	void printTransations(); 

private:
	double annualInterestRate;
	string name;
	int ID;
	double balance;
	vector<Transaction> transactions;
};

//create a transaction with given character value, amount, balance, and description
Transaction::Transaction(char type, double amount, double balance, string description)
{
	this->type = type;
	this->amount = amount;
	this->balance = balance;
	this->description = description;
}

//return type
char Transaction::getType()
{
	return type;
}

//return amount
double Transaction::getAmount()
{
	return amount;
}

//return balance
double Transaction::getBalance()
{
	return balance;
}

//return the transaction
string Transaction::getDescription()
{
	return description;
}

//functions for bank class
//default account constructor
Account::Account()
{
	ID = 0;
	balance = 0;
	annualInterestRate = 0;
	transactions;
}

//constructor with argument for account
Account::Account(string name, int ID, double balance)
{
	this->name = name;
	this->ID = ID;
	this->balance = balance;
	transactions;
}

//withdraw function
void Account::withdraw(double amount)
{
	//decrease the balance by the amount
	balance -= amount;
	//create a transaction object
	Transaction withdrawal('W', amount, balance, "withdrawal");
	//push the object into the vector in the account class
	transactions.push_back(withdrawal);
}

//deposit function
void Account::deposit(double amount)
{
	//add amount to balance
	balance += amount;
	//create a transaction object
	Transaction deposit('D', amount, balance, "deposit");
	//push the object into the vector in the account class
	transactions.push_back(deposit);
}

//get ID
int Account::getID()
{
	return ID;
}
//set ID
void Account::setID(int ID)
{
	this->ID = ID;
}

//get balance
double Account::getBalance()
{
	return balance;
}
//set balance
void Account::setBalance(double balance)
{
	this->balance = balance;
}

//get the annualInterestRate
double Account::getAnnualInterestRate() 
{
	return annualInterestRate;
}
//set the annualInterestRate
void Account::setAnnualInterestRate(double InterestRate)
{
	annualInterestRate = InterestRate;
}

//print out all transactions
void Account::printTransations()
{
	//Print out withdrawal if char type was w and deposit if char type was d
	for (int i = 0; i < transactions.size(); i++)
	{
		if (tolower(transactions[i].getType()) == 'w')
		{
			cout << "You withdrew: $" <<transactions[i].getAmount() << ". Your balance after withdrawing is $" << transactions[i].getBalance() << endl;
		}
		else if (tolower(transactions[i].getType()) == 'd')
		{
			cout << "Your deposited: $" << transactions[i].getAmount() << ". Your balance after depositing is $" << transactions[i].getBalance() << endl;
		}
	}
}