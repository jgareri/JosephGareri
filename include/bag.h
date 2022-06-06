//Joseph Gareri
//jgareri@my.athens.edu
//Problem 2-4, HW 2

#pragma once

#include <iostream>
#include "list.h"
//using namespace std;

template <typename Thing>
class Bag {
public:
    class Bag_with_receipts
    {
    public: 
        Bag_with_receipts()
        {
            bagContents2 = new List<Thing*>;
            bagContents2[size] = { 1,2,3,4 };
        }
        ~Bag_with_receipts()
        {
            delete[] bagContents2;
            bagContents2 = nullptr;
        }
        void insert(Thing aThing) {
            bagContents2.push_back(&aThing);
        }
        Thing& pop()
        {
            Thing* ptrToAThing;
            int i = bagContents2.size();
            bool thingIsNull = true;
            while (thingIsNull && (i > 0)) {
                if (bagContents2[i] != nullptr) {
                    ptrToAThing = bagContents2[i];
                    thingIsNull = false;
                }
            }
        }

        bool Test()
        {
            bool result;
            if (bagContents2.capacity() == NULL)
            {
                std::cerr << "Error." << std::endl;
            }

            if (bagContents2.size() == NULL)
            {
                std::cerr << "Error." << std::endl;
            }
            else
            {
                result = true;
            }
            return result;
        }

        int size() {
            return bagContents2.capacity();
        }
        int count() {
            return bagContents2.size();
        }
    private:
        List<Thing*>* bagContents2;
    };
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
