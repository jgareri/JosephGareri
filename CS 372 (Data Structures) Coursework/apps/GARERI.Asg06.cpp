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
#include <chrono>
#include <iomanip>
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
    const int SIZE2 = 2500;
    const int SIZE3 = 5000;
    const int SIZE4 = 10000;
    const int SIZE5 = 50000;
   
    srand(-time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        numbers.push_back(rand() % SIZE);

    }
    for (int i = 0; i < SIZE2; i++)
    {
        numbers.push_back(rand() % SIZE2);

    }
    for (int i = 0; i < SIZE3; i++)
    {
        numbers.push_back(rand() % SIZE3);

    }
    for (int i = 0; i < SIZE4; i++)
    {
        numbers.push_back(rand() % SIZE4);

    }
    for (int i = 0; i < SIZE5; i++)
    {
        numbers.push_back(rand() % SIZE5);

    }
    sort(numbers.begin(), numbers.end(), greater<int>());

   
}


void display(vector <int> const& numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
        cout << numbers[i] << " ";
} 

bool binarySearch(vector <int> const& numbers, int low, int high, int randomNumber)
{
    int i = low;
    int j = high;
    int mid = 0;

    while (i < j)
    {
        int mid = ((i + j) / 2);

        if (randomNumber > numbers[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
        if (randomNumber == numbers[i])
        {
            return i;
        }

        return -1;
    }
}


int main()
{
    int i = 0;
    const int SIZE6 = 100;

    auto start2 = std::chrono::steady_clock::now();
    fillarray();
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2 - start2;
   
    int randomNumber;

    cout << "A value will be chosen at random to search:" << endl;
    system("pause");

    srand(time(0));
    for (int i = 0; i < SIZE6; i++) 
    {
        randomNumber = (rand() % 100);
    }

    int n = sizeof(numbers) / sizeof(numbers[0]);
    cout << endl;
    display(numbers);

    auto start = std::chrono::steady_clock::now();
    int index = binarySearch(numbers, 0, n , randomNumber);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
  

    cout << endl << endl;
    if (index == -1)
    {
        cout << "Random numbers selected are NOT present in array" << endl;
    }
    else
    {
        cout << "Random numbers selected are present in the array " << endl;
    }
    cout << setprecision(8) << fixed << showpoint;
    cout << endl << "Arrays filled with random numbers completed at elapsed time: " << elapsed_seconds2.count() << "s\n";
    cout << "Binary search completed with elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
       
}


