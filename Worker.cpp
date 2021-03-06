#include "pch.h"
#include <iostream>
#include<cstring>
using namespace std;
class Worker
{
protected:
	char* name;
	double paymentPerHour;
public:
	Worker()
	{
		setName("Default");
		setPaymentPerHour(0);
	}
	Worker(const char* name, double paymentPerHour)
	{
		setName(name);
		setPaymentPerHour(paymentPerHour);
	}
	Worker(const Worker& other)
	{
		setName(other.name);
		setPaymentPerHour(other.paymentPerHour);
	}
	Worker& operator=(const Worker& other)
	{
		if (this!=&other)
		{
			setName(other.name);
			setPaymentPerHour(other.paymentPerHour);
		}
		return *this;
	}
	~Worker()
	{
		delete[] this->name;
	}
	void setName(const char* name)
	{
		if (name != nullptr)
		{
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	void setPaymentPerHour(const double paymentPerHour)
	{
		this->paymentPerHour = paymentPerHour;
	}
};
class HourlyWorker : public Worker
{
private:
	char* position;
	int workHoursPerWeek;
public:
	HourlyWorker()
	{
		setPosition("Default");
		setWorkHours(0);
	}
	HourlyWorker(const char* name, double paymentPerHour, const char* position, int workHoursPerWeek) : Worker(name, paymentPerHour)
	{
		setPosition(position);
		setWorkHours(workHoursPerWeek);
	}
	HourlyWorker(const HourlyWorker& other)
	{
		setName(other.name);
		setPaymentPerHour(other.paymentPerHour);
		setPosition(other.position);
		setWorkHours(other.workHoursPerWeek);
	}
	HourlyWorker& operator=(const HourlyWorker& other)
	{
		if (this!=&other)
		{
			setName(other.name);
			setPaymentPerHour(other.paymentPerHour);
			setPosition(other.position);
			setWorkHours(other.workHoursPerWeek);
		}
		return *this;
	}
	~HourlyWorker()
	{
		delete[] this->position;
	}
	void setPosition(const char* position)
	{
		if (position != nullptr)
		{
			delete[] this->position;
			this->position = new char[strlen(position) + 1];
			strcpy_s(this->position, strlen(position) + 1, position);
		}
	}
	void setWorkHours(int workHoursPerWeek)
	{
		this->workHoursPerWeek = workHoursPerWeek;
	}
	friend ostream& operator<<(ostream& os, const HourlyWorker& obj)
	{
		os << "Name: " << obj.name << endl;
		os << "Payment per hour: " << obj.paymentPerHour << endl;
		os << "Position: " << obj.position << endl;
		os << "Work hours per week: " << obj.workHoursPerWeek << endl;
		return os;
	}
	void paymentPerWeek()
	{
		double paymentPerWeek40 = workHoursPerWeek * paymentPerHour;
		double paymentPerWeek60 = 40*paymentPerHour + ((workHoursPerWeek - 40) * paymentPerHour * 1.5);
		double paymentPerWeek = 40*paymentPerHour + 20*paymentPerHour*1.5 + ((workHoursPerWeek - 60) * paymentPerHour * 2);
		if (workHoursPerWeek<=40)
		{
			cout <<"Payment: "<< paymentPerWeek40;
		}
		if (workHoursPerWeek > 40 && workHoursPerWeek <= 60)
		{
			cout << "Payment: " << paymentPerWeek60;
		}
		if (workHoursPerWeek > 60)
		{
			cout << "Payment: " << paymentPerWeek;
		}
		
	}

};
class SalariedWorker: public Worker
{
private:
	char* position;
	int workHoursPerWeek;
public:
	SalariedWorker()
	{
		setPosition("Default");
		setWorkHours(0);
	}
	SalariedWorker(const char* name, double paymentPerHour, const char* position, int workHoursPerWeek) :Worker(name, paymentPerHour)
	{
		setPosition(position);
		setWorkHours(workHoursPerWeek);
	}
	SalariedWorker(const SalariedWorker& other)
	{
		setPosition(other.position);
		setWorkHours(other.workHoursPerWeek);
	}
	SalariedWorker& operator=(const SalariedWorker& other)
	{
		if (this!=&other)
		{
			setPosition(other.position);
			setWorkHours(other.workHoursPerWeek);
		}
		return *this;
	}
	~SalariedWorker()
	{
		delete[] this->position;
	}
	void setPosition(const char* position)
	{
		if (position != nullptr)
		{
			delete[] this->position;
			this->position = new char[strlen(position) + 1];
			strcpy_s(this->position, strlen(position) + 1, position);
		}
	}
	void setWorkHours(int workHoursPerWeek)
	{
		this->workHoursPerWeek = workHoursPerWeek;
	}
	void paymentPerWeek()
	{
		double payment = paymentPerHour * workHoursPerWeek;
		if (workHoursPerWeek<=40)
		{
			cout <<"Payment: "<< payment;
		}
		else cout << "Payment: " << 40 * paymentPerHour;
	}
	friend ostream& operator<<(ostream& os, const SalariedWorker& obj)
	{
		os << "Name: " << obj.name << endl;
		os << "Payment per hour: " << obj.paymentPerHour << endl;
		os << "Position: " << obj.position << endl;
		os << "Work hours per week: " << obj.workHoursPerWeek << endl;
		return os;
	}
};

int main()
{
	SalariedWorker s1("Pesho", 3, "cleaner", 45);
	HourlyWorker h1("Misho", 3, "cleaner", 45);
	cout << s1;
	s1.paymentPerWeek();
	cout << endl;
	cout << h1;
	h1.paymentPerWeek();

}


