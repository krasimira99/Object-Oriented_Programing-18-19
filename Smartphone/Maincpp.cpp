#include "pch.h"
#include <iostream>
#include<cstring>
using namespace std;
#include "Smartphone.h"
int main()
{
	Smartphone phone;
	phone.print();
	MacAddress mac("AA:AA:AA:AA:AA:AA");
	Smartphone krasi("Krasi", "Krasi", "Krasi", 2015, 64, mac);
	krasi.print();
}