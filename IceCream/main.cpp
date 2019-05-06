#include "pch.h"
#include "IceCream.h"
#include<iostream>
	using namespace std;
	const int MAX = 100;
	int main()
	{
		char* buffer = new char[100];
		int balls = 0;
		char* buffertwo = new char[100];
		double price = 100;

		IceCream iceCreams[MAX];
		int size;
		cout << "Insert number of Ice Creams: ";
		cin >> size;
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Name of the ice cream: ";
			cin >> buffer;
			iceCreams[i].setNameI(buffer);
			cout << "Number of balls: ";
			cin >> balls;
			iceCreams[i].setNumberOfBalls(balls);
			cout << "Name of the flavour: ";
			cin >> buffertwo;
			cout << "Enter the price per ball: ";
			cin >> price;
			iceCreams[i].setIceCreamFlavour(IceCreamFlavour(buffertwo, price));
		}
		double money;
		cout << "Enter the money of a child: ";
		cin >> money;
		bestIceCream(iceCreams, size, money);
		printIceCreamWithFlavour(iceCreams, size, IceCreamFlavour(buffertwo, price));

		return 0;
}

