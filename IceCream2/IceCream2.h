#pragma once
#include<iostream>
using namespace std;
//Homework1
struct IceCreamFlavour {
	char name[32];
	double pricePerBall;
	IceCreamFlavour();
	IceCreamFlavour(char name[32] , double pricePerBall);
	
	const char* getNameF()const;
	double getPricePerBall()const;
};
class IceCream {
private:
	char* name;
	int numberOfBalls;
	IceCreamFlavour flavour;
public:
	IceCream();
	IceCream(const char*, int, IceCreamFlavour);
	IceCream(const IceCream&);
	IceCream& operator=(const IceCream&);
	~IceCream();

	void setName(const char*);
	void setNumberOfBalls(int);
	void setIceCreamFlavour(IceCreamFlavour);

	const char* getName()const;
	int getNumberOfBalls()const;
	IceCreamFlavour getIceCreamFlavour()const;

	double getPrice()const;
	void print()const;
	//Homework2

	bool operator<(const IceCream&)const;
	bool operator>(const IceCream&)const;
	bool operator<=(const IceCream&)const;
	bool operator>=(const IceCream&)const;
	bool operator==(const IceCream&)const;
	bool operator!=(const IceCream&)const;
};
void printIceCreamWithFlavour(IceCream* arr, int size, IceCreamFlavour searchedFlavour);
IceCream bestIceCream(IceCream* arr, int size, double money);

class IceCreamContainer {
private:
	IceCream* iceCreams;
	int size, capacity;

	void resize();
	void unsize();
	void popAt(size_t index);
public:
	IceCreamContainer();
	IceCreamContainer(IceCream*, int, int);
	IceCreamContainer(const IceCreamContainer&);
	IceCreamContainer& operator=(const IceCreamContainer&);
	~IceCreamContainer();

	void setSize(int);
	void setCap(int);

	int getSize()const;
	int getCap()const;

	void addIceCream(const IceCream&);
	void removeIceCream(int);

	bool has(const IceCream& obj);
	double fullPriceOfIceCreams() const;
};

