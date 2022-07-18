// GARERI.Asg06.cpp 
// Joseph Gareri
// jgareri@my.athens.edu
// Assignment 06
// Problem 1-4
//Derived from Instructor Code


#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include "Tree.h"
using namespace std;


template<typename T>
struct TreeSearch 
{
    size_t SIZE;
    int* arr[];
    T* x;

}; 
vector<int> numbers;


void fillarray()
{
    
    const int SIZE = 1000;
   
    srand(-time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        numbers.push_back(rand() % SIZE);

    }
    sort(numbers.begin(), numbers.end(), greater<int>());

}


void display(vector <int> const& numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
        cout << numbers[i] << " ";
} 

int binarySearch(vector <int> const& numbers, int low, int high, int x)
{
    int i = low;
    int j = high;
    int mid = 0;

    while (i < j)
    {
        int mid = ((i + j) / 2);

        if (x > numbers[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
        if (x == numbers[i])
        {
            return i;
        }

        return -1;
    }
}


int main()
{

    fillarray();
   
    int x;
    cout << "A value will be chosen at random to search:" << endl;
    system("pause");
    x = (rand() % 100);

    int n = sizeof(numbers) / sizeof(numbers[0]);
    cout << endl;
    display(numbers);

    int index = binarySearch(numbers, 0, n , x);
    if (index == -1)
    {
        cout <<endl<<endl<<endl<< x<< " | Element is NOT present in array" << endl;
    }
    else
    {
        cout << x << " | Element is present at index " <<index<< endl;
    }
 

    return 0;
       
}


