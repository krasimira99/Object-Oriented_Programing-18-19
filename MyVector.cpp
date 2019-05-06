#pragma once
#include"pch.h"
#include<iostream>
using namespace std;

template<typename T>
class Vector
{
private:
	unsigned int my_size;
	unsigned int my_capacity;
	T* buffer;
public:
	typedef T* iterator;
	class Iterator
	{
	private:
		size_t idx;
		T* point;
	public:
		Iterator()
		{
			this->point = NULL;
			this->idx = 0;
		}
		Iterator(T* point, size_t _idx)
		{
			this->point = point;
			this->idx = idx;
		}
		Iterator(const Iterator& other)
		{
			this->point = other.point;
			this->idx = other.idx;
		}
		Iterator& operator=(const Iterator& other)
		{
			if (this != other)
			{
				delete[] this->point;
				this->idx = other.idx;
				this->point = other.point;
			}
		}
		~Iterator()
		{
			delete[] this->point;
		}
		Iterator& operator++()
		{
			++idx;
			return *this;
		}
		Iterator operator++(int)
		{
			Itertaor iter(*this);
			++idx;
			return iter;
		}
		Iterator operator--(int)
		{
			Iterator iter(*this);
			--idx;
			return iter;
		}
		Iterator& operator--()
		{
			--idx;
			return *this;
		}
		const T& operator*()const
		{
			return (*point)[idx];
		}
		T& operator*()
		{
			return (*point)[idx]; 
		}
		T* operator->()
		{
			return &((*point)[idx]);
		}
		const T* operator->()const
		{
			return &((*point)[idx]);
		}
		bool operator<(const Iterator& other)
		{
			return this->idx < other.idx;
		}
		bool operator>(const Iterator& other)
		{
			return this->idx > other.idx;
		}
		bool operator<=(const Iterator& other)
		{
			return this->idx <= other.idx;
		}
		bool operator>=(const Iterator& other)
		{
			return this->idx >= other.idx;
		}
		bool operator==(const Iterator& other)
		{
			return this->idx == other.idx;
		}
		bool operator!=(const Iterator& other)
		{
			return this->idx != other.idx;
		}
		Iterator operator+(int num)
		{
			Iterator iter(*this);
			return iter += num;
		}
		Iterator operator-(int num)
		{
			Iterator iter(*this);
			return iter -= num;
		}
		Iterator& operator+=(int num)
		{
			idx += num;
			return *this;
		}
		Iterator& opeartor-=(int num)
		{
			idx -= num;
			return *this;
		}
    };
	template <class T>
	Vector()
	{
		this->my_size = 0;
		this->my_capacity = 0;
		this->buffer = new T[this->my_capacity];
	}
	template<class T>
	Vector(unsigned int size)
	{
		my_size = size;
		my_capacity = size;
		buffer = new T[size];
	}
	template<class T>
	Vector(unsigned int size, const T & initializer)
	{
		my_capacity = size;
		my_size = size;
		buffer = new T[my_size];
		for (unsigned int i = 0; i < my_size; i++)
		{
			buffer[i] = initializer;
		}
	}
	template <class T>
	Vector(const Vector<T>& other)
	{
		my_capacity = other.capacity;
		my_size = other.size;
		buffer = new T[my_size];
		for (unsigned int i = 0; i < my_size; i++)
		{
			buffer[i] = other.buffer[i];
		}
	}
	template <class T>
	Vector<T> & operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			my_capacity = other.capacity;
			my_size = other.size;
			buffer = new T[my_size];
			for (unsigned int i = 0; i < my_size; i++)
			{
				buffer[i] = other.buffer[i];
			}
		}
		return *this;
	}
	template<class T>
	~Vector()
	{
		delete[] this->buffer;
	}
	template <class T>
	T& operator[](unsigned int idx)
	{
		return this->buffer[idx];
	}
	template <class T>
	T& at(size_t idx)
	{
		if (!(idx < this->my_size))
		{
			return this->buffer[this->my_size-1];
		}
		else
		{
			this->return buffer[idx];
		}
	}
	template <class T>
	T & front() const
	{
		return buffer[0];
	}
	template <class T>
	T & back() const
	{
		return this->buffer[size() - 1];
	}
	template<class T>
	typename iterator begin()
	{
		return buffer;
	}
	template<class T>
	typename iterator end()
	{
		return buffer + size();
	}
	template <class T>
	bool empty()
	{
		return this->my_size == 0;
	}
	template <class T>
	unsigned int size() const
	{
		return this->my_size;
	}
	template <class T>
	void reserve(unsigned int capacity)
	{
		if (capacity < my_capacity)
		{
			return;
		}
		T* tempBuffer = new T[capacity];
		for (unsigned int i = 0; i < my_size; i++)
		{
			tempBuffer[i] = buffer[i];
		}
		my_capacity = capacity;
		delete[] buffer;
		buffer = new T[my_size];
		for (unsigned int i = 0; i < my_size; i++)
		{
			buffer[i] = tempBuffer[i];
		}
	}
	template <class T>
	unsigned int capacity() const
	{
		return this->my_capacity;
	}
	template <class T>
	void Vector<T>::shink_to_fit()
	{
		if (this->my_capacity>this->my_size)
		{
			this->my_capacity = this->my_size;
			T* tempBuffer = new T[my_capacity];
			for (size_t i = 0; i < my_size; i++)
			{
				tempBuffer[i] = this->buffer[i];
			}
			delete[] this->buffer;
			this->buffer = tempBuffer;
		}
	}
	template <class T>
	typename insert(size_t pos, const T& elem)
	{
		if (this->my_size==this->my_capacity)
		{
			this->my_capacity = this->my_capacity * 2 + 1;
			T* tempBuffer = new T[this->my_capacity];
			for (size_t i = 0; i < this->my_size; i++)
			{
				tempBuffer[i] = this->buffer[i];
			}
			delete[] this->buffer;
			this->buffer = tempBuffer;
		}
		T* tempBuffer = new T[this->my_capacity];
		for (size_t i = 0; i < pos; i++)
		{
			tempBuffer[i] = this->buffer[i];
		}
		tempBuffer[pos] = elem;
		for (size_t i = pos+1; i < my_size+1; i++)
		{
			tempBuffer[i] = this->buffer[i - 1];
		}
		this->my_size++;
		delete[] this->buffer;
		this->buffer = tempBuffer;
		return Vector<T>::Iterator
		{
			this,pos
		};
	}
	template <class T>
	typename Iterator erase(size_t pos)
	{
		for (size_t i = pos; i < this->my_size-1; i++)
		{
			this->buffer[i] = this->buffer[i + 1];
		}
		this->my_size--;
		return Vector<T>::iterator{ this,pos };
	}
	template <class T>
	void push_back(const T & element)
	{
		if (my_size >= my_capacity)
		{
			reserve(my_capacity + 5);
		}
		buffer[my_size++] = element;
	}
	template <class T>
	void pop_back()
	{
		my_size--;
	}
	template <class T>
	void swap(Vector & v)
	{
		for (size_t i = 0; i < size(); i++)
		{
			if (size() < v.size())
			{
				cout << "Error" << endl;
			}
			else
			{
				T* tempBuffer = new T[my_capacity];
				for (size_t i = 0; i < my_size; i++)
				{
					tempBuffer[i] = buffer[i];
					buffer[i] = v[i];
					v[i] = tempBuffer[i];
				}
			}
		}
	}
	template<class T>
	bool operator>(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] > other.buffer[i])
			{
				return true;
			}
		}
	}

	template<class T>
	bool operator<(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] < other.buffer[i])
			{
				return true;
			}
		}
	}

	template<class T>
	bool operator<=(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] <= other.buffer[i])
			{
				return true;
			}
		}
	}

	template<class T>
	bool operator>=(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] >= other.buffer[i])
			{
				return true;
			}
		}
	}

	template<class T>
	bool operator==(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] == other.buffer[i])
			{
				return true;
			}
		}
	}

	template<class T>
	bool operator!=(const T & other)
	{
		for (size_t i = 0; i < my_size; i++)
		{
			if (buffer[i] != other.buffer[i])
			{
				return true;
			}
		}
	}
};
int main()
{
	cout << "Hello" << endl;
	return 0;
}


