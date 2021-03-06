#include "pch.h"
#include <iostream>
#include<cstring>
#include "Smartphone.h"


MacAddress::MacAddress()
{
	strcpy_s(this->address, 17, "FF:FF:FF:FF:FF:FF");
}

MacAddress::MacAddress(const char *address)
{
	if (strlen(address)!=17)
	{
		cout << "Invalid Mac Address, set default." << endl;
		strcpy_s(this->address, 17, "FF:FF:FF:FF:FF:FF");
	}
	else
	{
		strcpy_s(this->address, 17, address);
	}
}

const char * MacAddress::getAddress() const
{
	return this->address;
}

bool MacAddress::operator<(const MacAddress &other) const
{
	return strcmp(this->address, other.address) < 0;
}

bool MacAddress::operator==(const MacAddress &other) const
{
	return strcmp(this->address, other.address) == 0;
}

bool MacAddress::operator>(const MacAddress &other) const
{
	return strcmp(this->address, other.address) > 0;
}

Smartphone::Smartphone()
{
	strcpy_s(this->model, 128, "Default model");
	strcpy_s(this->brand, 256, "Default brand");
	strcpy_s(this->owner, 256, "Default owner");
	this->year = 2019;
	this->memory = 32;
	this->address = MacAddress();
}

Smartphone::Smartphone(const char *model, const char *brand, const char *owner, size_t year, size_t memory, MacAddress address)
{
	strcpy_s(this->model, 128, model);
	strcpy_s(this->brand, 256, brand);
	strcpy_s(this->owner, 256, owner);
	this->year = year;
	this->memory = memory;
	this->address = address;
}

void Smartphone::setModel(const char * model)
{
	strcpy_s(this->model, 128, model);
}

void Smartphone::setBrand(const char *brand)
{
	strcpy_s(this->brand, 256, brand);
}

void Smartphone::setOwner(const char *owner)
{
	strcpy_s(this->owner, 256, owner);
}

void Smartphone::setYear(size_t year)
{
	this->year = year;
}

void Smartphone::setMemory(size_t memory)
{
	this->memory = memory;
}

void Smartphone::setAddress(MacAddress address)
{
	this->address = address;
}

const char * Smartphone::getModel() const
{
	return this->model;
}

const char * Smartphone::getBrand() const
{
	return this->brand;
}

const char * Smartphone::getOwner() const
{
	return this->owner;
}

size_t Smartphone::getMemory() const
{
	return this->memory;
}

size_t Smartphone::getYear() const
{
	return this->year;
}

const MacAddress & Smartphone::getAddress() const
{
	return this->address;
}

void Smartphone::print() const
{
	cout << "Model: " << this->model << endl;
	cout << "Brand: " << this->brand << endl;
	cout << "Owner: " << this->owner << endl;
	cout << "Year: " << this->year << endl;
	cout << "Memory: " << this->memory << endl;
	cout << "Mac Address: " << this->address.getAddress() << endl;
}

void Router::copy(const Router & other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->phones = new Smartphone[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		this->phones[i] = other.phones[i];
	}
}

void Router::erase()
{
	delete[] this->phones;
}

void Router::resize()
{
	this->capacity *= 2;
	Smartphone* newPhones = new Smartphone[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		newPhones[i] = phones[i];
	}
	this->erase();
	phones = newPhones;
}

void Router::popAt(size_t index)
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->phones[i] = this->phones[i + 1];
	}
	this->size--;
}

Router::Router()
{
	this->capacity = 8;
	this->size = 0;
	this->phones = new Smartphone[this->capacity];
}

Router::Router(const Router &other)
{
	this->copy(other);
}

Router & Router::operator=(const Router &other)
{
	if (this!=&other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Router::~Router()
{
	this->erase();
}

void Router::addPhone(const Smartphone &phone)
{
	if (this->size>=this->capacity)
	{
		this->resize();
	}
	this->phones[this->size++] = phone;
}

void Router::removePhone(MacAddress address)
{
	int index = -1;
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->phones[i].getAddress()==address)
		{
			index = i;
			break;
		}
	}
	if (index!=-1)
	{
		this->popAt(index);
	}
}

void Router::sort()
{
	for (size_t i = 0; i < this->size-1; i++)
	{
		for (size_t j = 0; j < this->size-1; j++)
		{
			if (this->phones[j].getAddress()>this->phones[j+1].getAddress())
			{
				swap(this->phones[j], this->phones[j + 1]);
			}
		}
	}
}

Router & Router::operator+=(const Router &other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		this->addPhone(other.phones[i]);
	}
	return *this;
}

Router & Router::operator+=(const Smartphone &other)
{
	this->addPhone(other);
	return *this;
}


Router Router::operator+(const Smartphone & other) const
{
	Router returned = *this;
	returned += other;
	return returned;
}

void Router::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->phones[i].print();
	}
}
