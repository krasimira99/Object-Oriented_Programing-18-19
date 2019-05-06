#pragma once
class BankAccount {
private:
	char*name;
	char*accountNumb;
	double balance;
public:
	BankAccount();
	BankAccount(const char*, const char*, double);
	BankAccount(const BankAccount&);
	BankAccount& operator=(const BankAccount&);
	~BankAccount();

	void print();
	void deposit(double);
	void withdraw(double);

	void setName(char*);
	void setAccountNumb(char*);
	void setBalance(double);

	const char* getName()const;
	const char* getAccountNumb()const;
	double getBalance()const;
};

class Bank {
private:
	BankAccount** accounts;
	int size;
	int capacity;
public:
	Bank();
	Bank(BankAccount**, int,int );
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	~Bank();

	BankAccount& getAccount(int);

	void setCap(int);
	void setSize(int);

	int getCap()const;
	int getSize()const;

	void addAccount(const BankAccount&);
	void deleteAccount(char*);
	void print();
};