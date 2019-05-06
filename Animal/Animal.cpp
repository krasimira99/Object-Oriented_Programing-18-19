#include"pch.h"
#include<iostream>
#include<cstring>
#include"Animal.h"
using namespace std;

Species::Species()
{
	name = nullptr;
	life = 25;
	type = safe;
}
Species::Species(const char*name, double life, spec type) :name(nullptr)
{
	setNameS(name);
	this->life = life;
	this->type = type;

}
Species::Species(const Species& other) :Species(other.name, other.life, other.type)
{}
Species& Species:: operator=(const Species& other)
{
	if (this!=&other)
	{
		this->setNameS(other.name);
		this->life = other.life;
		this->type = other.type;
	}
	return *this;
}
Species::~Species() 
{
	delete[] this->name;
}

void Species:: setNameS(const char*name)
{
	if (name != nullptr) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}
/////////////////////////////////////////////////////////////////////
Animal::Animal()
{

}
Animal::Animal( char*name, int age, Species spec) : name(nullptr)
{
	setName(name);
	setAge(age);
	setSpec(spec);
}
Animal::Animal(const Animal&other):Animal(other.name,other.age,other.spec)
{

}
Animal& Animal:: operator=(const Animal&other)
{
	if (this!=&other)
	{
		this->setName(other.name);
		this->setAge(other.age);
		this->setSpec(other.spec);
	}
	return *this;
}
Animal::~Animal()
{
	delete[] this->name;
}

void Animal:: setName(char*name)
{
	if (name!=nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}
void Animal::setAge(int age)
{
	this->age = age;
}
void Animal::setSpec(Species spec)
{
	this->spec = spec;
}

 char*Animal::getName()const
{
	return this->name;
}
int Animal::getAge()const
{
	return this->age;
}
Species Animal::getSpec()const
{
	return this->spec;
}
/////////////////////////////////////////////
void Zoo::sizeUp()
{
	this->size++;
}

void Zoo::sizeDown()
{
	if (getSize()>0)
	{
		this->size--;
	}
}

void Zoo::capUp()
{
	if (getCap() == 0)
	{
		this->capasity = 2;
	}
	else
	{
		this->capasity *= 2;
	}
}

int Zoo::getCap() const
{
	return this->capasity;
}

void Zoo::resize()
{
	capUp();
	Animal** newAnimal = new Animal*[getCap()];

	for (int i = 0; i < getSize(); i++)
	{
		newAnimal[i] = animals[i];
	}

	delete[] animals;
	animals=newAnimal;
}

int Zoo::getSize() const
{
	return this->size;
}

void Zoo::addAnimal(const Animal &a)
{
	if (getSize() == getCap())resize();

	sizeUp();

	animals[getSize() - 1] =
		new Animal(a.getName(), a.getAge(), a.getSpec());
}

Zoo::~Zoo()
{
	delete[] this->animals;
}
