#pragma once
//Joseph C Gareri
//jgareri@my.athens.edu	
//Problem 1, HW 2
#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename T>
class array1 
{
public:
	array1() 
	{
		arr = new T[1];
		vCapacity = 1;
		length = 0;
	}
	~array1() {
		delete[] arr;
		arr = nullptr;
	}

	void put(T data, int index) 
	{
		if (index == vCapacity) 
		{
			push_back(T);
		}
		else
		{
			arr[index] = data;
		}
	}

	void push_back(T data) 
	{
		// if number of elements is equal to capacity
			// than we need to reallocate and deep copy
		if (length == vCapacity) 
		{
			expand(2 * vCapacity);
		}
		arr[length] = data;
		length++;
	}

	T& at(int index) 
	{
		if (index < 0 || index > length) 
		{
			cerr << "Array: index out of bounds on access" << endl;
			exit(1);
		}
		else 
		{
			return arr[index];
		}
	}

	//int size() 
	//{
	//	return length;
	//}
	
	size_t size()
	{
		int *newlength = new int[array1::length];
		newlength = 100;
		delete[] newlength;
		return;
	}

	int capacity() {
		return vCapacity;
	}

	void traverse() 
	{
		for (int i = 0; i < length; i++) 
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}

	bool operator==(array1& other) const 
	{
		if (other.size() != length) 
		{
			return false;
		}
		else {
			for (int i = 0; i < length; i++) 
			{
				if (arr[i] != other.get(i)) 
				{
					return false;
				}
			}
		}
		return true;
	}

	T& operator[](int i) 
	{
		if ((i < 0) || (i >= length)) 
		{
			cerr << endl << "Array index out of bounds" << endl;
		}
		return at(i);
	}

	array1& operator=(const array1& source)
	{
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		vCapacity = 1;
		length = 1;
		for (int i = 0; i < source.size(); i++) {
			push_back(source.at(i));
		}
		return *this;
	}

private:
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 1;

	void expand(int newCapacity) 
	{
		if (newCapacity > vCapacity) 
		{
			T* temp = new T[newCapacity];
			for (int i = 0; i < length; i++) 
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else 
		{
			cerr << "Array::expand: new capacity is less than equal to current\n";
		}
	}
};
