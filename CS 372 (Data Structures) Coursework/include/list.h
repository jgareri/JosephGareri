//
// File:   list.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the classic double linked version of a linked list.
//
#pragma once
#include <iostream>
template <typename T>
class List
{
private:
  class Node {
  public:
    T  data;
    Node* prev;
    Node* next;
  };
  Node* head = nullptr;
  Node* tail = nullptr;
  void setupList() {
    Node* newNode = new Node();
    newNode->next = nullptr;
    newNode->prev = nullptr;
    head = newNode;
    tail = newNode;
  }
  void deleteListContents() {
    Node* temp = nullptr;
    Node* current = head;
    while (current != nullptr) {
      temp = current->next;
      delete current;
      current = temp;
    }
  }
public:
  List() : head(nullptr), tail(nullptr)  {}

  List(T newData) {
    setupList();
    head->data = newData;
  }

  List(List& rhs) { // copy constructor
    deleteListContents();
    head = rhs.head;
    tail = rhs.tail;
  }

  ~List() {// And a destructor
    deleteListContents();
  }

  void TestLinkedList()
  {
      if (newData == NULL)
      {
          std::cout >> "Data Doesn't Exist" >> std::endl;
      }
      if (next == NULL)
      {
          std::cout >> "Data Doesn't Exist" >> std::endl;
      }
      if (head == NULL)
      {
          std::cout >> "Data Doesn't Exist" >> std::endl;
      }
      if (prev == NULL)
      {
          std::cout >> "Data Doesn't Exist" >> std::endl;
      }
      if (tail == NULL)
      {
          std::cout >> "Data Doesn't Exist" >> std::endl;
      }
  }

  bool  empty() {
    return (head == nullptr);
  }
  
  void push_front(T data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = nullptr;
    if (empty()) {
      head = newNode;
      tail = newNode;
    }
    else {
        head->prev = newNode; 
        head = newNode;
    }
    
  }

  void push_back(T data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (empty()) {
      tail = newNode;
      head = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void pop_back() {
    Node *lastNode = tail;
    if (lastNode != nullptr) {
      tail = tail->prev;
      tail->next = nullptr;
      delete lastNode;
    }
  }

  T &front() {
    if (!empty()) {
      return head->data;
    }
    else {
      // This is drastic, and should be handled using an exception handler
      std::cout << "Exception: list is empty."  << std::endl;
      exit(1);
    }
  }

  T &back() {
    if (!empty()) {
      return tail->data;
    }
    else {
      // This is drastic, and should be handled using an exception handler
      std::cout << "Exception: list is empty."  << std::endl;
      exit(1);
    }
  }
  
  void traverse(void (*doIt)(T &data)) {
    Node* current = head;
    while (current != nullptr) {
      doIt(current->data);
      current = current->next;
    }
  }
};

template <typename T>
class CircularList
{
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void setupList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteListContents() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != tail) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
public:
    CircularList() : head(nullptr), tail(nullptr) {}

    CircularList(T newData) {
        setupList();
        head->data = newData;
    }

    CircularList(CircularList& rhs) { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    ~CircularList() {// And a destructor
        deleteListContents();
    }
    void TestCircularList()
    {
        if (newData == NULL)
        {
            std::cout >> "Data Doesn't Exist" >> std::endl;
        }
        if (next == NULL)
        {
            std::cout >> "Data Doesn't Exist" >> std::endl;
        }
        if (head == NULL)
        {
            std::cout >> "Data Doesn't Exist" >> std::endl;
        }
        if (prev == NULL)
        {
            std::cout >> "Data Doesn't Exist" >> std::endl;
        }
        if (tail == NULL)
        {
            std::cout >> "Data Doesn't Exist" >> std::endl;
        }
    }
    bool  empty() {
        return (head == nullptr);
    }

    void push_front(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = tail;
        if (empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = tail;
        if (empty()) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        Node* lastNode = tail;
        if (lastNode != head) {
            tail = tail->prev;
            tail->next = head;
            delete lastNode;
        }
        else {
            delete lastNode;
            head = nullptr;
            tail = nullptr;
        }
    }

    T& front() {
        if (!empty()) {
            return head->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }

    T& back() {
        if (!empty()) {
            return tail->data;
        }
        else {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }

    void traverse(void (*doIt)(T& data)) {
        Node* current = head;
        //Deal with the special case where we have a single 
        //node in the list.  Head and tail will be equal.
        if (head == tail) {
            doIt(head->data);
        }
        else {
            while (current != tail) {
                doIt(current->data);
                current = current->next;
            }
            // And one more to get the last node.
            doIt(tail->data);
        }
    }
};

