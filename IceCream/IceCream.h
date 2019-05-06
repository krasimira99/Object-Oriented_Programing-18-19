#pragma once
#include<cstring>
struct IceCreamFlavour {
	char name[32];
	double priceOfBall;
	IceCreamFlavour(char name[32], int price);
	IceCreamFlavour();
};
class IceCream {
private:
	char* name;
	int numberOfBalls;
	IceCreamFlavour flavour;

public:

	IceCream();
	IceCream(const char* name, int numberOfBalls, IceCreamFlavour flavour);
	IceCream(const IceCream& other);
	IceCream& operator=(const IceCream& other);
	~IceCream();

	void setNameI(const char* name);
	void setNumberOfBalls(int numberOfBalls);
	void setIceCreamFlavour(const IceCreamFlavour& flavour);

	char* getNameI() const;
	int getNumberOfBalls() const;
	IceCreamFlavour getIceCreamFlavour() const;


	double getPrice() const;
	void print() const;

};
IceCream bestIceCream(IceCream* arr, int size, double money);
void printIceCreamWithFlavour(IceCream* arr, int size, IceCreamFlavour searchedFlavour);