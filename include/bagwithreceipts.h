//Joseph Gareri
//jgareri@my.athens.edu
//Problem 4, HW 2
//Derived from Instructor Code

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
        
        int receipt = bagContents.size() - 1;
        receipts.push_back(receipt);
        return receipt;
    }
    Thing* pop(int receipt)
    {
        Thing* ptrToAThing = nullptr;
        int i = bagContents.size();
        bool thingIsNull = true;
        while (thingIsNull && (i > 0) && (receipts[i] != receipt)
        {
            if (bagContents[i] != nullptr)
            {
                ptrToAThing = bagContents[i];
                thingIsNull = false;
                receipt[i] = 0;
            }
        }
        return ptrToAThing;
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
    List<int>* receipts;

};
