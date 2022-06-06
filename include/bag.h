//Joseph Gareri
//jgareri@my.athens.edu
//Problem 2-3, HW 2

#pragma once

#include <iostream>
#include "list.h"
//using namespace std;

template <typename Thing>
class Bag {
public:
   
    Bag() {
        bagContents = new List<Thing*>;
        bagContents[0] = nullptr;
    }
    ~Bag() {
        delete[] bagContents;
        bagContents = nullptr;
    }
    
    void insert(Thing aThing) {
        bagContents.push_back(&aThing);
    }
    Thing& pop() 
    {
        Thing* ptrToAThing;
        int i = bagContents.size();
        bool thingIsNull = true;
        while (thingIsNull && (i > 0)) {
            if (bagContents[i] != nullptr) {
                ptrToAThing = bagContents[i];
                thingIsNull = false;
            }
        }
    }
   
    int size() {
        return bagContents.capacity();
    }
    int count() {
        return bagContents.size();
    }
    bool TEST()
    {
        bool result;
        if (bagContents.capacity() == NULL)
        {
            std::cerr << "Error." << std::endl;
        }

        if (bagContents.size() == NULL)
        {
            std::cerr << "Error." << std::endl;
        }
        else
        {
            result = true;
        }
        return result;
    }

    
    
private:
    List<Thing*>* bagContents;
   
};
