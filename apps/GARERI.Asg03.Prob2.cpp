// GARERI.Asg03.cpp 
// Joseph Gareri
// jgareri@my.athens.edu
// Assignment 03
// Problem 1

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "virtualclass.h"
using namespace std;

struct Tasks
{
    int taskNumber;
    char input;
    string task;
   
};vector<Tasks> totalTasks;

int ReadData();
void TaskDisplay(string, int, char);

vector<Tasks>::iterator ptr = totalTasks.begin();

int ReadData()
{
    int i;
    int number;
    string task;
    char input;
  
    Tasks aTask;
    ifstream infile;

    infile.open("tasks.txt");
    if (infile.is_open())
    {
        infile >> aTask.taskNumber >> aTask.input >> aTask.task;
       
        while (!infile.eof())
        {
            infile >> aTask.taskNumber >> aTask.input >> aTask.task;
            totalTasks.push_back(aTask);
        }
    }
    else
    {
        cout << "Error: Unable to open datafile" << endl;
        exit(1);
    }
    number = aTask.taskNumber;
    input = aTask.input;
    task = aTask.task;

       return input, task, number;
       
        infile.close();
}    

void TaskDisplay(string task, int number, char input)
{
    int i;
    
    cout << " Current Task List Display:" << endl; //This works, but I know the formatting looks bad.
    for (int i = 0; i < totalTasks.size(); i++)
    {

        cout << totalTasks[i].taskNumber << endl;

        cout << totalTasks[i].input << endl;

        cout << totalTasks[i].task << endl;
        
    }
    cout << "----------------------------------" << endl;
    
    return;
}


int main()
{
    ReadData();
    Tasks a;
    string task;
    int number = 0, input = 0;
    int option=0;
    char choice = 0;
    char answer = ' ';
    int item = 0;
    bool exitNow = false;
    do 
    {
        cout << "Hello. Select an option:\n"
            << "1. Display All Items\n"
            << "2. Select An Item\n"
            << "3. Exit" << endl << endl;

        cin >> option;
        if (option == 1)
        {   
                TaskDisplay(task, number, input);
                do
                {
                    cout << "Return (r) or Exit (e)" << endl;
                    cin >> choice;
                } while (!(choice == 'r' || choice == 'e') && cout << "Invalid input!" << endl);
                if (choice == 'e')
                {
                    exit(1);
                }
        }
        if (option == 2)
        {
            cout << "Select an Item:" << endl;
            cin >> totalTasks[item].taskNumber;
            cout << "Would you like it to mark complete?" << endl;
            cin >> answer;
            if (answer == 'y')
            {
                totalTasks[item].input = 'D';
                next(totalTasks.begin(), 4); //I'm not sure if this does anything.
            }

        }

    } while (option != 3);

    return 0;
}
