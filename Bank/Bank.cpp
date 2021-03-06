#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;
#include "Bank.h"


BankAccount::BankAccount()
{
	setName(NULL);
	setAccountNumb(0);
	setBalance(0);
}

BankAccount::BankAccount(const char *name, const char *accountNumb, double balance)
{
	setName(this->name);
	setAccountNumb(this->accountNumb);
	setBalance(this->balance);
}

BankAccount::BankAccount(const BankAccount &other)
{
	this->name = other.name;
	this->accountNumb = other.accountNumb;
	this->balance = other.balance;
}

BankAccount & BankAccount::operator=(const BankAccount &other)
{
	if (this!=&other)
	{
		this->name = other.name;
		this->accountNumb = other.accountNumb;
		this->balance = other.balance;
	}
	return *this;
}

BankAccount::~BankAccount()
{
	delete[] this->name;
	delete[] this->accountNumb;
}

void BankAccount::print()
{
	cout << "Name of the client:" << this->getName() << endl;
	cout << "Account number: " << this->getAccountNumb() << endl;
	cout << "Balance: " << this->getBalance() << endl;
}

void BankAccount::deposit(double balance)
{
	int addedMoney;
	balance = this->getBalance + addedMoney;
}

void BankAccount::withdraw(double balance)
{
	int tokenMoney;
	balance = this->getBalance + tokenMoney;
}

void BankAccount::setName(char *name)
{
	if (name!=nullptr)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void BankAccount::setAccountNumb(char *accountNumb)
{
	if (accountNumb != nullptr)
	{
		this->accountNumb = new char[strlen(accountNumb) + 1];
		strcpy_s(this->accountNumb, strlen(accountNumb) + 1, accountNumb);
	}
}

void BankAccount::setBalance(double)
{
	this->balance = balance;
}

const char * BankAccount::getName() const
{
	return this -> name;
}

const char * BankAccount::getAccountNumb() const
{
	return this->accountNumb;
}

double BankAccount::getBalance() const
{
	return this->balance;
}

Bank::Bank()
{
	accounts[1];
	setSize(0);
	setCap(1);
}

Bank::Bank(BankAccount **accounts, int size, int capacity)
{
	accounts = new BankAccount*[capacity];
	setSize(size);
	setCap(capacity);
	
}

Bank::Bank(const Bank & other)
{
	accounts = other.accounts;
	size = other.size;
	capacity = other.capacity;
}

Bank & Bank::operator=(const Bank & other)
{
	if (this!=&other)
	{
		accounts = other.accounts;
		size = other.size;
		capacity = other.capacity;
	}
	return *this;
}

Bank::~Bank()
{
	delete[] this->accounts;
}

BankAccount & Bank::getAccount(int index)
{
	if (index < getSize())
		return *accounts[index];
	else cout << "Index is invalid!";
}

void Bank::setCap(int capacity)
{
	if (capacity>0)
	{
		this->capacity = capacity;
	}
	
}

void Bank::setSize(int size)
{
	this->size = size;
}

int Bank::getCap() const
{
	return this->capacity;
}

int Bank::getSize() const
{
	return this->size;
}

void Bank::addAccount(const BankAccount& a)
{
	if (size+1>=getCap())
	{
		setCap(getCap() * 2);
		BankAccount** newAccount = new BankAccount*[getCap()];
		for (int i = 0; i < getSize(); i++)
		{
			newAccount[i] = accounts[i];
		}

		newAccount[size] = new BankAccount(a);
		setSize(getSize() + 1);
		delete[] accounts;
		accounts = newAccount;
	}
	else
	{
		accounts[getSize()] = new BankAccount(a);
		setSize(getSize() + 1);
	}
}

void Bank::deleteAccount(char* accountNumb)
{
	for (int i = 0; i < getSize(); i++)
	{
		if (!strcmp(accounts[i][i].getAccountNumb(),accountNumb))
		{

		}
	}
}

void Bank::print()
{
	
}
