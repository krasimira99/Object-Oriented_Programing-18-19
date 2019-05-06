#pragma once
enum spec{safe, endangered, extinct};
class Species {
private:
	char*name;
	double life;
	spec type;
public:
	Species();
	Species(const char*, double, spec);
	Species(const Species&);
	Species& operator=(const Species&);
	~Species();

	void setNameS(const char*);
};
class Animal {
private:
	char*name;
	int age;
	Species spec;
public:
	Animal();
	Animal( char*, int, Species);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	~Animal();

	void setName(char*);
	void setAge(int);
	void setSpec(Species);

	 char* getName()const;
	int getAge()const;
	Species getSpec()const;
};
class Zoo
{
private:
	Animal** animals;
	int size;
	int capasity;
	double ticket;

	void sizeUp();
	void sizeDown();
	void capUp();
	int getCap()const;
	void resize();
public:
	int getSize()const;
	void addAnimal(const Animal&);

	~Zoo();
};