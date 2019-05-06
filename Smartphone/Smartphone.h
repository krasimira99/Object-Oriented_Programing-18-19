#pragma once
#include<iostream>
using namespace std;
class MacAddress {
private:
	char address[17];
public:
	MacAddress();
	MacAddress(const char*);
	const char* getAddress()const;
	bool operator<(const MacAddress&) const;
	bool operator==(const MacAddress&) const;
	bool operator>(const MacAddress&) const;
};
class Smartphone {
private:
	char model[128];
	char brand[256];
	char owner[256];
	size_t year;
	size_t memory;
	MacAddress address;
public:
	Smartphone();
	Smartphone(const char*, const char*, const char*, size_t, size_t, MacAddress);
	void setModel(const char*);
	void setBrand(const char*);
	void setOwner(const char*);
	void setYear(size_t);
	void setMemory(size_t);
	void setAddress(MacAddress);

	const char* getModel()const;
	const char* getBrand()const;
	const char* getOwner()const;
	size_t getMemory()const;
	size_t getYear()const;
	const MacAddress& getAddress()const;
	
	void print() const;
};
class Router {
private:
	Smartphone* phones;
	size_t size;
	size_t capacity;
	void copy(const Router&);
	void erase();
	void resize();
	void popAt(size_t index);
public:
	Router();
	Router(const Router&);
	Router& operator=(const Router&);
	~Router();

	void addPhone(const Smartphone&);
	void removePhone(MacAddress);
	void sort();
	Router& operator+=(const Router&);
	Router& operator +=(const Smartphone&);
	Router operator+(const Smartphone&) const;
	void print()const;
};