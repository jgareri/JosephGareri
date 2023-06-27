//
// File:   assignment1.cpp
// Author: Joseph Gareri
// Purpose: To get good grades
// Illustrate some of the bad things that can happen with
// pointers
// Problem: 1

#include <iostream>
 using namespace std;

void allocate();
string* set();
void display(string&);

string* set()
{
	
	string* letters1 = NULL; 
	
	letters1 = new string;
	
	string* letters2 = letters1;

	delete letters1;

	return letters2;
}

void display(string& letters2)
{
	cout << letters2;
}

void allocate()
{
	int *number3 = new int[100];
	int* number4 = number3;
	
	for (int i = 0; i < 10; i++)
	{
		number3[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << number4[i]<<" ";
	}
}


int main() 
{
	string letters2 = "abcdefghikl";
	display(letters2);
	set();
	allocate();
	int *number1 = new int[100];
	int* number2 = number1;
	for (int i = 0; i < 10; i++)
	{
		number1[i] = i + 1;
	}
	
	for (int i = 0; i < 10; i++)
	{
		cout << number2[i]<<" ";
	}
	delete[] number1;
	return 0;
}
