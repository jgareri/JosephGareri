//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "list.h"

template <typename T>
void printItem(T &item) {
  std::cout << item << " ";
}

void List<int>::TestLinkedList()
{
    return;
}

void CircularList<int>::TestCircularList()
{
    return;
}

int main() {
  List<int> aListOfIntegers;
  List<int> test;
  CircularList<int> test2;
  CircularList<int> circularlistintegers;

  test.TestLinkedList();
  test2.TestCircularList();

  if (aListOfIntegers.empty()) {
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 10; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << aListOfIntegers.back() << " ";
    aListOfIntegers.pop_back();
  }
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  if (circularlistintegers.empty()) {
      std::cout << "Yep, the new list is empty. " << std::endl;
  }
  for (int i = 10; i >= 0; i--) {
      circularlistintegers.push_front(i);
  }
  circularlistintegers.traverse(printItem);
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
      std::cout << circularlistintegers.back() << " ";
      circularlistintegers.pop_back();
  }
  if (!circularlistintegers.empty()) {
      circularlistintegers.traverse(printItem);
      std::cout << std::endl;
  }
  circularlistintegers.push_back(42);
  circularlistintegers.traverse(printItem);
  std::cout << std::endl;
  return 0;
}
