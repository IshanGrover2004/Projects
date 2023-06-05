// Created by Ishan Grover on 05-June-2023
// Generic Linked List --> A Linked Lists which can store data of any data type
// Eg-: [1,2,3,4,5] or ['a','b','c','d']

#include <iostream>

// For making a Node of a linked list
template <typename T> struct Node {
  T data;
  Node *next;

  Node() = default;

  Node(T &data) { // Parameterised Constructor taking data input to node
    this->data = data;
    next = nullptr;
  }
};

// Creating Linked List structure
template <typename T> class LinkedList {
private:
  Node *head = new Node;

public:
  LinkedList() { head = nullptr; }

  // Operations or Function needed in linked list
  void push_back(T element);
  void push_front(T element);
  void insert(int position, T element);
  T pop_back(); // pop element return and shows up
  T pop_front();
  void remove(T element);
  T get(int position);
  int size();
  bool is_empty();
  void clear();
  void display_all();
};

// push_back(element) --> push the element in the last node of linked list
template <typename T> void LinkedList<T>::push_back(T element) {
  Node *current = new Node;
  current->data = element;
  current->next = nullptr;
}

// push_front(element) --> push the element in the first node of linked list
template <typename T> void LinkedList<T>::push_front(T element) {
  Node *current = new Node;

  if (head == nullptr) {
    head->data = element;
    head->next = nullptr;
  } else {
    current = head;
    head->data = element;
    head->next = nullptr;
  }
}

// display_all() --> Display all elements of linked list
template <typename T> void LinkedList<T>::display_all() {
  Node *current = new Node;
  current = head;
  int count = 1;
  while (current->next != nullptr) {
    cout << "Elements at Node " << count << "is: " << current->data << endl;
    
  }
}

int main() {}
