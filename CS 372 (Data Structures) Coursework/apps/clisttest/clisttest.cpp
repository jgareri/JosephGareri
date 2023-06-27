//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "CircularList.h"

template <typename T>
void printItem(T &item) {
  std::cout << item << " ";
}

int main() {
  CircularList<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 10; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  std::cout << "Popping the list" << std::endl;
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  // Note this doesn't completely clear the list.
  for (int i = 0; i < 10; i++) {
    std::cout << aListOfIntegers.back() << " ";
    aListOfIntegers.pop_back();
  }
  std::cout << std::endl << "Traversing the list" <<  std::endl;
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  std::cout << "Adding one more item to the list" << std::endl;
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  return 0;
}
