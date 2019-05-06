#include "pch.h"
#include "IceCream.h"
#include <iostream>
#include<cstring>
using namespace std;

IceCreamFlavour::IceCreamFlavour(char name[32], int priceOfBall)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->priceOfBall = priceOfBall;
}
IceCreamFlavour::IceCreamFlavour()
{
	name[0] = '\0';
	priceOfBall = 0;
}
//"set" функции
void IceCream::setNameI(const char* name)
{
	delete[] this->name;
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}
void IceCream::setNumberOfBalls(const int numberOfBalls)
{
	this->numberOfBalls = numberOfBalls;
}
void IceCream::setIceCreamFlavour(const IceCreamFlavour& flavour)
{
	this->flavour = flavour;
}

//"get" функции
char* IceCream::getNameI() const
{
	return this->name;
}
int IceCream::getNumberOfBalls() const
{
	return this->numberOfBalls;
}
IceCreamFlavour IceCream::getIceCreamFlavour() const
{
	return this->flavour;
}
//Конструктор по подразбиране
IceCream::IceCream() :name(nullptr)
{
	name = new char[1];
	name[0] = '\0';
	numberOfBalls = 0;
	flavour.name[0] = '\0';
	flavour.priceOfBall = 0;

}
//Конструктор за общо ползване
IceCream::IceCream(const char* name, int numberOfBalls, IceCreamFlavour flavour) :name(nullptr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->numberOfBalls = numberOfBalls;
	this->flavour = flavour;
}
//Copy конструктор
IceCream::IceCream(const IceCream &other) :name(nullptr)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->numberOfBalls = other.numberOfBalls;
	this->flavour = other.flavour;
}
//operator=
IceCream& IceCream::operator=(const IceCream& other)
{
	if (this != &other)
	{
		setNameI(other.getNameI());
		setNumberOfBalls(other.getNumberOfBalls());
		setIceCreamFlavour(other.getIceCreamFlavour());
	}
	return *this;
}
//Деструктор
IceCream::~IceCream()
{
	delete[] this->name;
}
//Цена на Ice Cream
double IceCream::getPrice() const
{
	return numberOfBalls * flavour.priceOfBall;
}
//Print функция
void IceCream::print() const
{
	cout << flavour.name << endl;
	cout << flavour.priceOfBall << endl;
	cout << name << endl;
	cout << numberOfBalls << endl;
}
IceCream bestIceCream(IceCream* arr, int size, double money)
{
	int idx = -1, coutBallsMax = -1;
	double price = -5;
	for (int i = 0; i < size; i++)
	{
		if ((arr[i].getPrice() < money && arr[i].getNumberOfBalls() > coutBallsMax) || (arr[i].getPrice() > price && arr[i].getNumberOfBalls() == coutBallsMax))
		{
			idx = i;
			coutBallsMax = arr[i].getNumberOfBalls();
			price = arr[i].getPrice();
		}
	}
	return arr[idx];
}
void printIceCreamWithFlavour(IceCream* arr, int size, IceCreamFlavour searchedFlavour)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getIceCreamFlavour().name, searchedFlavour.name) == 0)
		{
			arr[i].print();
		}
	}
}